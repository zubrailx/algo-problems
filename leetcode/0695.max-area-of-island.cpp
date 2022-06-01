class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int max_area = 0;
      for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
          max_area = max(check_area(grid, i, j), max_area);
        }
      }
      return max_area;
    }
  
    int check_area(vector<vector<int>> &grid, int i, int j) {
      if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) return 0;
      
      grid[i][j] = 0;
      int size = 1;
      size += check_area(grid, i + 1, j);
      size += check_area(grid, i - 1, j);
      size += check_area(grid, i, j + 1);
      size += check_area(grid, i, j - 1);
      return size;
    }
};
