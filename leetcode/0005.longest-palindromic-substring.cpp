class Solution {
public:
    string longestSubstring(string &s, int idx) {
      int left = idx, right = idx;
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left; ++right;
      }
      string sstr = s.substr(left + 1, right - left - 1);
      left = idx - 1, right = idx;
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left; ++right;
      }
      if (sstr.size() < right - left - 1) {
        sstr = s.substr(left + 1, right - left - 1);
      }
      return sstr;
    }

    string longestPalindrome(string s) {
      string mxsstr = s.substr(0, 1);
      string csstr;
      for (int i = 1; i < s.size(); ++i) {
        csstr = longestSubstring(s, i);
        if (csstr.size() > mxsstr.size()) mxsstr = csstr;
      }
      return mxsstr;
    }
};
