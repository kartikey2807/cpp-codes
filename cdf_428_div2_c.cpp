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
#define LEN 100005
lld vis[LEN];
dbl pro[LEN];
dbl sum;
lld lev[LEN];
void dfs (vector <lld> v[], lld pos, lld parent, dbl val)
{
	lev[pos] = 1+lev[parent];
	pro[pos] = val;
	vis[pos] = 1;
	lld cnt  = 0;
	dbl ans;
	dbl len = v[pos].size();
	if (pos == 1) {ans = pro[pos]/len;}
	else {ans = pro[pos]/(len-1);}
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1){
			cnt++;
			dfs(v,v[pos][i],pos,ans);
		}
	}
	if (cnt == 0) {sum += (lev[pos]*pro[pos]);}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      vector <lld> v[n+1];
      for(lld i = 0; i < n-1; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	v[x].push_back(y);
      	v[y].push_back(x);
      }
      memset(vis, -1, sizeof(vis));
      memset(lev, 0, sizeof(lev));
      memset(pro, 0, sizeof(pro));
      sum = 0;
      lev[0] = -1;
      dfs(v,1,0,1);
      cout << fixed << setprecision(15) << sum << "\n";
      return 0;
}