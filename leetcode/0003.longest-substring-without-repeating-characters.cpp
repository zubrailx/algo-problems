// sliding window

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    // ok, let's use hashset
    unordered_set<int> bits;
    int result = 0;
    int start = 0;
    
    for (int i = 0; i < s.size(); ++i) {
      if (bits.find(s[i]) != bits.end()) {
        // check result
        result = result > (i - start) ? result : (i - start);
        // try to move pointer up to the current i
        while (bits.find(s[i]) != bits.end()) {
          bits.erase(s[start++]);
        }
      }
      bits.insert(s[i]);
    }
    return result > (s.size() - start) ? result : (s.size() - start);
  }
};

// also can store chars with it's indexes to move window much faster (not only on 1)

