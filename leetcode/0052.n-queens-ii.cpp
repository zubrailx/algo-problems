// found interesting solution using 3 arrays

class Solution {
public:
  int totalNQueens(int n) {
    vector<vector<int>> field(n, vector<int>(n, 0));
    int result = 0;
    backtracking(&result, field, 0);
    return result;
  }
  
  void backtracking(int *result, vector<vector<int>> &field, int row) {
    int n = field.size();
    if (row == n) {
      ++(*result);
      return;
    }   
    
    for (int j = 0; j < n; ++j) {
      if (field[row][j] == 0) {
        field[row][j] = -1; 
        increase_queen_front(field, row, j, 1);  
        backtracking(result, field, row + 1);
        increase_queen_front(field, row, j, -1);
        field[row][j] = 0;
      }
    }
  }
  
  void increase_queen_front(vector<vector<int>> &field, int row, int col, int val) {
    for (int i = row + 1, l = 1; i < field.size(); ++i, ++l) {
      field[i][col] += val;
      if (col + l < field.size()) {
        field[i][col + l] += val;
      }
      if (col - l >= 0) {
        field[i][col - l] += val;
      }
    }
  }
};
