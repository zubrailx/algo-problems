// when k == 1 just init first element of ann array in range(1, n + 1)
// else if k > 1 then last elements are already inited and it's only need
// to init previous elements and etc until k == k_data
class Solution {
  int cs;
public:
    vector<vector<int>> combine(int n, int k) {
      cs = k;
      return recursion(n, k);
    }
  
  vector<vector<int>> recursion(int n, int k) {
    if (k == 1) { 
      vector<vector<int>> v(n, vector<int>(cs));
      for (int i = 0; i < n; ++i) {
        v[i][0] = i + 1;
      }
      return v;
    }  
    
    vector<vector<int>> subc;
    for (int i = k; i < n + 1; ++i) {
      auto subsubc = recursion(i - 1, k - 1);
      for (int j = 0; j < subsubc.size(); ++j) {
        subsubc[j][k - 1] = i;
        subc.push_back(subsubc[j]);
      }
    }
    return subc;
  }
};
