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
lld gov[LEN];
lld siz;
lld cnt;
void dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	siz++;
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			cnt++;
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs(v,v[pos][i]);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m, k;
      cin >> n >> m >> k;
      vector <lld>v[n+1];
      memset(gov, -1, sizeof(gov));
      memset(vis, -1, sizeof(vis));
      for(lld i = 0; i < k; i += 1){
      	lld r;
      	cin >> r;
      	gov[r]=1;
      }
      for(lld i = 0; i < m; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	v[x].push_back(y);
      	v[y].push_back(x);
      }
      vector <lld> ans1, ans2;
      vector <lld> rnt1, rnt2;
      for(lld i = 1; i <= n; i += 1){
      	if (gov[i] != -1){
      		siz = 0;
      		cnt = 0;
      		dfs(v,i);
      		ans1.push_back(siz); rnt1.push_back(cnt);
      	}
      }
      for(lld i = 1; i <= n; i += 1){
      	if (vis[i] == -1){
      		siz = 0;
      		cnt = 0;
      		dfs(v,i);
      		ans2.push_back(siz); rnt2.push_back(cnt);
      	}
      }
      lld ans = MIN;
      lld pos;
      for(lld i = 0; i < ans1.size(); i += 1){
      	lld sum = ans1[i];
      	lld edg = rnt1[i];
      	for(lld j = 0; j < ans2.size(); j += 1){
      		sum += ans2[j];
      		edg += rnt2[j];
      	}
      	if (((sum*(sum-1))/2)-edg > ans){
      		ans = (sum*(sum-1))/2-edg;
      		pos = i;
      	}
      }
      for(lld i = 0; i < ans1.size(); i += 1){
      	if (i == pos)
      		continue;
      	ans += (ans1[i]*(ans1[i]-1))/2-rnt1[i];
      }
      cout << ans;
      return 0;
}