// top-down
class Solution {
public:
  vector<int> fibs;
    int tribonacci(int n) {
      if (n == 0) { return 0;}
      if (n == 1 || n == 2) { return 1;}
      
      fibs.resize(n + 1, -1);
      fibs[0] = 0; fibs[1] = 1; fibs[2] = 1;
      
      return calc(n);
    }
  
    int calc(int n) {
      if (fibs[n] == -1) {
        fibs[n] = calc(n - 1) + calc(n - 2) + calc(n - 3);
      }
      return fibs[n];
    }
};
