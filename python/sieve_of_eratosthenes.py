from bitarray import bitarray
from math import isqrt
from datetime import datetime

expectations = {
    100 : 25,
    1000 : 168,
    10000 : 1229,
    100000 : 9592,
    1000000 : 78498
}

class Sieve_of_eratoschenes:
    def __init__(self, max_num):
        self.max_num = max_num
        self.primes = bitarray(int(self.max_num))
        self.primes.setall(1)
        # 0 and 1 are not prime and we won't include them in calculations
        self.primes[0] = 0
        self.primes[1] = 0
        # Chop out even numbers over 2
        for i in range(4,len(self.primes),2):
            self.primes[i] = 0

    def set_bit(self, n):
        self.primes[n] = 0

    def get_bit(self, n):
        return self.primes[n]

    def print_primes(self):
        print(f'There are {self.primes.count(1)} primes under {self.max_num}')
        for i in range(2,len(self.primes)):
            if self.get_bit(i):
                print(f'{i},', end='')
            print

    def calc_primes(self):
        start_time = datetime.now()
        # Start at 3 and only work out odd numbers since all even numbers over 2 cannot be prime
        for i in range(3,isqrt(self.max_num)+1,2):
            if self.get_bit(i):
                for j in range(i,self.max_num,i):
                    if j != i:
                        self.set_bit(j)
        end_time = datetime.now()
        print(f'Took {(end_time-start_time).microseconds}\u03BCs to calc primes under {self.max_num}')
        # self.print_primes()
        return self.primes.count(1)

def main():
    for key in expectations.keys():
        expectation = expectations[key]
        result = Sieve_of_eratoschenes(key).calc_primes()
        assert result == expectation, f'Number of primes for {key} not as expected, got {result}, expected {expectation}'

if __name__ == "__main__":
    # execute only if run as a script
    main()