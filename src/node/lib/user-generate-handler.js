const summonUser = require("white-summoner");

const handler = {};

handler.generate = (req, res) => {
  summonUser(req.body.locale)
    .then(profile => {
      const { country, personal_profile, address } = profile;
      return { country, personal_profile, address };
    })
    .then(user => res.send({ message: "user generated", user }))
    .catch(err => res.status(500).send({ message: "user not generated" }));
};

module.exports = handler;
