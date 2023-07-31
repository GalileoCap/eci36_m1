#include <utility>
#include <iostream>
#include <vector>

struct Bolt {
  int _width;
};

struct Nut {
  int _width;
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

std::vector<int> solve(int n, std::vector<struct Bolt> &bolts, std::vector<struct Nut> &nuts) {
  std::vector<int> res;
  res.reserve(n);

  for (const auto& bolt : bolts) {
    for (int i = 0; i < n; i++) {
      struct Nut &nut = nuts[i];
      if (!nut.used && match(bolt, nut) == Fits) {
        nut.used = true;
        res.push_back(i);
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
      bolts.push_back(Bolt{x});
    }

    // Read nuts
    std::vector<struct Nut> nuts;
    for (int i = 0, x; i < n; i++) {
      std::cin >> x;
      nuts.push_back(Nut{x, false});
    }

    std::vector<int> res = solve(n, bolts, nuts);

    // Report result
    for (int idx : res)
      std::cout << idx << " ";
    std::cout << std::endl;
  }
}
