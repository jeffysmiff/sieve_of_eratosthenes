#include <cmath>
#include <cstdint>
#include <iostream>
#include "bitarray.h"

BitArray::BitArray(int size) {
    m_numBytes = (int)ceil(size/8.0);
    m_bitArray = new int[m_numBytes];
    // Set all to 1
    for(int i=0; i<m_numBytes; i++) {
        m_bitArray[i] = 0xFF;
    }
    /*
     * Unset any bits beyond max in case we have some left over
     */
    for(int i=size; i<m_numBytes*8; i++) {
        unsetBit(i);
    }
}

void BitArray::unsetBit(int index) {
    /*
     * Div index by 8 to find byte. Remainder is bitshift
     * Want to set to 0 so logical AND with 0 on that bit
     * will flip it if it's currently set
     */
    int base_index = (int)(index/8);
    int remainder = index % 8;
    m_bitArray[base_index] &= ~(1 << remainder);
}

int BitArray::getBit(int index) {
    int base_index = (int)(index/8);
    int remainder = index % 8;
    return ( (m_bitArray[base_index] & (1 << remainder )) != 0 ) ; 
}

int BitArray::countSet() {
    unsigned int count = 0;
    /*
     * For each byte, if it's 0, then no bits are set
     * so loop round while n != 0
     * Then, if n logical and 1 = 1, bit is set so
     * increment counter, then bitshift 1 to the right
     */
    for(int i=0; i<m_numBytes; i++)
    {
        uint8_t n = m_bitArray[i];
        while (n) {
            count += n & 1;
            n >>= 1;
        }
    }
    return count;
}

void BitArray::printSet() {
    for(int i=0; i<m_numBytes; i++)
    {
        uint8_t n = m_bitArray[i];
        for(uint8_t j=0; j<8; j++) {
            if((n >> j) & (0x01) == 1) {
                std::cout << (i*8)+j << ',';
            }
        }
        std::cout << std::endl;
    }
}