class Solution {
public:
  bool backspaceCompare(string s, string t) {
    int n = s.size();
    int m = t.size();
    int skip1 = 0;
    int skip2 = 0;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
      while (i >= 0 && s[i] == '#') { ++skip1; --i; }
      while (j >= 0 && t[j] == '#') { ++skip2; --j; }

      if (skip1 == 0 && skip2 == 0) {
        if (s[i] != t[j]) { return false; }
        --i; --j;
      }
      if (skip1) { --i; --skip1; }
      if (skip2) { --j; --skip2; }
    }
    if (j >= 0) {
      s = t;
      i = j;
      skip1 = skip2;
    }
    while (i >= 0) {
      while (i >= 0 && s[i] == '#') { ++skip1; --i; }
      if (skip1 == 0) { return false; }
      else { --i; --skip1; }
    }
    return true;
  }
};
