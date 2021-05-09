// マップやその他の非常に複雑なタプルは使用しないでください。そして、文字列
// で遊ぶとき、それを整数配列に変換します。それは不思議です。パニックになら
// ないでください。それに慣れているときは常に競争をしてください。評価が下がっ
// たときに強調しないでください、それは起こります。だから、冷静ですが重要なコード:)
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t, w;
      cin >> t;
      foi(w,t){
      	lld l, r, m;
      	cin >> l >> r >> m;
      	for(lld i = l; i <= r; i += 1){
      		lld x = m%i;
      		if (x >= 0 && x <= (r-l) && m-x > 0){
      			cout << i << " " << l+x << " " << l << "\n";
      			break;
      		}
      		if (i-x >= 0 && i-x <= (r-l)){
      			cout << i << " " << l << " " << l+(i-x) << "\n";
      			break;
      		}
      	}
      }
      return 0;
}