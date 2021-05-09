// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
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
#define LEN 200010
lld vis[LEN];
lld cnt[LEN];
lld loc[LEN];
vector <lld> order;
lld dfs (vector <lld> v[], lld pos)
{
	order.pb(pos);
	vis[pos] = 1;
	lld c = 0;
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			c+=dfs(v,v[pos][i]);
	cnt[pos] = c+1;
	return c+1;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, q;
      cin >> n >> q;
      vector <lld> v[n+1];
      for(lld i = 2; i <= n; i += 1){
      	lld r;
      	cin >> r;
      	v[r].pb(i);
      }
      memset(vis, -1, sizeof(vis));
      memset(cnt,  0, sizeof(cnt));
      memset(loc, -1, sizeof(loc));
      dfs(v,1);
      for(lld i = 0; i < order.size(); i += 1)
      	loc[order[i]] = i;
      while(q--){
      	lld u, k;
      	cin >> u >> k;
      	if (k > cnt[u]) {cout << "-1\n";}
      	else {lld val = loc[u]; cout << order[val+k-1] << "\n";}
      }
      return 0;
}