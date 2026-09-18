class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int i = 0;
        while(i < 32){
            int bit = n & 1;
            res |= (bit << (31 - i));
            n = n >> 1;
            i++;
        }
        return res;
    }
};
