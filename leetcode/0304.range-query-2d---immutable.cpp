class NumMatrix {
public:
  int m_m, m_n;
  vector<vector<int>> m_cum;
  
  NumMatrix(vector<vector<int>>& matrix) {
    m_m = matrix.size();
    m_n = matrix[0].size();
    m_cum.resize(m_m + 1, vector<int>(m_n + 1, 0));
    // can be used matrix of size (m_m + 1) x (m_n + 1) instead of checks
    for (int i = 0; i < m_m; ++i) {
      for (int j = 0; j < m_n; ++j) {
        m_cum[i + 1][j + 1] = m_cum[i][j + 1] + m_cum[i + 1][j] - m_cum[i][j] + matrix[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return m_cum[row2 + 1][col2 + 1] - m_cum[row1][col2 + 1] - m_cum[row2 + 1][col1] + m_cum[row1][col1] ;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
