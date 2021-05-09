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
#define LEN 100005
lld vis[LEN];
lld cnt[LEN];
lld f;
lld ans;
void dfs (vector <lld> v[], lld pos, set <lld> s[])
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1){
		for(lld j = i+1; j < v[pos].size(); j += 1){
			if (s[v[pos][i]].count(v[pos][j])){
				f = 1;
				ans = min(ans,cnt[pos]+cnt[v[pos][i]]+cnt[v[pos][j]]-6);
			}
		}
	}
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs(v,v[pos][i],s);
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
      set <lld> s[n+1];
      memset(vis,-1,sizeof(vis));
      memset(cnt, 0,sizeof(cnt));
      for(lld i = 1; i <= m; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	v[x].push_back(y);
      	s[x].insert(y);
      	cnt[x]++;
      	v[y].push_back(x);
      	s[y].insert(x);
      	cnt[y]++;
      }
      f = 0;
      ans = MAX;
      for(lld i = 1; i <= n; i += 1){
      	if (vis[i] == -1)
      		dfs(v,i,s);
      }
      if (f == 0) cout << "-1";
      else cout << ans;
      return 0;
}