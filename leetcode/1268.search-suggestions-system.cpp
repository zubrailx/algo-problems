class Solution {
public:
  struct Trie {
    map<char, Trie> children;
  };
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    Trie root;
    for (string &p : products) {
      Trie *cur = &root;
      for (char c : p) {
        cur = &cur->children[c];
      }
      cur->children[0]; // null-termination
    }
    vector<vector<string>> result;
    string buffer;
    // when root is assigned than it can be freed by compilers, that's why using temp
    Trie *temp = &root;
    for (char c : searchWord) {
      temp = &temp->children[c];
      buffer.push_back(c);
      result.push_back(get_words(*temp, buffer, 3));
    }
    return result;
  }

  vector<string> get_words(Trie &root, string buffer, int mxw) {
    vector<string> result;
    recursion(root, result, mxw, buffer);
    return result;
  }

  void recursion(Trie &root, vector<string> &result, int mxw, string &buffer) {
    for (auto &it : root.children) {
      if (result.size() >= mxw) { break; }
      if (it.first == 0) {
        result.push_back(buffer);
      } else {
        buffer.push_back(it.first);
        recursion(it.second, result, mxw, buffer);
        buffer.pop_back();
      }
    }
  }
};
