class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> result;
      if (s.size() < p.size()) { return result; } 
      int arr[26] = {0};
      for (auto e : s) ++arr[e - 'a'];
      for (int i = 0; i < p.size() - 1; ++i) {
        --arr[s[i] - 'a'];
      }
      for (int i = p.size() - 1; i < s.size(); ++i) {
        --arr[s[i] - 'a'];
        bool good = true;
        for (auto e : arr) {
          if (e) { 
            good = false;
            break;
          }
        }
        if (good) result.push_back(i);
        ++arr[s[i - p.size() + 1] - 'a'];
      }
      return result;
    }
};
