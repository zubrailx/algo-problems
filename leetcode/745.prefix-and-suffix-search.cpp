lass WordFilter {
  unordered_map<string, int> dict;
public:
    WordFilter(vector<string>& words) {
      for (int w = 0; w < words.size(); ++w) {
        string word = words[w];
        for (int i = 1; i <= word.size(); ++i) {
          string prefix = word.substr(0, i);
          for (int j = 0; j < word.size(); ++j) {
            string suffix = word.substr(j);
            string key = suffix + "#" + prefix;
            dict[key] = w + 1;
          }
        }
      }
    }
    
    int f(string prefix, string suffix) {
      return dict[suffix + "#" + prefix] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
