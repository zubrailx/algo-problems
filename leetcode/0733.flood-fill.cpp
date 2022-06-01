class Solution {
  int m, n;
  int init_color, new_color;
public:
    void update_neighbour(pair<int, int> p, queue<pair<int, int>> &dq, vector<vector<int>> &image) {
        if (p.first >= 0 && p.first < m && p.second >= 0 && p.second < n 
            && image[p.first][p.second] == init_color) {
          dq.push(make_pair(p.first, p.second));
          image[p.first][p.second] = new_color;
        }
    }
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      if (image[sr][sc] == newColor) { return image; }
      
      queue<pair<int, int>> dq;
      m = image.size();
      n = image[0].size();
      
      dq.push(make_pair(sr, sc));
      init_color = image[sr][sc];
      new_color = newColor;
      image[sr][sc] = newColor;
      
      while (!dq.empty()) {
        auto p = dq.front();
        dq.pop();
        // for each neignbour
        update_neighbour(make_pair(p.first - 1, p.second), dq, image);
        update_neighbour(make_pair(p.first, p.second + 1), dq, image);
        update_neighbour(make_pair(p.first + 1, p.second), dq, image);
        update_neighbour(make_pair(p.first, p.second - 1), dq, image);
      }
      return image;
    }
};


// can be solved with recursion check(fill) -> execute for each neighbor
