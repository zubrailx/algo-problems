/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
      int oc = 0;
      while (n != 0) {
        oc += n & 1;
        n >>= 1;
        if (oc > 1) { return false; }
      }
      return oc;
    }
};
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }
};

