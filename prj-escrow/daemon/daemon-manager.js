function DaemonManager() {
    const DAEMON = "DAEMON";
    const [NODE_PATH, SCRIPT_PATH] = process.argv;
    const { join, parse } = require("path");

    const name = parse(SCRIPT_PATH).name;
    const color = {
        green: "\x1b[32m" + "%s\x1b[0m",
        red: "\x1b[31m" + "%s\x1b[0m"
    };

    function start() {
        const pid = find_pid();
        if (pid) {
            console.log(color.red, `'${name}' daemon EXISTS.`);
            return;
        }
        const { spawn } = require("child_process");
        const { openSync, existsSync, mkdirSync } = require("fs");

        const log_dir = join(__dirname, "..", "logs");
        const [NODE_PATH, SCRIPT_PATH] = process.argv;

        !existsSync(log_dir) && mkdirSync(log_dir);

        const out = openSync(join(log_dir, `${name}.log`), "a");

        console.log(`Starting '${name}' daemon ...`);
        const child = spawn(NODE_PATH, [SCRIPT_PATH, DAEMON], {
            detached: true,
            stdio: ["ignore", out, out]
        });
        child.unref();
        console.log(color.green, `Started '${name}' daemon`);
    }

    function prepare_daemon() {
        ["log", "error", "warn"].forEach(fn_ => {
            const fn = console[fn_];

            console[fn_] = function(...args) {
                const date = new Date();
                const date_string = `[${date
                    .toDateString()
                    .slice(4)} ${date.toTimeString().slice(0, 8)}] `;
                fn.apply(console, [date_string, ...args]);
            };
        });

        console.log("STATUS", "Started.");
        process.on("SIGTERM", function() {
            console.log("STATUS", "Stopped.");
            process.exit(0);
        });
    }

    function find_pid() {
        const { execSync } = require("child_process");
        const rows = execSync("ps -x")
            .toString()
            .split(/\r?\n/)
            .filter(row => row.indexOf(SCRIPT_PATH) != -1)
            .map(row => row.trim().split(/\s+/)[0] | 0);
        return rows[0];
    }

    function status() {
        const pid = find_pid();
        pid &&
            console.log(
                color.green,
                `'${name}' daemon is RUNNING (pid: ${pid}).`
            );
        pid || console.log(`'${name}' daemon is NOT RUNNING`);
        process.exit(0);
    }
    function stop() {
        const { execSync } = require("child_process");
        const pid = find_pid();
        if (!pid) {
            console.log(color.red, `'${name}' daemon is NOT RUNNING`);
            return;
        }
        console.log(`Stopping '${name}' daemon (pid: ${pid}) ...`);

        process.kill(pid, "SIGTERM");
        for (var i = 0; i < 5 && find_pid() == pid; ++i) {
            execSync("sleep 1");
        }

        console.log(
            find_pid() != pid ? color.green : color.red,
            find_pid() != pid ? `${pid} Stopped.` : "Failed"
        );
    }

    function restart() {
        stop();
        start();
    }

    function manage() {
        const arg = process.argv[2];
        try {
            const method = {
                DAEMON: prepare_daemon,
                start,
                stop,
                status,
                restart
            }[arg];

            if (method) {
                method();
            } else {
                console.log(
                    "\x1b[31m%s\x1b[0m",
                    `USAGE ${name}.js start|stop|status|restart`
                );
            }
        } catch (e) {
            console.error(e);
            process.exit(1);
        }

        arg != DAEMON && process.exit(0);
    }

    return { manage };
}

module.exports = DaemonManager();
