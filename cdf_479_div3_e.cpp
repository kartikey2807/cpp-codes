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
#define LEN 200005
lld vis[LEN];
vector <lld> order;
void dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1)
			dfs(v,v[pos][i]);
	}
	order.push_back(pos);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      vector <lld> v[n+1];
      lld len[n+1];
      memset(len, 0, sizeof(len));
      for(lld i = 1; i <= m; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	v[x].push_back(y); v[y].push_back(x);
      	len[x]++;
      	len[y]++;
      }
      lld c = 0;
      memset(vis, -1, sizeof(vis));
      for(lld i = 1; i <= n; i += 1){
      	if (vis[i] == -1){
      		order.clear();
      		dfs(v,i);
      		if (order.size() >= 3){
      			lld f = 1;
      			for(lld j = 0; j < order.size(); j += 1)
      				if (len[order[j]] != 2)
      					f = 0;
      			if (f == 1)
      				c++;
      		}
      	}
      }
      cout <<c;
      return 0;
}