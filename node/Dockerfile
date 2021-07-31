FROM ubuntu:20.04

RUN apt update && apt upgrade -y
RUN apt install -y curl

RUN mkdir /install
WORKDIR /install

RUN curl -sL https://deb.nodesource.com/setup_16.x -o- | /bin/bash
RUN apt install -y nodejs

RUN npm install -g npm

RUN npm -v
RUN node -v

RUN mkdir /src
WORKDIR /src

ADD package.json /src/
ADD package-lock.json /src/

RUN npm install

ADD sieveOfEratosthenes.mjs /src/
ADD test /src/test

RUN npm test

RUN rm -rf node_modules

RUN npm install --production

ENTRYPOINT [ "node", "sieveOfEratosthenes.mjs" ]

