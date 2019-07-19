#!/usr/bin/env node
require("./daemon-manager.js").manage();
const WebSocket = require("ws");

function build_websocket({ endpoint }) {
    console.log("Opening connection");
    const ws = new WebSocket(endpoint);

    const timeout = 6 * 60 * 60 * 1000; // 6 hours
    const handle = setTimeout(() => {
        if (ws.readyState === WebSocket.OPEN) {
            console.log("Restarting connection");
            ws.close();
        }
    }, timeout);

    ws.on("error", evt => console.log("SOCKET ERROR: ", evt));
    ws.on("close", () => {
        clearTimeout(handle);
        console.log("Connection closed");
        build_websocket({ endpoint });
    });
    ws.on("message", msg => {
        const { stream, data } = JSON.parse(msg) || {};
        if (stream && data) {
            const { s: symbol, c: close, E: time } = data;
            console.log({ symbol, close, time });
        } else {
            console.log("Bad message: ", msg);
        }
    });
}

var underlyings = ["bchabcusdt", "btcusdt", "ethusdt", "ltcusdt", "xrpusdt"];
const streams = underlyings.map(pair => `${pair}@miniTicker`).join("/");

build_websocket({
    endpoint: `wss://stream.binance.com:9443/stream?streams=${streams}`
});

// Binance Docs:
// https://github.com/binance-exchange/binance-official-api-docs
