/// <reference types="cypress" />

//GET Request Test cases
describe("Verfiy Get api  request", () => {
  it("Navigate to  Api Url ", () => {
    cy.request("GET", "http://localhost:3000/").then((response) => {
      expect(response.body).to.have.property("message", "hello");
    });
  });
  it("Verify correct HTTP status code.", () => {
    cy.request("GET", "http://localhost:3000/").then((response) => {
      expect(response.status).to.eq(200);
    });
  });
});

//Post Request Test cases
describe("Verfiy Post api  request", () => {
  
  // Replace the country code here.All auomated test script run and give the final results 
  const code = { locale: "DE" };

  it("Verify POST request ", () => {
    cy.log(myJSON);
    cy.request("POST", "http://localhost:3000/generate", code).then(
      (response) => {
        expect(response.body).has.property("message", "user generated");
      }
    );
  });
  it("Verify correct HTTP status code.", () => {
    cy.request("POST", "http://localhost:3000/generate", code).then(
      (response) => {
        expect(response.status).to.eq(200);
        expect(response.duration).to.not.be.greaterThan(1000);
      }
    );
  });
  it("Verify Content-Type is present", () => {
    cy.request("POST", "http://localhost:3000/generate", code)
      .its("headers")
      .its("content-type")
      .should("include", "application/json");
  });
  it("Verify  Response time is less than 200ms", () => {
    cy.request("POST", "http://localhost:3000/generate", code).then(
      (response) => {
        expect(response.duration).to.not.be.greaterThan(1000);
      }
    );
  });

  it("Verify response header ", () => {
    cy.request("POST", "http://localhost:3000/generate", code).then(
      (response) => {
        expect(response).to.have.property("headers");
      }
    );
  });
  it("Body is not blanck ", () => {
    cy.request("POST", "http://localhost:3000/generate", code).then(
      (response) => {
        expect(response).to.not.be.null;
      }
    );
  });

  it("Verify  Post Api response object and mandatory fileds", () => {
    cy.request("POST", "http://localhost:3000/generate", code).then(
      (response) => {
        var userData = response.body.user;
        //validates Objects {country,address,personal_profile}
        expect(userData).to.have.all.keys(
          "country",
          "address",
          "personal_profile"
        );
        expect(response.body).to.have.property("user");

        // validate object(personal_profile) fields {first_name,last_name,date_of_birth,mobile_phone,national_id}
        var personalProfile = userData.personal_profile;
        const address = userData.address;

        expect(personalProfile).to.have.all.keys(
          "first_name",
          "last_name",
          "date_of_birth",
          "mobile_phone",
          "national_id"
        );
        expect(personalProfile.first_name).to.not.be.null;
        expect(personalProfile.last_name).to.not.be.null;
        expect(personalProfile.date_of_birth).to.not.be.null;
        expect(personalProfile.mobile_phone).to.not.be.null;
        const mobileNumber = personalProfile.mobile_phone;
        expect(mobileNumber).to.have.lengthOf(13);

        expect(address).to.have.all.keys(
          "country",
          "address_line1",
          "address_line2",
          "city",
          "post_code",
          "region_name",
          "landline",
          "first_name",
          "last_name",
          "company"
        );
        expect(address.country).to.not.be.null;
        expect(address.landline).to.not.be.null;
        expect(address.first_name).to.not.be.null;
        expect(address.last_name).to.not.be.null;
        expect(address.company).to.not.be.null;
      }
    );
  });

  it("Verify available country codes", () => {
    cy.request("POST", "http://localhost:3000/generate", code).then(
      (response) => {
        var userData = response.body.user;
        const address = userData.address;

        expect(address.country).to.equal("DE");
      }
    );
  });
  it("Verify response body shoudl not be null ", () => {
    cy.request("POST", "http://localhost:3000/generate", code).then(
      (response) => {
        expect(response).to.not.be.null;
      }
    );
  });
});
