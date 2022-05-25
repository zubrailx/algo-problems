*
// broot force
class Solution {
public:
    int longestValidParentheses(string s) {
      int mx = 0;
      int op, cl;
      for (int i = 0; i < s.size(); ++i) {
        op = 0;
        cl = 0;
        for (int j = i; j < s.size(); ++j) {
          if (s[j] == '(') { ++op; }
          else { ++cl; }
          
          if (cl > op) { break; }
          
          if (op == cl && op + cl > mx) {
            mx = op + cl;
          }
        }
      }
      return mx;
    }
};
*/
// (())()
// sol n.2
class Solution {
public:
  int longestValidParentheses(string s) {
    vector<int> v(s.size(), 0);
    
    int mx = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        v[i] = 0;
      } else {
        // check () 
        if (i >= 1 && s[i - 1] == '(') {
          v[i] = 2;
        }
        // check (()) <-
        if (i >= 1 && s[i - 1] == ')' && v[i - 1] != 0) {
          // i == 2, v[i - 1] == 2 -> need to check v[-1] -> i > v[i - 1] + 1
          if (i - 1 - v[i - 1] >= 0 && s[i - 1 - v[i - 1]] == '(') {
            v[i] = v[i - 1] + 2;
          } 
        }
        // merge two arrays like ()()
        // v[i] = 2 -> need to check i - v[i] for v != 0
        if (v[i] && i >= v[i]) {
          v[i] += v[i - v[i]];
        }
        if (v[i] > mx) {
          mx = v[i];
        }
      }
      /*
      for (int j = 0; j < s.size(); ++j) {
        cout << v[j] << " ";
      }
      cout << endl;
      */
    }
    return mx;
  }
};
