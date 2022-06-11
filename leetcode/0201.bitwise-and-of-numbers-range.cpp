class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      int mc = 0;
      while (left != right) {
        left >>= 1;
        right >>= 1;
        ++mc;
      }
      return right << mc;
    }
};
