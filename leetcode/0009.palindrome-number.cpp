// 1
class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) { return false; }
      if (x == 0) { return true; }
      
      vector<int> v(sizeof(int) * 8, 0);
      int end = -1;
      while (x != 0) {
        v[++end] = x % 10;
        x /= 10;
      }
      for (int start = 0; start < end; ++start, --end) {
        if (v[start] != v[end]) { return false; }
      }
      return true;
    }
};

// reverse number

