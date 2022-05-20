#include <map>
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <map>

std::vector<std::string> get_key_and_values(std::string& str)
{
	std::vector<std::string> v;
	std::size_t prev_pos = 0, pos;
	while ((pos = str.find_first_of(" -,", prev_pos)) != std::string::npos) {
		if (pos > prev_pos) {
			v.push_back(str.substr(prev_pos, pos - prev_pos));
		}
		prev_pos = pos + 1;
	}
	if (prev_pos < str.length()) {
		v.push_back(str.substr(prev_pos, std::string::npos)); //read till the end of the string.
	}
	return v;
}

void print_map(std::map<std::string, std::set<std::string>> mp) {
	std::cout << mp.size() << '\n';
	for (auto element : mp) {
		std::cout << element.first << " - ";
		size_t count = 0;
		for (auto set_v : element.second) {
			if (++count < element.second.size()) {
				std::cout << set_v << ", ";
			}
			else {
				std::cout << set_v << std::endl;
			}
		}
	}
}


int main() {
	std::map<std::string, std::set<std::string>> mp_2;

	int n;				
	std::cin >> n;
	std::cin.ignore(1, '\n');
	for (int i = 0; i < n; ++i) { //set the words and keys in the map.
		std::string s;

		std::getline(std::cin, s);
		std::vector<std::string> v_s = get_key_and_values(s);

		std::string key = v_s[0]; //english - latin dict.
		v_s.erase(v_s.begin());

		for (auto element : v_s) {
			if (mp_2.find(element) == mp_2.end()) {
				std::set<std::string> values;
				values.insert(key);
				mp_2[element] = values;
			}
			else {
				mp_2[element].insert(key);
			}
		}
	}
	print_map(mp_2);
}