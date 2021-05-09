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
#define LEN 300000
lld vis[LEN];
lld col[LEN];
lld n;
void dfs (vector <lld> v[], lld pos, lld g_pos)
{
	vis[pos] = 1;
	lld cnt  = 1;
	lld i = 0;
	while(i < v[pos].size()){
		if (col[v[pos][i]] == -1){
			if (cnt != col[pos] && cnt != col[g_pos]){
				col[v[pos][i]] = cnt;
				i++;
			}
			cnt++;
		}
		else  i+= 1;
	}
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] ==  -1){
			dfs(v,v[pos][i],pos);
		}
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      cin >> n;
      vector <lld> v[n+1];
      for(lld i = 0; i < n-1; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	v[x].pb(y);v[y].pb(x);
      }
      memset(vis, -1, sizeof(vis));
      memset(col, -1, sizeof(col));
      col[1] = 1;
      vis[1] = 1;
      lld cnt= 2;
      for(lld i = 0; i < v[1].size(); i += 1){
      	col[v[1][i]]=cnt;
      	cnt++;
      	dfs(v,v[1][i],1);
      }
      lld ans = MIN;
      for(lld i = 1; i <= n; i += 1)
      	ans = max(ans,col[i]);
      cout << ans << "\n";
      for(lld i = 1; i <= n; i += 1)
      	cout << col[i] << " ";
      return 0;
}