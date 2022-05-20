#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>


typedef std::pair<int, int> PII;


int main() {
  PII black_points[60001];
  int by_rows = 0, by_columns = 0, by_separated = 0;
  std::vector<PII> solo_whites;

  int rows, columns, k;
  std::cin >> rows >> columns >> k;

  for (int i = 0; i < k; ++i) {
    int x, y;
    std::cin >> x >> y;
    black_points[i] = std::make_pair(x - 1, y - 1);
  }


  auto cmp_rows = [](const PII a, const PII b){
    if (a.first != b.first) {
      return a.first < b.first;
    }
    return a.second < b.second;
  };

  auto cmp_cols = [](PII a, PII b) {
    if (a.second != b.second) {
      return a.second < b.second;
    }
    return a.first < b.first;
  };


  // sort points by row
  // for each row find vectors and count them (if length of vector is > 1)
  // + calculate solo points
  // will read every line, cuz i can't get more optimal algorithm right now
  std::sort(black_points, black_points + k, cmp_rows);

  PII pprev = std::make_pair(0,-1);
  black_points[k] = std::make_pair(rows - 1, columns);
  for (int i = 0; i < k + 1; ++i) {
    PII p = black_points[i];
    if (p.first > pprev.first) {
      if (columns > 1) by_rows += (p.first - pprev.first - 1);
      int diff = columns - pprev.second;
      if (diff == 2) {
        solo_whites.emplace_back(pprev.first, pprev.second + 1);
      } else if (diff > 2) {
        by_rows += 1;
      }
      pprev = std::make_pair(p.first, -1);
    }
    int diff = p.second - pprev.second;
    if (diff == 2) {
      solo_whites.emplace_back(p.first, p.second - 1);
    } else if (diff > 2) {
      by_rows += 1;
    }
    pprev = p;
  }
  // sort point by column
  // for each column find vectors and count them (-||-)
  // + calculate solo points
  std::sort(black_points, black_points + k, cmp_cols);

  pprev = std::make_pair(-1,0);
  black_points[k] = std::make_pair(rows, columns - 1);
  for (int i = 0; i < k + 1; ++i) {
    PII p = black_points[i];
    if (p.second > pprev.second) {
      if (rows > 1) by_columns += (p.second- pprev.second - 1);
      int diff = rows - pprev.first;
      if (diff == 2) {
        solo_whites.emplace_back(pprev.first + 1, pprev.second);
      } else if (diff > 2) {
        by_columns += 1;
      }
      pprev = std::make_pair(-1, p.second);
    }
    int diff = p.first- pprev.first;
    if (diff == 2) {
      solo_whites.emplace_back(p.first - 1, p.second);
    } else if (diff > 2) {
      by_columns += 1;
    }
    pprev = p;
  }
  std::sort(solo_whites.begin(), solo_whites.end());
  by_separated = solo_whites.end() - std::unique(solo_whites.begin(), solo_whites.end());
  // find result
  std::cout << by_columns + by_rows + by_separated << std::endl;
}

