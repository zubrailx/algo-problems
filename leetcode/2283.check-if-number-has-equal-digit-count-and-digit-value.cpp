class Solution {
public:
    bool digitCount(string num) {
      vector<int> sd(10, 0);
      for (int i = 0; i < num.size(); ++i) {
        sd[i] = num[i] - '0';
      } 
      for (int i = 0; i < num.size(); ++i) {
        sd[num[i] - '0'] -= 1; 
      }
      for (int i = 0; i < num.size(); ++i) {
        if (sd[i]) { return false; }
      }
      return true;
    }
};
