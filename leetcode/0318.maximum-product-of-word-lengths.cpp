class Solution {
public:
    int maxProduct(vector<string>& words) {
      int n = words.size();
      vector<int> masks(n, 0);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
          masks[i] |= 1 << (words[i][j] - 'a');
        }
      }
      int max = 0;
      int cur;
      /*
      for (int i = 0; i < n; ++i) {
        cout << bitset<64>(masks[i]) << endl;
      }
      */
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (!(masks[i] & masks[j])) {
          //if ((masks[i] ^ masks[j]) == (masks[i] | masks[j])) {
            cur = words[i].size() * words[j].size();
            if (cur > max) { max = cur; }
          }
        }
      }
      return max;
    }
};
