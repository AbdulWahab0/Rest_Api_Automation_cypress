const server = require("./lib/server");

const app = {
  start: () => {
    // start the server
    server.start();
  },
  stop: () => {
    server.stop();
  }
};

app.start();

module.exports = app;
