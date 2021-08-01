FROM ubuntu:20.04

RUN apt update && apt upgrade -y

RUN DEBIAN_FRONTEND="noninteractive"  apt install -y openjdk-11-jdk maven

RUN mkdir /src

WORKDIR /src

ADD pom.xml /src/pom.xml

ADD src /src/src

RUN mvn clean package

ENTRYPOINT [ "java", "-cp", "target/sieveoferatosthenes-1.0-SNAPSHOT.jar", "com.jksmith.sieveoferatosthenes.App" ]

