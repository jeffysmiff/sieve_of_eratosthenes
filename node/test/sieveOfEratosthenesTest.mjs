import {SieveOfEratosthenes} from '../sieveOfEratosthenes.mjs';
import {describe, it} from 'mocha';
import {expect} from 'chai';


describe('Test prime sieve up to 1000000', function() {
  const expectations = {
    100: 25,
    1000: 168,
    10000: 1229,
    100000: 9592,
    1000000: 78498,
  };

  for (const [key, value] of Object.entries(expectations)) {
    it('Test for primes up to ' + key, async function() {
      const result = await new SieveOfEratosthenes(key).calcPrimes();
      expect(result).to.equal(value, 'Result: ' + result + ' does not match expectation: ' + value);
    });
  }
});
