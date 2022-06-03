class Solution {
public:
  vector<string> letterCasePermutation(string s) {
    vector<string> result;
    backtracking(result, s, 0);
    return result;
  }

private:
  void backtracking(vector<string> &result, string &current, int idx) {
    if (idx >= current.size()) {
      result.push_back(current);
      return;
    }
    // don't change case of current
    backtracking(result, current, idx + 1);
    // change case of current
    if (isalpha(current[idx])) {
      if (isupper(current[idx])) {
        current[idx] = tolower(current[idx]);
        backtracking(result, current, idx + 1);
      } else {
        current[idx] = toupper(current[idx]);
        backtracking(result, current, idx + 1);
      }
    }
  }
};
