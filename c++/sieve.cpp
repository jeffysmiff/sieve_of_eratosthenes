#include <chrono>
#include <cmath>
#include <ctime>
#include <iostream>
#include "sieve.h"

Sieve::Sieve(int maxNum) {
    m_maxNum = maxNum;
    m_primes = new BitArray(m_maxNum);
    int numBytes = (int)ceil(maxNum/8.0);
    /*
     * Unset every even number except 2 since they cannot be prime 
     */ 
    for(int i=0; i<m_maxNum; i+=2) {
        if(i!=2) {
            m_primes->unsetBit(i);
        }
    }
    /*
     * 1 is also not prime so need to unset that
     */ 
    m_primes->unsetBit(1);
}

int Sieve::countPrimes() {
    return m_primes->countSet();
}

void Sieve::printPrimes() {
    m_primes->printSet();
}

uint64_t Sieve::getTime() {
    uint64_t microsecSinceEpoch = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return microsecSinceEpoch;
}

void Sieve::calcPrimes() {
    uint64_t startTime = getTime();
    for(int i=3; i<=(int)sqrt((double)m_maxNum); i+=2) {
        if(m_primes->getBit(i)) {
            for(int j=i; j<m_maxNum; j+=i) {
                if(j!=i) {
                    m_primes->unsetBit(j);
                }
            }
        }
    }
    uint64_t endTime = getTime();

    // Fill out the result
    m_result["primes"]=m_primes->countSet();
    m_result["duration"]=endTime-startTime;
}

std::map<std::string, uint64_t> Sieve::getResult() {
    return m_result;
}