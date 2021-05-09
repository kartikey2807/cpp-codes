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
      lld n;
      cin >> n;
      lld m = 2*n;
      lld A[m];
      for(lld i = 0; i < m; i += 1)
      	cin >> A[i];
      sort(A,A+m);
      lld ans = MAX;
      for(lld i = 0; i < m; i += 1){
      	for(lld j = 0; j < m; j += 1){
      		if (j == i)
      			continue;
      		vector <lld> v;
      		for(lld k = 0; k < m; k += 1){
      			if (k == i || k == j)
      				continue;
      			v.push_back(A[k]);
      		}
      		lld sum = 0;
      		for(lld k = 1; k<m-2; k += 2)
      			sum += (v[k]-v[k-1]);
      		ans = min(ans, sum);
      	}
      }
      cout << ans;
      return 0;
}