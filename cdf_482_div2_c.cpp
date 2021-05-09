// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. 
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
#define auth set <lld> :: iterator
#define pb push_back
#define LEN 400000
lld vis[LEN];
lld cnt1, cnt2;
vector <lld> order;
lld dfs (vector <lld> v[], lld pos, lld dest)
{
	vis[pos] = 1;
	if (pos == dest)
		{order.pb(pos); return 1;}
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1){
			if (dfs(v,v[pos][i],dest) == 1)
				{order.pb(pos);return 1;}
		}
	}
	return 0;
}
void dfs1 (vector <lld> v[], lld pos, lld forbid)
{
	vis[pos] = 1;
	cnt1++;
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (v[pos][i] == forbid)
			continue;
		if (vis[v[pos][i]]== -1)
			dfs1(v,v[pos][i],forbid);
	}
}
void dfs2 (vector <lld> v[], lld pos, lld forbid)
{
	vis[pos] = 1;
	cnt2++;
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (v[pos][i] == forbid)
			continue;
		if (vis[v[pos][i]]== -1)
			dfs2(v,v[pos][i],forbid);
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, x, y;
      cin >> n >> x >> y;
      vector <lld>v[n+1];
      for(lld i = 0; i <n-1; i += 1){
      	lld a, b;
      	cin >> a >> b;
      	v[a].pb(b);v[b].pb(a);
      }
      memset(vis, -1, sizeof(vis));
      dfs(v,x,y);
      memset(vis, -1, sizeof(vis));
      cnt1 = 0;
      dfs1(v, y, order[1]);
      memset(vis, -1, sizeof(vis));
      cnt2 = 0;
      lld len = order.size();
      dfs2(v,x,order[len-2]);
      cout <<(n*(n-1))-(cnt1*cnt2);
      return 0;
}