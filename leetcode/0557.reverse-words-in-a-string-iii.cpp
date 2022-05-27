class Solution {
public:
    string reverseWords(string s) {
      int ws = 0;
      int i = 0;
      while (i < s.size()) {
        // move pointer to the first non asci character
        while (i < s.size() && tolower(s[i]) != ' ') {
          ++i;
        }
        if (i - ws > 1) {
          for (int j = 0; j < (i - ws) / 2; ++j) {
            swap(s[ws + j], s[i - 1 - j]);
          }
        }
        // move pointer to the word and change ws
        ++i;
        ws = i;
      }
      return s;
    }
};
