FROM ubuntu:20.04

RUN apt update && apt upgrade -y

RUN DEBIAN_FRONTEND="noninteractive"  apt install -y build-essential

RUN mkdir /src

WORKDIR /src

ADD sieveOfEratosthenes.c /src/
ADD sieveOfEratosthenes.h /src/

RUN gcc -g sieveOfEratosthenes.c -lm -o sieveOfEratosthenes

ENTRYPOINT [ "./sieveOfEratosthenes" ]

