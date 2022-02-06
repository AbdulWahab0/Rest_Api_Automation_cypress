# cypress Api Automation

A coding challenge for  learning 

## Requirements

- Any computer: Mac, Windows, Linux
- Node 12.0.0+ (LTS)
- git
- Docker
- Postman

## About project

- Postman is used for api testing
- Cypress is used as Test automation framework 
- Manual test case and Test Strategy is implemented
- For reports Moacha awsome is used
- Docker for containerised environment
- Used cypress assertion

## Introduction

This is a web service for generating users. It provides a simple REST API inside a docker container.

### Your task

Define a proper test strategy for this application and design the related test cases for it.
Implement a suite of automated tests with your preferred scripting language, or decide to go with manual testing.

Document the test design and results providing:

- A description of the test strategy adopted.
- The list of test-cases designed, including test steps.
- An overview of the test cases executed, passed, and failed.
- An overview of the issues found, highlighting the critical ones.

Furthermore, in case of automated tests, provide the scripts and a detailed documentation on how to setup and run them. "Dockerized" applications are highly appreciated.

## Getting started

Setup your local machine for [using Docker](#installation-and-usage).

You can generate a user by calling:

```
POST /generate HTTP/1.1
Host: localhost:3000
Content-Type: application/json

Body:
{
	"locale": "YOUR_COUNTRY_CODE"
}
```

Following the list of country-codes available:

```
AL AR AM AU AT AZ BD BE BA BR BZ BG CA CL CN CO CR DK EG GB EE FI FR GE DE GR HU IN IR IL IT JP KR MX MA NP NL NZ NG NO PK PL PT RO RU SA SK SI ES SE CH TR UA US VN
```


## Run Locally 🚀

- git clone : git@github.com:AbdulWahab0/su-hw-challenge-2021-07-07_AbdulWahab.git
- With Docker installed, you can just go to the root folder of the project and run:
```bash
docker-compose up
```
- Now go to the directly (src/node) and install npm packages

- ``` cd node ```
- ``` npm install ```

### Enter the following commands in terminal in order to execute test on chrome browser locally 
```bash
npm test
```
### Enter the following commands in terminal in order to execute test on electron browser to view command console test

- ``` npm run cy:apitest-only ```

### Enter the following command to visulaize test execution report
- ``` npm run merge``` 
- ``` generate_mochawesome_report``` 
- ``` npm run final_report ``` 

### Enter the following commands to run automated test inside docker container

- ``` docker run --network=host -v $PWD:/e2e -w /e2e cypress/included:7.5.0 ```
### Manual test case excel Sheet 
```bash

src/node/Manual-Test-Case-document
```
### Test Strategy doc

```bash
src/node/Test_Strategy
```




Let me know if you have any questions. [Email Abdul Wahab ](mailto:wahab3060h@gmail.com)

## Technology used:

 - Cypress 
 - JavaScript
 - Mochawesome
 - Docker

## Using and troubleshooting Docker

### Installation and usage

If you don't have Docker, you first need to install it using the official guides:
- If you have Mac, follow the [get started with Docker Desktop for Mac](https://docs.docker.com/docker-for-mac/)
- If you have Windows, follow the [get started with Docker for Windows](https://docs.docker.com/docker-for-windows/)
- And if you have Linux, you need to [install the server version compatible with your platform](https://docs.docker.com/install/)

With Docker installed, you can just go to the root folder of the project and run:
```bash
docker-compose up
```

After that, the server will be running and the application should be available on `http://localhost:3000`. To stop the containers, you can press `Ctrl + C`.

### Troubleshooting

If you are having trouble with your containers, you can stop and remove all the containers running the following command on the root folder:
```bash
docker-compose stop
docker-compose rm
```
And after that you can just run again:
```bash
docker-compose up
```


If you need to check which containers are running in your machine, just do:
```bash
docker ps
```


If you need to forcefully kill any of the containers, you can just get the `CONTAINER ID` from the previous command, add do:
```bash
docker kill <container_id>
```
To get access to the running container, and run other commands inside of it, you can run the following command on the root folder:
```bash
docker-compose run app bash
```
Typing `exit` when you are finished.

If you are using Docker under Windows OS and you get an error like `/usr/bin/env: 'bash\r': No such file or directory`, you might have have `git` changing the line endings, therefore change the following settings:
```bash
git config --global core.autocrlf input
```
See also [this article](https://www.git-scm.com/book/en/v2/Customizing-Git-Git-Configuration) for reference.
