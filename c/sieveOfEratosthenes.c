#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <sys/time.h>
#include "sieveOfEratosthenes.h"

/* Sieve of Eratosthenes
   Using int's to form bit array. Each is 1 byte long */

int unset_bit(int* bit_array, int index) {
    /*
     * Div index by 8 to find byte. Remainder is bitshift
     * Want to set to 0 so logical AND with 0 on that bit
     * will flip it if it's currently set
     */
    int base_index = (int)(index/8);
    int remainder = index % 8;
    bit_array[base_index] &= ~(1 << remainder);
}

struct PrimeResult calc_primes(int max) {
    struct PrimeResult result;
    result.max = max;
    result.duration = 0;
    result.primes = 0;
    int numBytes = (int)ceil(max/8.0);
    int bit_array[numBytes];
    /*
     * Set each byte to 10101010 since every even number is not prime
     */ 
    for(int i=0; i<numBytes; i++) {
        bit_array[i] = 0xAA;
    }
    /* 
     * 0 = not prime
     * 1 = not prime
     * 2 = prime
     * Therefore first byte should be 10101100
     */
    bit_array[0] = 0xAC;
    /*
     * Unset any bits beyond max in case we have some left over
     */
    for(int i=max; i<numBytes*8; i++) {
        unset_bit(bit_array, i);
    }

    unsigned long startTime = get_time();
    for(int i=3; i<=(int)sqrt((double)max); i+=2) {
        if(get_bit(bit_array,i)) {
            for(int j=i; j<max; j+=i) {
                if(j!=i) {
                    unset_bit(bit_array, j);
                }
            }
        }
    }
    unsigned long endTime = get_time();
    // print_primes(bit_array, numBytes);
    result.primes = count_primes(bit_array, numBytes);
    result.duration = endTime-startTime;
    return result;
}

unsigned long get_time() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return 1000000 * tv.tv_sec + tv.tv_usec;
}

int get_bit(int* bit_array, int index) {
    int base_index = (int)(index/8);
    int remainder = index % 8;
    return ( (bit_array[base_index] & (1 << remainder )) != 0 ) ; 
}

int count_primes(int* bit_array, int numBytes) {
    unsigned int count = 0;
    /*
     * For each byte, if it's 0, then no bits are set
     * so loop round while n != 0
     * Then, if n logical and 1 = 1, bit is set so
     * increment counter, then bitshift 1 to the right
     */
    for(int i=0; i<numBytes; i++)
    {
        uint8_t n = bit_array[i];
        while (n) {
            count += n & 1;
            n >>= 1;
        }
    }
    return count;
}

void print_primes(int* bit_array, int numBytes) {
    for(int i=0; i<numBytes; i++)
    {
        uint8_t n = bit_array[i];
        for(uint8_t j=0; j<8; j++) {
            if((n >> j) & (0x01) == 1) {
                printf("%d,",(i*8)+j);
            }
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    int numMaxPrimes = sizeof(maxPrimes)/sizeof(maxPrimes[0]);
    printf("{\"c\":{");
    for(int i=0; i<numMaxPrimes;i++) {
        struct PrimeResult result = calc_primes(maxPrimes[i]);
        printf("\"%d\":{\"primes\":%d,\"duration\":%lu}", maxPrimes[i],result.primes, result.duration);
        if(i<numMaxPrimes-1) {
            printf(",");
        }
    }

    printf("}}\n");
    return 0;
}