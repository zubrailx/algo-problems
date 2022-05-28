int wcount(string &str) {
  int sp = 0;
  for (auto c : str) {
    if (c == ' ') {
      ++sp;
    }
  }
  return sp + 1;
}

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
      map<string, int> sc;
      for (int i = 0; i < messages.size(); ++i) {
        sc[senders[i]] += wcount(messages[i]);
      }
      string ms = sc.begin()->first;
      int cnt = sc.begin()->second;
      for (auto it = sc.begin(); it != sc.end(); ++it) {
        if(it->second >= cnt) {
          cnt = it->second;
          ms = it->first;
        }
      }
      return ms;
    }
};

