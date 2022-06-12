class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n = matrix.size();
      int m = matrix[0].size();
      int s = 0, e = n * m - 1, i, num;
      while (s <= e) {
        i = s + (e - s) / 2;
        num = matrix[i / m][i % m];
        if (num > target) {
          e = i - 1;
        } else if (num < target) {
          s = i + 1;
        } else {
          return true;
        }
      }
      return false;
    }
};
