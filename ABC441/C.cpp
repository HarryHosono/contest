#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  long long x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  // 昇順にソート
  sort(a.begin(), a.end());
  
  // 最悪のケースは小さいカップからK個に日本酒が入っている場合。
  // 高橋君は大きい順から選んだほうがよき。降順でM個選ぶとする。
  // 選ばれなかったカップ(n - M)。
  // n - k個までは水だとすると、そこから1個ずつ引いていくと日本酒が確定していく
  for (int i = k - 1; i >= 0; i--) {
    x -= a[i];
    
    // 飲むべき日本酒の量が0いかになった場合、出力するカップの個数はn - i (0 <= i <= k - 1)
    if (x <= 0) {
      cout << n - i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
