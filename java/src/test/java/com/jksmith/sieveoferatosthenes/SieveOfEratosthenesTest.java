package com.jksmith.sieveoferatosthenes;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.util.HashMap;
import java.util.Map;

import org.junit.jupiter.api.Test;

class Constants
{
    public static Map<Integer,Long> EXPECTATIONS = new HashMap<Integer,Long>();
    static 
    {
        EXPECTATIONS.put(100,Long.valueOf(25));
        EXPECTATIONS.put(1000,Long.valueOf(168));
        EXPECTATIONS.put(10000,Long.valueOf(1229));
        EXPECTATIONS.put(100000,Long.valueOf(9592));
        EXPECTATIONS.put(1000000,Long.valueOf(78498));
    }    
}

/**
 * Unit test for simple App.
 */
 public class SieveOfEratosthenesTest 
{
    
    void runSieve(int maxNum)
    {
        SieveOfEratosthenes sieve = new SieveOfEratosthenes(maxNum);
        Map<String,Long> result = sieve.calcPrimes();
        assertEquals(Constants.EXPECTATIONS.get(maxNum),result.get("primes"),"Unexpected ");
    }

    @Test
    void calcTo100()
    {
        runSieve(100);
    }

    @Test
    void calcTo1000()
    {
        runSieve(1000);
    }

    @Test
    void calcTo10000()
    {
        runSieve(10000);
    }

    @Test
    void calcTo100000()
    {
        runSieve(100000);
    }

    @Test
    void calcTo1000000()
    {
        runSieve(1000000);
    }
}
