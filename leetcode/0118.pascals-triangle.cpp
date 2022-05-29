class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<int> first(1, 1);
      
      vector<vector<int>> triangle;
      triangle.push_back(first);
        
      vector<int> second;
      for (int i = 2; i <= numRows; ++i) {
        second.resize(i);
        second[0] = first[0];
        second[i - 1] = first[i - 2];
        for (int j = 1; j < i - 1; ++j) {
          second[j] = first[j - 1] + first[j];
        }
        first = second;
        triangle.push_back(first);
      }
      return triangle;
    }
};
