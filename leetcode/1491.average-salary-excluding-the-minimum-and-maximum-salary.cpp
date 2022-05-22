// in case of overflow

class Solution {
public:
    double average(vector<int>& salary) {
      int size = salary.size() - 2;
      double mn = 1 << 30;
      double mx = -1;
      double result = 0.;
      for (auto s : salary) {
        result += (double)s / size;
        cout << result << endl;
        if (mn > s) {
          mn = s;
        }
        if (mx < s) {
          mx = s;
        }
      }
      return result - mn/size - mx/size;
    }
};
