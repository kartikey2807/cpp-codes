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
vector <lld> depth[LEN];
void dfs (vector <lld> v[], lld pos, lld d)
{
	vis[pos] = 1;
	depth[d+1].push_back(v[pos].size()-1);
	for(lld i = 0; i < v[pos].size();i++)
		if (vis[v[pos][i]]  == -1)
			dfs(v,v[pos][i],d+1);
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
      for(lld i = 2; i <= n; i += 1){
      	lld r;
      	cin >> r;
      	v[i].push_back(r);
      	v[r].push_back(i);
      }
      memset(vis, -1, sizeof(vis));
      dfs(v,1,0);
      depth[0].push_back(1);
      depth[1][0]++;
      lld sum = 0;
      for(lld i = 0; i < LEN; i += 1){
      	if (depth[i].empty())
      		break;
      	for(lld j = 0; j < depth[i].size(); j += 1)
      		depth[i][j] = depth[i][j]%2;
      	lld cnt = 0;
      	for(lld j = 0; j < depth[i].size(); j += 1)
      		if (depth[i][j] == 1)
      			cnt++;
      	if (cnt%2 != 0)
      		sum++;
      }
      cout<<sum;
      return 0;
}