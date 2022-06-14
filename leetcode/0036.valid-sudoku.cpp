// a little bit stupid solution =)
class Solution {
public:
    bool check_square(vector<vector<char>>& board, int r, int c) {
      int ro = (r / 3) * 3, co = (c / 3) * 3;
      int arr[9] = {0};
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          int e = board[ro + i][co + j];
          if (e >= '1' && e <= '9')
            if (arr[e - '1']++) { return false; }
        }
      }
      return true;
    }

    bool check_row(vector<vector<char>>& board, int r) {
      int arr[9] = {0};
      for (int i = 0; i < 9; ++i) {
        int e = board[r][i];
        if (e >= '1' && e <= '9')
          if (arr[e - '1']++) { return false; }
      }
      return true;
    }

    bool check_column(vector<vector<char>>& board, int c) {
      int arr[9] = {0};
      for (int i = 0; i < 9; ++i) {
        int e = board[i][c];
        if (e >= '1' && e <= '9')
          if (arr[e - '1']++) { return false; }
      }
      return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
          if (board[i][j] != '.') {
            if (!(check_square(board, i, j) && check_row(board, i) && check_column(board, j))) {
              return false;
            }
          }
        }
      }
      return true;
    }
};

