class BitArray {
    private: 
        int* m_bitArray;
        int m_numBytes;
    public:
        BitArray(int size);
        void unsetBit(int index);
        int getBit(int index);
        int countSet();
        void printSet();
};


