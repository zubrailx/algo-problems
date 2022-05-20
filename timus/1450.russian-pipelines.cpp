#include <iostream>
#include <vector>
#include <utility>
#include <deque>

int MIN_VALUE = -2147483648;

struct Vertex {
  // size - out-degree, vector<v_num, edge_weight>
  std::vector<std::pair<int, int>> v_pair;
  int in = 0;
  int dist = MIN_VALUE;
};

Vertex varray[500];
std::deque<Vertex *> zero_in;
int n;
int s, f;


void print_result() {
  if (varray[f].dist < 0) {
    std::cout << "No solution" << std::endl;
  } else {
    std::cout << varray[f].dist << std::endl;
  }
}

void toposort() {
  // adding points with zero in-degree
  for (int i = 0; i < n; ++i) {
    if (varray[i].in == 0) {
      zero_in.push_back(varray + i);
    }
  }
  // set start point value
  varray[s].dist = 0;
  // calculate distances
  while (!zero_in.empty()) {
    auto u = zero_in.front();
    zero_in.pop_front();
    for (size_t i = 0; i < u->v_pair.size(); ++i) {
      auto bc = u->v_pair[i];
      auto v = varray + bc.first;
      v->dist = std::max(v->dist, u->dist + bc.second);
      if (--v->in == 0) {
        zero_in.push_back(v);
      }
    }
  }
}

int main() {
  int m;
  std::cin >> n >> m;

  int a, b, c;
  while (m--) {
    std::cin >> a >> b >> c;
    --a; --b;
    varray[a].v_pair.emplace_back(b, c);
    ++varray[b].in;
  }

  std::cin >> s >> f;
  --s; --f;

  toposort();
  print_result();
}