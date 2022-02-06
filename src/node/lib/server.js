const express = require("express");
const bodyParser = require("body-parser");

const userGenHandler = require("./user-generate-handler");

const app = express();
const PORT = 3000;
const router = express.Router();

// //parsing
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// routing
app.use("/", router);

router.get("/", (req, res) => {
  res.json({ message: "hello" });
});
router.route("/generate").post(userGenHandler.generate);

//Exposing public methods
const server = {
  start: () => {
    app.listen(PORT);
    console.log("\x1b[33m%s\x1b[0m", `\n\n\nServer started on port ${PORT}\n`);
  },
  stop: done => {
    process.exit(0);
    done();
  }
};

module.exports = server;
