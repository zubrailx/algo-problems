// solution I
bool is_substring_palindrome(string &s, int start, int end) {
  while (start < end) {
    if (s[start++] != s[end-- - 1]) return false;
  }
  return true;
}

class Solution {
public:
  int countSubstrings(string s) {
    int counter = 0;
    for (int l = 1; l <= s.length(); ++l) {
      for (int i = 0; i <= s.length() - l; ++i) {
        counter += (int) is_substring_palindrome(s, i, i + l);
      }
    }
    return counter;
  }
};


// solution II (expand around center)


// solution III (Manacher's algorithm)
