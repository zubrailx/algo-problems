class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& l1, vector<vector<int>>& l2) {
    vector<vector<int>> result;
    if (l2.empty()) swap(l1, l2);
    int i = 0, js = 0, j = 0;
    while (i < l1.size()) {
      while (js < l2.size() && l2[js][1] < l1[i][0]) ++js;
      if (js == l2.size()) break;
      j = js;
      while (j < l2.size() && l2[j][1] >= l1[i][0] && l2[j][0] <= l1[i][1]) {
        result.push_back({max(l1[i][0], l2[j][0]), min(l1[i][1], l2[j][1])});
        ++j;
      }
      ++i;
    }
    return result;
  }
};
