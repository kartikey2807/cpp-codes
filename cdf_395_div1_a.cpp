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
#define LEN 200000
lld vis[LEN];
lld col[LEN];
lld p, q;
set <lld>ans;
void dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1){
			if (col[v[pos][i]]!=col[pos]){
				if (p == 0){
					p = v[pos][i];
					q = pos;
				}
			}
			dfs(v,v[pos][i]);
		}
	}
}
void dfs1 (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	ans.insert(col[pos]);
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1)
			dfs1(v,v[pos][i]);
	}
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
      for(lld i = 0; i <n-1; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	v[x].pb(y);v[y].pb(x);
      }
      memset(vis,-1, sizeof(vis));
      for(lld i = 1; i <= n; i += 1){
      	cin >> col[i];
      }
      p = 0;
      dfs(v,1);
      if (p == 0){
      	cout << "YES\n1";
      }
      else{
      	memset(vis,-1,sizeof(vis));
      	vis[p] = 1;
      	lld f  = 1;
      	for(lld i = 0; i < v[p].size(); i += 1){
      		ans.clear();
      		dfs1(v,v[p][i]);
      		if (ans.size() > 1)
      			f = 0;
      	}
      	if (f == 1){
      		cout << "YES\n" << p;
      	}
      	else{
      		memset(vis,-1,sizeof(vis));
      		vis[q] = 1;
      		lld g  = 1;
      		for(lld i = 0; i < v[q].size(); i += 1){
      			ans.clear();
      			dfs1(v,v[q][i]);
      			if (ans.size() > 1)
      				g = 0;
      		}
      		if (g == 1) cout << "YES\n" << q;
      		else cout << "NO";
      	}
      }
      return 0;
}