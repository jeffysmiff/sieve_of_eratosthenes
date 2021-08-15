struct PrimeResult {
    int max;
    int primes;
    unsigned long duration;
};

int maxPrimes[] = {100,1000,10000,100000,1000000};

struct PrimeResult calc_primes(int max);
int unset_bit(int* bit_array, int index);
int get_bit(int* bit_array, int index);
int count_primes(int* bit_array, int numBytes);
void print_primes(int* bit_array, int numBytes);
unsigned long get_time();