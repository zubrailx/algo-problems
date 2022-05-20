#include <iostream>
#include <map>
#include <string>
#include <sstream>


struct Dir {
  std::map<std::string, Dir*> subdir;
};

Dir* dir_add(Dir *dir, const std::string &name) {
  if (dir->subdir.find(name) == dir->subdir.end()) {
    dir->subdir[name] = new Dir();
  }
  return dir->subdir[name];
}

void dir_print(Dir *dir, int depth) {
  for (auto &d : dir->subdir) {
    for (int i = 0; i < depth; ++i){
      std::cout << " ";
    }
    std::cout << d.first << std::endl;
    dir_print(d.second, depth + 1);
  }
}

int main() {
  Dir *root = new Dir();
  int n;
  std::cin >> n;
  while (n--) {
    std::string line, str_dir;
    std::cin >> line;
    Dir *cur_dir = root;
    std::stringstream ss(line);
    while(std::getline(ss, str_dir, '\\')) {
      cur_dir = dir_add(cur_dir, str_dir);
    }
  }
  dir_print(root, 0);
}
