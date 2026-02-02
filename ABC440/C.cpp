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
  int t;
  cin >> t;
  // 1≤i≤N を満たす整数 i のうち、 (i+x) を 2W で割った余りが W より小さくなるもの全てに対し、マス i を黒く塗る。
  // = 長さ2Wの円環として見なす。x→0≤x≤2wとした場合の、それぞれの位置iからi + xのコストを求めて、最小のコストを探す。
  while (t--) {
    int n, w;
    cin >> n >> w;
    vector<long long> c(w * 2);
    for (int i = 0; i < n; i++) {
      long long a;
      cin >> a;
      // 位置i(w * 2周期)のコストを代入
      c[i % (w * 2)] += a;
    }
    //　末尾を先頭をまたぐケースをカバーするために、長さ2倍にして円環を直線化する
    for (int i = 0; i < w * 2; i++) {
      c.push_back(c[i]);
    }
    //　コストの累積和
    vector<long long> s(w * 4 + 1);
    s[0] = 0;
    for (int i = 1; i <= w * 4; i++) {
      s[i] = s[i - 1] + c[i - 1];
    }
    long long ans = (long long)1e18;
    // コストの最小値を求める
    for (int i = 0; i < w * 2; i++) {
      ans = min(ans, s[i + w] - s[i]);
    }
    cout << ans << '\n';
  } 
  return 0;
}
