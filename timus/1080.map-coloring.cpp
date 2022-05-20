#include <iostream>
#include <string>

int n;

int matrix[100][100];
int colors[100];

// 0 - red, 1 - blue
void dfs(int i, int c) {
  colors[i] = c;
  for (int j = 0; j < n; ++j) {
    if (matrix[i][j]) {
      if (colors[j] == -1) {
        dfs(j, !c);
      } else if (colors[j] == c) {
        std::cout << -1 << std::endl;
        exit(0);
      }
    }
  }
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int j;
    std::cin >> j;
    while (j) {
      --j;
      matrix[i][j] = 1;
      matrix[j][i] = 1;
      std::cin >> j;
    }
    colors[i] = -1;
  }
  dfs(0, 0);
  for (int i = 0; i < n; ++i) {
    std::cout << colors[i];
  }
  std::cout << std::endl;
}
