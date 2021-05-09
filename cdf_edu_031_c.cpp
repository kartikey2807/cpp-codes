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
lld cnt;
lld vis[LEN];
void dfs1 (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	cnt++;
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs1(v,v[pos][i]);
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
      vector <lld> x[n+1];
      for(lld i = 1; i <= n; i += 1){
      	lld r;
      	cin >> r;
      	v[i].push_back(r);
      	x[r].push_back(i);
      }
      vector <lld> c;
      memset(vis, -1, sizeof(vis));
      for(lld i = 1; i <= n; i += 1){
      	if (vis[i] == -1){
      		cnt = 0;
      		dfs1(v,i);
      		c.push_back(cnt);
      	}
      }
      if (c.size() == 1) cout  << (c[0]*c[0]);
      else{
      	sort(c.begin(),c.end(),greater<lld>());
      	lld sum = (c[0]+c[1])*(c[0]+c[1]);
      	for(lld i = 2; i < c.size(); i++)
      		sum += (c[i]*c[i]);
      	cout << sum;
      }
      return 0;
}