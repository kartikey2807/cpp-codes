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
set <lld> saw;
vector <lld> ans;
vector <lld> took;
vector <lld> order;
void dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs(v,v[pos][i]);
	saw.insert(pos);
	took.push_back(pos);
}
void dfs1(vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs1(v,v[pos][i]);
	order.push_back(pos);
}
void dfs2(vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	ans.push_back(pos);
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs2(v,v[pos][i]);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, k;
      cin >> n >> k;
      lld A[k];
      for(lld i = 0; i < k; i += 1){
      	cin >> A[i];
      }
      vector <lld> v[n+1];
      vector <lld> u[n+1];
      for(lld i = 1; i <=n; i += 1){
      	lld len;
      	cin >> len;
      	foi(j,len){
      		lld x;
      		cin >> x;
      		v[i].push_back(x);
      		u[x].push_back(i);
      	}
      }
      memset(vis, -1,  sizeof(vis));
      for(lld i = 0; i < k; i += 1){
      	if (vis[A[i]] == -1)
      		dfs(v,A[i]);
      }
      // get all the cycles
      memset(vis, -1,  sizeof(vis));
      for(lld i = 1; i <=n; i += 1){
      	if (vis[i] == -1)
      		dfs1(v,i);
      }
      reverse(order.begin(), order.end());
      memset(vis, -1,  sizeof(vis));
      lld f = 1;
      for(lld i = 0;i < order.size();i++){
      	if (vis[order[i]] == -1){
      		ans.clear();
      		dfs2(u,order[i]);
      		if (ans.size() > 1){
      			foi(j,ans.size()){
      				if (saw.count(ans[j]))
      					f = 0;
      			}
      		}
      	}
      }
      if (f == 0) cout << "-1";
      else{
      	cout << took.size() << "\n";
      	foi(i,took.size()) cout << took[i] << " ";
      }
      return 0;
}