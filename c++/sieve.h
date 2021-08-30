#include <map>
#include <cstdint>
#include "bitarray.h"

class Sieve {
    private: 
        int m_maxNum;
        BitArray* m_primes;
        std::map<std::string, uint64_t> m_result;
        uint64_t getTime();

    public:
        Sieve(int maxNum);
        std::map<std::string, uint64_t> getResult();
        int countPrimes();
        void printPrimes();
        void calcPrimes();
};