class Solution {
public:
    bool isValid(string s) {
      stack<char> q;
      char prev;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') { q.push(s[i]); }
        else {
          if (!q.empty()) { prev = q.top(); } 
          else { return false; }

          if (prev == '(' && s[i] == ')' || prev == '[' && s[i] == ']' || prev == '{' && s[i] == '}') {
            q.pop();
          } else { return false; }
        }
      }
      return q.empty();
    }
};
