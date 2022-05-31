class Solution {
public:
    bool hasAllCodes(string s, int k) {
      if (s.size() < k) { return false; }
      
      vector<bool> arr(pow(2, k), 0);
      for (int i = 0; i < s.size() - k + 1; ++i) {
        // substring to binary
        int val = 0;
        for (int j = 0; j < k; ++j) {
          val += (s[i + j] - '0') << (k - 1 - j);
        }
        arr[val] = 1;
      }
      for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) { return false; }
      }
      return true;
    }
};

