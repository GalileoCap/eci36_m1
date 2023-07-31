#include <utility>
#include <iostream>
#include <vector>
#include <map>

struct Bolt {
  int _width;
  int idx; // Index within the vector
};

struct Nut {
  int _width;
  int idx; // Index within the vector
  bool used;
};

enum Match {
  Small = -1,
  Fits = 0,
  Large = 1,
};

enum Match match(const struct Bolt &bolt, const struct Nut &nut) {
  if (bolt._width < nut._width)
    return Small;
  else if (bolt._width == nut._width)
    return Fits;
  else return Large;
}

std::map<int, int> solve(int n, std::vector<struct Bolt> &bolts, std::vector<struct Nut> &nuts) {
  std::map<int, int> res;

  for (const auto& bolt : bolts) {
    for (struct Nut &nut : nuts) {
      if (!nut.used && match(bolt, nut) == Fits) {
        nut.used = true;
        res[bolt.idx] = nut.idx;
        break;
      }
    }
  }

  return std::move(res);
}

int main() {
  int n; // Number of bolts and nuts
  while (std::cin >> n) {
    // Read bolts
    std::vector<struct Bolt> bolts;
    bolts.reserve(n);
    for (int i = 0, x; i < n; i++) {
      std::cin >> x;
      bolts.push_back(Bolt{x, i});
    }

    // Read nuts
    std::vector<struct Nut> nuts;
    for (int i = 0, x; i < n; i++) {
      std::cin >> x;
      nuts.push_back(Nut{x, i, false});
    }

    std::map<int, int> res = solve(n, bolts, nuts);

    // Report result
    for (int i = 0; i < n; i++)
      std::cout << res[i] << " ";
    std::cout << std::endl;
  }
}
