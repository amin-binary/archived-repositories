const puppeteer = require("puppeteer");
const fs = require("fs");
const { join } = require("path");
const read = require("readline-sync");
const execSync = require("child_process").execSync;

let problem_id = process.argv[2] || read.question("problem id : ");
const submit = problem_id.startsWith("s");
problem_id = problem_id.replace("s", "");

let username, password;
const cred_file = join(__dirname, "cred");
if (!fs.existsSync(cred_file)) {
    username = read.question("username : ");
    password = read.question("password : ", { hideEchoBack: true });
} else {
    const cred_json = fs.readFileSync(cred_file, "utf8");
    const cred = JSON.parse(cred_json);
    username = cred.username;
    password = cred.password;
}

async function write_template(page) {
    const read_table = async selector => {
        const rows = await page.$$eval(selector, ps =>
            [].map.call(ps, e => e.textContent)
        );
        return rows.map(t => t.replace(/\s+/g, " ")).join("\n") + "\n";
    };

    const input = await read_table(
        ".MsoTableGrid tr:nth-child(2) td:first-child p.MsoNoSpacing"
    );
    const output = await read_table(
        ".MsoTableGrid tr:nth-child(2) td:last-child p.MsoNoSpacing"
    );

    const lines = await page.$$eval("div.Section1 > :not(table)", divs =>
        [].map.call(divs, d => d.textContent)
    );
    const explanation =
        lines.map(l => l.replace(/^/gm, "* ")).join("\n") + "\n";

    console.log("writing templates ...");
    const dir = join(process.cwd(), `${problem_id}`);
    if (!fs.existsSync(dir)) {
        fs.mkdirSync(dir);
    }

    fs.writeFileSync(join(dir, "input1"), input);
    fs.writeFileSync(join(dir, "output1"), output);

    const cpp_file = `${problem_id}.cc`;

    let cpp_text = fs.readFileSync(join(__dirname, "template.cpp"), "utf8");
    cpp_text = cpp_text.replace(/PROB/g, `prob_${problem_id}`);
    cpp_text = cpp_text.replace(/AUTHOR/g, `author: ${username}`);
    cpp_text = cpp_text.replace(/EXPLANATION/g, explanation);
    fs.writeFileSync(join(dir, cpp_file), cpp_text);

    let test_text = fs.readFileSync(join(__dirname, "test.sh"), "utf8");
    test_text = test_text.replace(/CPPFILE/g, cpp_file);
    fs.writeFileSync(join(dir, "test.sh"), test_text);
    fs.chmodSync(join(dir, "test.sh"), 0755);

    fs.writeFileSync(cred_file, JSON.stringify({ username, password }));
}

(async () => {
    const browser = await puppeteer.launch();
    const page = await browser.newPage();
    const url = `http://www.lightoj.com/login_main.php?url=volume_showproblem.php?problem=${problem_id}`;

    console.log("Opening lightoj.com ...");
    await page.goto(url);
    console.log("Loging in as " + username);
    await page.$eval("#myuserid", (el, v) => (el.value = v), username);
    await page.$eval("#mypassword", (el, v) => (el.value = v), password);
    await page.click('input[type="submit"]');
    await page.waitForSelector(".MsoTableGrid");

    if (submit) {
        const pid = problem_id;
        const dir = join(process.cwd(), `${pid}`);
        const cpp_path = join(dir, `${pid}.cc`);
        const cpp_text = fs.readFileSync(cpp_path, "utf8");
        await page.click("td.one > a");
        console.warn("Opening submition page ...");
        await page.waitForSelector("textarea");
        await page.$eval("textarea", (el, v) => (el.textContent = v), cpp_text);
        await page.click('input[type="submit"]');
        console.warn("Submitting ...");
        await page.waitForSelector("#mytable3");

        let finished = false;
        do {
            const rows = await page.$$eval("tbody tr", all =>
                [].map
                    .call(all, tr =>
                        [].map.call(tr.querySelectorAll("td,th"), t =>
                            t.textContent.trim()
                        )
                    )
                    .filter((tr, idx) => idx >= 2 && idx <= 7)
                    .map(
                        ([
                            id,
                            time,
                            problem,
                            source,
                            cpu,
                            memory,
                            verdict
                        ]) => ({
                            id,
                            time,
                            problem,
                            source,
                            cpu,
                            memory,
                            verdict
                        })
                    )
            );
            console.clear();
            console.table(rows);

            finished =
                ["Not Judged Yet", "Judging..."].indexOf(rows[0].verdict) == -1;

            if (!finished) {
                execSync("sleep 1");
                await page.reload();
            }
        } while (!finished);
    } else {
        await write_template(page);
    }
    await browser.close();
    console.log("Done");
})();
