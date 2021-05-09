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
      string s;
      cin >> n >> s;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	A[i] = (lld)s[i]-48;
      }
      lld f = 1;
      for(lld i = 1; i < n; i += 1){
      	if (A[i] != A[i-1])
      		f = 0;
      }
      if (f == 1) cout << "0";
      else{
      	lld zero = 0;
      	lld onee = 0;
      	pair <lld, lld> cnt[n+1];
      	cnt[0] = {zero,onee};
      	for(lld i = 0; i < n; i += 1){
      		if (A[i] == 1)
      			onee++;
      		else
      			zero++;
      		cnt[i+1] = {zero, onee};
      	}
      	map <lld, lld> offset;
      	for(lld i = 0; i<n+1; i += 1){
      		if (!offset.count(cnt[i].first-cnt[i].second))
      			offset[cnt[i].first-cnt[i].second] = i;
      	}
      	lld ans = MIN;
      	for(lld i = n; i >=0; i -= 1){
      		if (offset.count(cnt[i].first-cnt[i].second)){
      			ans = max(ans, i-offset[cnt[i].first-cnt[i].second]);
      		}
      	}
      	cout << ans;
      }
      return 0;
}