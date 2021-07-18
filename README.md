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