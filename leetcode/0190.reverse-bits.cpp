class Solution {
public:
  /*
    uint32_t reverseBits(uint32_t n) {
      // straight-forward method
      bool tmp1;
      bool tmp2;
      for (int i = 0; i < 16; ++i) {
        tmp1 = (n >> i) & 1;
        tmp2 = (n >> (31 - i)) & 1;
        
        n = (n & ~(1 << i)) | (tmp2 << i);
        n = (n & ~(1 << (31 - i))) | (tmp1 << (31 - i));
      }
      return n; 
    }
    */ 
    uint32_t reverseBits(uint32_t n) {
      // straight-forward method
      uint32_t result = 0;
      for (int i = 0; i < 32; ++i) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
      }
      return result; 
    }
};
