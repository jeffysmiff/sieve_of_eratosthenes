# Sieve of Eratosthenes

Various implementations of the prime sieve described [here:](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)

Time how long it takes to calculate for primes under:
100
1000
10000
100000
1000000

## Validation
Validate prime counts are as follows:
```
100 : 25
1000 : 168
10000 : 1229
100000 : 9592
1000000 : 78498
```

## Results
In the root directory, a JSON file is provided with results
for each language from my laptop so they can be compared.
Each was run from it's Docker image.

## Python
Written using 3.9.6
```
cd python
source venv/bin/activate
pip install -r requirements.txt
python sieveOfEratosthenes.py
```

## Node
Written using 16.4.1
```
cd node
npm install
npm test
```

## Java
Written using OpenJDK 11 using Maven for dependency management and build
```
cd java
mvn clean package
java -cp target/sieveoferatosthenes-1.0-SNAPSHOT.jar com.jksmith.sieveoferatosthenes.App
```

## Docker
### Purpose
In order to run in a reproducable, managed environment, the code
can be wrapped in a suitable Docker image and a container run to 
calaculate primes.

### Build
A Docker image for any specific language can be built with:
```
cd <language>
docker build --rm -t <tag name> .
```
### Run
A container can then be run with:
```
docker run -it --rm <tag name>
```
Results are provided as a JSON object