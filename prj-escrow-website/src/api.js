
export
const reg_txns = ({
  endpoint = 'wss://ws.blockchain.info/inv',
  retry = 5,
  on_utx
}) => {
  const ws = new WebSocket(endpoint);
  ws.onopen = () => {
    // register to unconfirmed transactions
    ws.send(`{"op":"unconfirmed_sub"}`);
  };
  ws.onmessage = ev => {
    // parse array of transactions
    const data = JSON.parse(ev.data);
    if(data.op === 'utx') on_utx(data.x);
    else console.error(data);
  };
  ws.onerror = ev => console.error(ev);
  ws.onclose = () => {
    if(!retry) { return; };
    --retry;
    setTimeout(() => reg_txns({endpoint, retry, on_utx}), 2000);
  };
}

