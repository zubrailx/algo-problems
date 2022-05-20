#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>


using namespace std;

struct Point {
  int x;
  int y;
  int n;
  double rad;
};

double find_rad(int dx, int dy) {
  double rad;
  rad = atan2(dy,dx);
  //rad = acos((double)dx / pow(pow((double)dx, 2) + pow((double)dy, 2), (double)0.5));
  return rad;
}

int main() {
  int n;
  cin >> n;
  vector<Point> arr(n);
  // min by y
  int min_i = -1;
  int min_y = 1000000001;
  // reading 
  for (int i = 0; i < n; ++i) {
    Point p{};
    cin >> p.x >> p.y;
    p.n = i + 1;
    arr[i] = p;
      if (p.y < min_y) {
      min_y = p.y;
      min_i = i;
    }
  }
  // put first point in the beginning of array
  Point t = arr[min_i];
  arr[min_i] = arr[0];
  arr[0] = t;
  // calculate radian
  for (int i = 1; i < n; ++i) {
    arr[i].rad = find_rad(arr[i].x - arr[0].x, arr[i].y - arr[0].y);
  }
  //quick_sort(arr, 1, n - 1);
  sort(arr.begin() + 1, arr.end(), [](Point a, Point b) { 
      return a.rad < b.rad;
  });
  // print
  cout << arr[0].n << " " << arr[n / 2].n;
}

