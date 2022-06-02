void print(vector<vector<int>>& grid) {
  for (auto &l : grid) {
    for (auto e : l) {
      cout << e << " ";
    }
    cout << endl;
  }
  cout << endl;
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<int,int>> oq;
      for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
          if (grid[i][j] == 2) {
            oq.emplace(i, j);
          }
        }
      }
      
      int cmo = oq.size();
      int nmo = 0;
      int time = -1;
      int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
      while (cmo != 0) {
        ++time;
        while (cmo-- > 0) {
          auto [r, c] = oq.front(); oq.pop();
          int nr, nc;
          for (int i = 0; i < 4; ++i) {
            nr = dirs[i][0] + r;
            nc = dirs[i][1] + c;
            if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size() || grid[nr][nc] != 1) continue;
            grid[nr][nc] = 2;
            ++nmo;
            oq.emplace(nr, nc);
          }
        }
        cmo = nmo;
        nmo = 0;
      }
      
      for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
          if (grid[i][j] == 1) { return -1; }
        }
      }
      // when only 0 is present then nothing should be 
      return max(time, 0);
    }
};

// P.S. can use oq.size() instead of cmo and nmo (for while current size is not 0 continue)
