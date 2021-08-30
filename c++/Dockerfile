FROM ubuntu:20.04

RUN apt update && apt upgrade -y

RUN DEBIAN_FRONTEND="noninteractive"  apt install -y build-essential

RUN mkdir /src

WORKDIR /src

ADD bitarray.h /src/
ADD bitarray.cpp /src/
ADD sieve.h /src/
ADD sieve.cpp /src/
ADD main.cpp /src/
ADD bitarray.h /src/

RUN g++ *.cpp -o sieveOfEratosthenes

ENTRYPOINT [ "./sieveOfEratosthenes" ]

