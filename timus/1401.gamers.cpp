#include <iostream>
#include <cmath>

// current number of piece
int current = 0;
int act_size;

void print_array(int *arr, int n, int start_x, int start_y) {
  for (int i = start_x; i < start_x + n; ++i) {
    for (int j = start_y; j < start_y + n; ++j) {
      std::cout << arr[i * act_size + j] << '\t';
    }
    std::cout << '\n';
  }
}
// arr - array[n][n]
// zero_x - normal coordinate of x (starts with 0)
// zero_y - normal coordinate of y (starts with 0)
// start_x, start_y - top_left coordinate of subarray
void calculate(int *arr, int n, int zero_x, int zero_y, int start_x, int start_y){
  // increment current
  ++current;
  // calculate matrix 2*2
  if (n == 2) {
    // top left
    if (zero_x == start_x && zero_y == start_y) {
      arr[(start_x + 1) * act_size + (start_y    )]    = current; 
      arr[(start_x + 1) * act_size + (start_y + 1)]    = current;
      arr[(start_x    ) * act_size + (start_y + 1)]    = current; 
    // top right
    } else if (zero_x == start_x && zero_y == start_y + 1) {
      arr[(start_x    ) * act_size + (start_y    )]     = current; 
      arr[(start_x + 1) * act_size + (start_y    )]     = current; 
      arr[(start_x + 1) * act_size + (start_y + 1)]     = current; 
    // bottom left
    } else if (zero_x == start_x + 1 && zero_y == start_y) {
      arr[(start_x    ) * act_size + (start_y    )]     = current; 
      arr[(start_x    ) * act_size + (start_y + 1)]     = current; 
      arr[(start_x + 1) * act_size + (start_y + 1)]     = current; 
    // bottom right
    } else if (zero_x == start_x + 1 && zero_y == start_y + 1) {
      arr[(start_x    ) * act_size + (start_y    )]     = current; 
      arr[(start_x    ) * act_size + (start_y + 1)]     = current; 
      arr[(start_x + 1) * act_size + (start_y    )]     = current; 
    }
    return;
  }

  int half = n / 2;
  // 1 2
  // 3 4
  // if 0 in 1
  if (zero_x < half + start_x && zero_y < half + start_y) {
    arr[(start_x + half - 1) * act_size + (start_y + half    )]     = current;
    arr[(start_x + half    ) * act_size + (start_y + half - 1)]     = current; 
    arr[(start_x + half    ) * act_size + (start_y + half    )]     = current; 
    calculate(arr, half, (zero_x            ), (zero_y            ), start_x       , start_y);
    calculate(arr, half, (start_x + half - 1), (start_y + half    ), start_x       , start_y + half);
    calculate(arr, half, (start_x + half    ), (start_y + half - 1), start_x + half, start_y);
    calculate(arr, half, (start_x + half    ), (start_y + half    ), start_x + half, start_y + half);
  // if 0 in 2
  } else if (zero_x < half + start_x && zero_y >= half + start_y) {
    arr[(start_x + half - 1) * act_size + (start_y + half - 1)]     = current;
    arr[(start_x + half    ) * act_size + (start_y + half - 1)]     = current; 
    arr[(start_x + half    ) * act_size + (start_y + half    )]     = current; 
    calculate(arr, half, (zero_x            ), (zero_y            ), start_x       , start_y + half);
    calculate(arr, half, (start_x + half - 1), (start_y + half - 1), start_x       , start_y);
    calculate(arr, half, (start_x + half    ), (start_y + half - 1), start_x + half, start_y);
    calculate(arr, half, (start_x + half    ), (start_y + half    ), start_x + half, start_y + half);
  // if 0 in 3
  } else if (zero_x >= half + start_x && zero_y < half + start_y) {
    arr[(start_x + half - 1) * act_size + (start_y + half - 1)]     = current;
    arr[(start_x + half - 1) * act_size + (start_y + half    )]     = current; 
    arr[(start_x + half    ) * act_size + (start_y + half    )]     = current; 
    calculate(arr, half, (zero_x            ), (zero_y            ), start_x + half, start_y);
    calculate(arr, half, (start_x + half - 1), (start_y + half - 1), start_x       , start_y);
    calculate(arr, half, (start_x + half - 1), (start_y + half    ), start_x       , start_y + half);
    calculate(arr, half, (start_x + half    ), (start_y + half    ), start_x + half, start_y + half);
  // if 0 in 4
  } else if (zero_x >= half + start_x && zero_y >= half + start_y) {
    arr[(start_x + half - 1) * act_size + (start_y + half - 1)]     = current;
    arr[(start_x + half - 1) * act_size + (start_y + half    )]     = current; 
    arr[(start_x + half    ) * act_size + (start_y + half - 1)]     = current; 
    calculate(arr, half, (zero_x            ), (zero_y            ), start_x + half, start_y + half);
    calculate(arr, half, (start_x + half - 1), (start_y + half - 1), start_x       , start_y);
    calculate(arr, half, (start_x + half - 1), (start_y + half    ), start_x       , start_y + half);
    calculate(arr, half, (start_x + half    ), (start_y + half - 1), start_x + half, start_y);
  }
}


int main() {
  int n;
  // x - row, y - column
  int x, y;
  std::cin >> n >> x >> y;
  // convert to normal
  --x; --y;
  n = (int)pow(2, n);
  act_size = n;

  int arr[n][n];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n ; ++j) {
      arr[i][j] = -1;
    }
  }
  arr[x][y] = 0;
  calculate(&arr[0][0], n, x, y, 0, 0);
  print_array(&arr[0][0], n, 0, 0);
}

