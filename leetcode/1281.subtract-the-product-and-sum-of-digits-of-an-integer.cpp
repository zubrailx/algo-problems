class Solution {
public:
  int subtractProductAndSum(int n) {
    int prod = 1;
    int sum = 0;
    int sign;
    while (n) {
      sign = n % 10;
      prod *= sign;
      sum += sign;
      n /= 10;
    } 
    return prod - sum;
  }
};

