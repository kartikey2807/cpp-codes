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
lld sum;
bool buy (lld k, lld A[], lld n, lld s)
{
	lld B[n];
	for(lld i = 0; i < n; i += 1)
		B[i] = A[i]+(k*(i+1));
	sort(B,B+n);
	sum = 0;
	for(lld i = 0; i < k; i += 1)
		sum += B[i];
	return sum<=s;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, s;
      cin >> n >> s;
      lld A[n];
      for(lld i = 0; i < n; i += 1)
      	cin >> A[i];
      lld l = 0, r = n+1, mid = 0;
      while(r-l > 1){
      	mid = (l+r)/2;
      	if (buy(mid,A,n,s))
      		l = mid;
      	else  r = mid;
      }
      buy(l,A,n,s);
      cout << l << " " << sum;
      return 0;
}