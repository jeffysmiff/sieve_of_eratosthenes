#include <iostream>
#include "sieve.h"

int main() {
    int maxPrimes[] = {100,1000,10000,100000,1000000};
    int numMaxPrimes = sizeof(maxPrimes)/sizeof(maxPrimes[0]);
    std::cout << "{\"c++\":{";
    for(int i=0; i<numMaxPrimes;i++) {
        Sieve* sieve = new Sieve(maxPrimes[i]);
        sieve->calcPrimes();
        std::map<std::string, uint64_t> result = sieve->getResult();
        std::cout << "\"" << maxPrimes[i] << "\":{\"primes\":" << result["primes"] << ",\"duration\":" << result["duration"] <<  "}";
        if(i<numMaxPrimes-1) {
            std::cout << ",";
        }
    }

    std::cout << "}}" << std::endl;
    return 0;
}

