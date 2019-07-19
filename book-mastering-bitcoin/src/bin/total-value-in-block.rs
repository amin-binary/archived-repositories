use reqwest;
use serde;
use serde_json::{self, to_string_pretty, json};



fn rpc(method: &str, params : &[impl serde::ser::Serialize]) -> Result<serde_json::Value, Box<std::error::Error>> {
    let client = reqwest::Client::new();

    let jsn = json!({
        "jsonrpc": "2.0",
        "method": method,
        "params": params
    });

    let mut res = client
        .post("http://127.0.0.1:18332")
        .basic_auth("bitcoinrpc", Some("Golabi*7"))
        .json(&jsn)
        .send()?;

    let result: serde_json::Value = res.json()?;
    let result = result["result"].clone();
    Ok(result)
}

fn log(value: &serde_json::Value) {
    println!("{}", to_string_pretty(value).unwrap());
}

fn main() -> Result<(), Box<std::error::Error>> {
    let blockheight = 1564658;

    let blockhash = rpc("getblockhash", &[blockheight])?;
    let block = rpc("getblock", &[blockhash])?;

    log(&block);

    let transactions = block["tx"].as_array().unwrap();

    let mut block_value = 0f64;

    for txid in transactions {
        let mut tx_value = 0f64;
        let tx_raw = rpc("getrawtransaction", &[txid])?;
        let tx_decoded = rpc("decoderawtransaction", &[tx_raw])?;
        for output in tx_decoded["vout"].as_array().unwrap() {
            tx_value += output["value"].as_f64().unwrap();
        }
        dbg!((txid, tx_value));
        block_value += tx_value;
    }

    dbg!(block_value);

    Ok(())
}
