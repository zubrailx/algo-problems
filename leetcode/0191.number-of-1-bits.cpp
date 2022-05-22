
class Solution {
public:
    int hammingWeight(uint32_t n) {
      int result = 0;
      while (n) {
        if (n & 1) {
          ++result;
        }
        n = n >> 1;
      }
      return result;
    }
};
// also there are built-in functions in gcc like:
/*
__builtin_popcount(x): This function is used to count the number of one’s(set bits) in an integer.

__builtin_parity(x): This function is used to check the parity of a number. This function returns true(1) if the number has odd parity else it returns false(0) for even parity.

__builtin_clz(x): This function is used to count the leading zeros of the integer. Note: clz = count leading zero’s.

__builtin_ctz(x): This function is used to count the trailing zeros of the given integer. Note: ctz = count trailing zeros.
*/
