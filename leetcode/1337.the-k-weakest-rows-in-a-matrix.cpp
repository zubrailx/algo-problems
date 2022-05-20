#include <algorithm>
#include <queue>
#include <utility>


int calculateNumberOfSoldiers(vector<int> &line) {
  int start = -1;
  int end = line.size();
  int index;
  while (start != end - 1) {
    index = start + (end - start) / 2;
    if (line[index]) {
      start = index;
    } else {
      end = index;
    }
  }
  return end;
}

auto comp = [](const pair<int,int> &lsv, const pair<int, int> &rsv) -> bool {
  if (lsv.first == rsv.first) {
    return lsv.second > rsv.second;
  }
  return lsv.first > rsv.first;
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> queue(comp);
      for (int i = 0; i < mat.size(); ++i) {
        queue.emplace(calculateNumberOfSoldiers(mat[i]), i);
      }
      vector<int> result;
      while (k--) {
        result.push_back(queue.top().second);
        queue.pop();
      }
      return result;
    }
};

