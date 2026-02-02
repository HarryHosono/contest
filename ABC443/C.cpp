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
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // 次にchokutterを開く時間
  int nxt = 0; 
  int ans = 0;
  for (int i = 0; i < n; i++) {
    // nxtよりも青木さんが後ろを通った時の値が小さい場合→通った時間-開き始めた時間(nxt)が開いていた時間
    if (nxt <= a[i]) {
      ans += a[i] - nxt;
      nxt = a[i] + 100;
    } 
  }
  // t秒までの開いていた時間を考慮する
  if (nxt <= t) {
    ans += t - nxt;
  }
  cout << ans << '\n';
  return 0;
}
