#include <iostream>

int main() {
  int m;
  std::cin >> m;

  while (m--) {
    int n, k;
    std::cin >> n >> k;
    int t = n / k;
    int l = n % k; // how many teams will have t + 1 persons
    std::cout << ((n - 1) * n / 2) - (t * (t - 1) / 2) * (k - l) - ((t + 1) * t / 2) * l << '\n';
  }
}

