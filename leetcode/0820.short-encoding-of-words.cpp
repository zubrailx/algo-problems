class Solution {
public:
  struct Trie {
    // can't use unordered_map because type is incomplete
    map<char, Trie> children;
  };

  int recursive(Trie &root, int depth) {
    if (root.children.empty()) {
      return depth + 1;
    } else {
      int sm = 0;
      for (auto & it : root.children) {
        sm += recursive(it.second, depth + 1);
      }
      return sm;
    }
  }

  int minimumLengthEncoding(vector<string>& words) {
    Trie root;
    for (auto &word : words) {
      Trie* cur = &root;
      for (int i = word.size() - 1; i >= 0; --i) {
        cur = &cur->children[word[i]];
      }
    }
    return recursive(root, 0);
  }
};
