const ws = require("ws");
const child = require("child_process");

let pipe = child.spawn(__dirname + "/build/print_6dof", [], {
  stdio: "pipe"
});

pipe.stderr.setEncoding("ascii");
pipe.stderr.on("data", data => {
  console.log(">", data);
});

pipe.stdout.setEncoding("ascii");
pipe.stdout.on("data", data => {
  let splt = data.trim().split(" ").map(parseFloat);
  if (splt.findIndex(isNaN) >= 0) {
    console.log(data, splt);
  } else {
    sendData(splt);
  }
});

function shutdown() { // < note: this is not currently used
  pipe.stdin.write("\n");
  pipe.stdin.end();
  process.stdin.end();
  wss.close(() => console.log("WSS closed"));
}

pipe.on("close", code => {
  console.log("Process exited with code " + code);
});

let wss = new ws.Server({port: 7700});

wss.broadcast = function(msg) {
  wss.clients.forEach(client => {
    if (client.readyState === ws.OPEN) {
      client.send(msg);
    }
  });
};

wss.on("connection", con => {
  console.log("Got connection!");
});

function sendData(data) {
  wss.broadcast(JSON.stringify(data));
}
