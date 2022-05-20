#include <iostream>
#include <cmath>
#include <algorithm>


using namespace std;

struct Point {
  int x;
  int y;
  int n;
  /*double rad;*/
};

struct {
  bool operator()(Point a, Point b) const {
    // если углы одинаковые (векторное произведение == 0) и 
    // смотрят в одну сторону (скалярное произведение > 0)
    if (a.x * b.y - a.y * b.x == 0 && a.x * b.x + a.y * b.y >= 0) {
      // возвращаем меньший вектор
      return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
    // иначе возвращаем тот, угол которого меньше 
    } else {
      return atan2(a.y, a.x) < atan2(b.y, b.x);
    }
  }
} comparator;

int main() {
  Point arr[30000];
  int n;
  cin >> n;
  // read the first point
  cin >> arr[0].x >> arr[0].y;
  arr[0].n = 1;
  // read rest points with relative coordinates
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    arr[i].x = x - arr[0].x;
    arr[i].y = y - arr[0].y;
    arr[i].n = i + 1;
  }
  /*for (int i = 0; i < n; ++i) {
      arr[i].rad = atan2(arr[i].y, arr[i].x);
  }*/
  // sort point by angle
  sort(arr + 1, arr + n, comparator);

  // если векторное произведение со следующим отрицательное, например,
  // как для случая точек (0,0) (-1,1) (-1,) (-1,-1), то необходимо начинать
  // с той точки, для которой не будет какого, что следующий вектор будет 
  // находиться более чем на 180 градусов
  int start = 0;
  for (int i = 1; i < n - 1; ++i) {
    Point a = arr[i];
    Point b = arr[i + 1];
    // или угол между векторами > 180 градусов (левая тройка) или
    // угол между векторами = 180 градусов (скалярное произведение отрицательное, векторное равно 0)
    if (a.x * b.y - a.y * b.x < 0 || (a.x * b.y - a.y * b.x == 0 && a.x * b.x + a.y * b.y < 0)) {
      // previous element before one that should be printed first (cuz if zero than should start with 1) 
      start = i;
      break;
    }
  }

  cout << n << endl << 1 << endl;
  // выводим начиная с s и по циклу 
  for (int i = 0; i < n - 1; ++i) {
    cout << arr[(start + i) % (n - 1) + 1].n << endl;
  }
  return 0;
}

