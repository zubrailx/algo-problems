class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> one_back(1, 1);
      vector<int> current;
      for (int i = 1; i <= rowIndex; ++i) {
        current.resize(i + 1);
        current[0] = 1, current[i] = 1;
        for (int j = 1; j < i; ++j) {
          current[j] = one_back[j - 1] + one_back[j];
        }
        one_back = current;
      }
      return one_back;
    }
};
