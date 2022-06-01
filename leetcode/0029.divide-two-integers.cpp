// using long
// not to use long we can start recursion for example on larger value and add 1:
// -1 + divide(dividend + divisor, divisor);
// 1 + divide(dividend -divisor, divisor);

long mns(long val) {
  return (long)(~val) + (long)1;
}

class Solution {
public:
    int divide(long dividend, long divisor) {
      if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
      } 
      
      bool sign;
      if (dividend < 0 && divisor > 0) {
        sign = 1;
        dividend = mns(dividend);
      } else if (dividend > 0 && divisor < 0) {
        sign = 1;
        divisor = mns(divisor);
      } else if (dividend < 0 && divisor < 0) {
        sign = 0;
        divisor = mns(divisor);
        dividend = mns(dividend);
      } else {
        sign = 0;
      }
      
      long result = 0;
      int byte_move;
      while (dividend >= divisor) {
        byte_move = 0;
        while ((divisor << (byte_move + 1) > 0) && dividend > divisor << (byte_move + 1)) {
          ++byte_move;
        }
        dividend -= divisor << byte_move;
        result += 1 << byte_move;
      }
      return (sign) ? mns(result) : result;
    }
};

