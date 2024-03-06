#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll t, n;
vll P;

ll ans;
vb selected;
ll sx, sy;
void solve(ll b, ll s) {
  if (n / 2 == s) {
    sx = 0;
    sy = 0;

    for (auto i = 0; i < n; ++i) {
      if (selected[i]) {
        sx -= P[i].first;
        sy -= P[i].second;
      } else {
        sx += P[i].first;
        sy += P[i].second;
      }
    }

    const auto& nowsum = sx * sx + sy * sy;
    ans = min(ans, nowsum);
    return;
  }

  for (auto i = b; i < n; ++i) {
    selected[i] = true;
    solve(i + 1, s + 1);
    selected[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> t;
  while (0 < (t--)) {
    cin >> n;

    P = vll(n);
    for (auto&& [x, y] : P) {
      cin >> x >> y;
    }

    ans = numeric_limits<ll>::max();
    selected = vb(n, false);
    solve(0, 0);

    cout << fixed << setprecision(12) << sqrt(ans) << '\n';
  }

  return 0;
}