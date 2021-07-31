FROM ubuntu:20.04

RUN apt update && apt upgrade -y
RUN DEBIAN_FRONTEND="noninteractive" apt install -y python3.9 python3-pip

RUN mkdir /src

WORKDIR /src

ADD requirements.txt /src/
RUN pip3 install -r requirements.txt

ADD sieve_of_eratosthenes.py /src/

ENTRYPOINT [ "python3", "sieve_of_eratosthenes.py" ]

