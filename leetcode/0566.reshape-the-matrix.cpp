class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
      int mr = mat.size(), mc = mat[0].size();
      if (mr * mc != r * c) { return mat; }
      vector<vector<int>> result(r, vector<int>(c));
      
      for (int i = 0; i < mr; ++i) {
        for (int j = 0; j < mc; ++j) {
          int fl = i * mc + j;
          result[fl / c][fl % c] = mat[i][j];
        }
      }
      
      return result;
    }
};
