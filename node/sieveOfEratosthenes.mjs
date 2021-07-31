import BitVector from 'bit-vec';
import Microseconds from 'microseconds';

export class SieveOfEratosthenes {
  constructor(maxNum) {
    this.maxNum = maxNum;
    // Creates a bit array with number of specified bits to the closest byte boundary
    // e.g. creating BitVector of 100 bits results in 104 bits being created
    this.primes = new BitVector(maxNum);
    // Init bit array to all 1's
    this.primes.setRange(0, this.primes.bits, 1);
    // 0 and 1 are not prime so set them as such
    this.primes.setRange(0, 2, 0);
    // Clear any bits higher than maxNum
    for (let i=this.maxNum; i<this.primes.bits; i++) {
      this.primes.set(i, 0);
    }
    // setRange not working - only setting bit at maxNum to 0
    // this.primes.setRange(this.maxNum, this.primes.bits+1, 0);
    // DEBUG - print array as-is
    // any even number higher than 4 is not prime since it has 2 as a factor
    for (let i=4; i<this.primes.bits; i+=2) {
      this.primes.set(i, 0);
    }
    this.result = {};
  }

  async count() {
    return this.primes.bits;
  }

  async setBit(n) {
    // Could use flip here since I init the bit array to 1 but using
    // set just to be 100% safe
    this.primes.set(n, 0);
  }

  async getBit(n) {
    return this.primes.get(n);
  }

  async printPrimes() {
    console.log('There are ' + await this.primes.count() + ' primes under ' + this.maxNum);
    const count = await this.count();
    for (let i=2; i<count; i++) {
      if (await this.getBit(i) === 1) {
        process.stdout.write(i+',');
      }
    }
    console.log('');
  }

  async calcPrimes() {
    const startTime = Microseconds.now();
    const count = await this.count();
    for (let i=3; i<=Math.round(Math.sqrt(count)); i+=2 ) {
      if (await this.getBit(i) === 1) {
        for (let j=i; j<count; j+=i) {
          if (j !== i) {
            await this.setBit(j);
          }
        }
      }
    }
    const duration = Math.round(Microseconds.now()-startTime);
    this.result = {
      'primes': await this.primes.count(), 
      'duration': duration
    };
    // console.log('Took ' + duration + '\u03BCs to calc primes under ' + this.maxNum);
    // await this.printPrimes();
    return this.result;
  }
}

(async () => {
  let results = {
    node: {}
  };

  const expectations = {
    100: 25,
    1000: 168,
    10000: 1229,
    100000: 9592,
    1000000: 78498,
  };

  for (const [key, value] of Object.entries(expectations)) {
      const result = await new SieveOfEratosthenes(key).calcPrimes();
      results['node'][key.toString()] = result;
  }
  console.log(JSON.stringify(results,null));
})()
