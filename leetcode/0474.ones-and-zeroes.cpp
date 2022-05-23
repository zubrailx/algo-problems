// top-bottom dynamic programming
int dp[600][101][101] = {};
    

int resolve(vector<pair<int, int>> &vect, int zeroes, int ones, int idx) {
  if (zeroes == 0 && ones == 0 || idx == vect.size()) return 0;
  if (dp[idx][zeroes][ones] != -1) {return dp[idx][zeroes][ones]; }
  
  // exclude
  dp[idx][zeroes][ones] = resolve(vect, zeroes, ones, idx + 1);
  
  int z = vect[idx].first;
  int o = vect[idx].second;
  if (zeroes >= z && ones >= o) {
    dp[idx][zeroes][ones] = max(dp[idx][zeroes][ones], 1 + resolve(vect, zeroes - z, ones - o, idx + 1));
  }
  return dp[idx][zeroes][ones];
}


class Solution {
public:
  int findMaxForm(vector<string>& strs, int zeroes, int ones){
    memset(dp, -1, sizeof(dp));
    vector<pair<int, int>> vect(strs.size());
    int z;
    for (int i = 0; i < strs.size(); ++i) {
      z = count(strs[i].begin(), strs[i].end(), '0');
      vect[i] = make_pair(z, strs[i].size() - z);
    }
    return resolve(vect, zeroes, ones, 0);
  }
};
 
