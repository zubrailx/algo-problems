class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
      vector<pair<int,int>> vxs(n);
      for (int i = 0; i < n; ++i) {
        vxs[i].first = i;
        vxs[i].second = 0;
      }
      for (const auto &p : roads) {
        ++vxs[p[0]].second; ++vxs[p[1]].second;
      }
      // sort vector of pairs
      sort(vxs.begin(), vxs.end(), [](const pair<int, int> &lsv, const pair<int, int> &rsv) {
        return lsv.second > rsv.second;
      });
      vector<int> vp(n, 0);
      int cnt = n;
      for (int i = 0; i < n; ++i) {
        vp[vxs[i].first] = cnt--;
      }
      long long result = 0;
      for (const auto &p : roads) {
        result += vp[p[0]] + vp[p[1]];
      }
      return result;
    }
};

