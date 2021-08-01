package com.jksmith.sieveoferatosthenes;

import java.time.Duration;
import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;

class SieveOfEratosthenes
{
    private int maxNum = 0;
    private BitSet primes = null;
    private Map<String,Long> result = null;

    public SieveOfEratosthenes(int maxNum) 
    {
        this.maxNum = maxNum;
        this.primes = new BitSet(this.maxNum);
        this.primes.flip(2,this.maxNum);
        this.result = new HashMap<String,Long>();
        for(int i=4; i<this.maxNum; i+=2)
        {
            this.setBit(i);
        }
    }

    public Map<String,Long> getResult()
    {
        return this.result;
    }

    public void setBit(int n)
    {
        this.primes.set(n,false);
    }

    public boolean getBit(int n)
    {
        return this.primes.get(n);
    }

    private int countPrimes()
    {
        int count = 0;
        for(int i=0; i<this.maxNum; i++)
        {
            if( this.getBit(i) )
                count++;
        }
        return count;
    }

    public void printPrimes()
    {
        System.out.println("There are " + this.countPrimes() + " primes under " + this.maxNum);
        for(int i=2; i<this.maxNum; i++)
        {
            if(this.getBit(i)) 
            {
                System.out.print("i,");
            }
        }
        System.out.println();
    }

    public Map<String,Long> calcPrimes()
    {
        Instant startTime = Instant.now();
        for(int i=3; i<=Math.sqrt(this.maxNum); i+=2)
        {
            if(this.getBit(i))
            {
                for(int j=i; j<this.maxNum; j+=i)
                {
                    if(j!=i)
                    {
                        this.setBit(j);
                    }
                }
            }
        }
        Instant endTime = Instant.now();
        Duration duration = Duration.between(startTime,endTime).truncatedTo(ChronoUnit.MICROS);
        // this.printPrimes();
        this.result.put("primes",Long.valueOf(this.countPrimes()));
        this.result.put("duration",duration.toNanos()/1000);
        return result;
    }
}

/**
 * Hello world!
 *
 */
public class App 
{
    private static final int maxPrimes[] = {100,1000,10000,100000,1000000};
    public static void main( String[] args )
    {
        Map<String,Map<String,Long>> results = new HashMap<String,Map<String,Long>>();
        for(int maxNum : maxPrimes)
        {
            SieveOfEratosthenes sieve = new SieveOfEratosthenes(maxNum);
            Map<String, Long> result = sieve.calcPrimes();
            results.put(String.valueOf(maxNum), result);
        }
        System.out.print("{\"java\":{");
        Iterator<Entry<String,Map<String,Long>>> it = results.entrySet().iterator();
        while(it.hasNext()) 
        {
            Entry<String,Map<String,Long>> result = it.next();
            System.out.print("\"" + result.getKey() + "\":");
            System.out.print("{\"primes\":");
            System.out.print(result.getValue().get("primes"));
            System.out.print(",\"duration\":");
            System.out.print(result.getValue().get("duration"));
            System.out.print("}");
            if(it.hasNext())
                System.out.print(",");
        }
        System.out.println("}}");
    }
}