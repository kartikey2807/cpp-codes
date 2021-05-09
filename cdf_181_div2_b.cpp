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
#define LEN 2000
lld vis[LEN];
vector <lld> order;
void dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs(v,v[pos][i]);
	order.pb(pos);
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
      for(lld i = 1; i <= m; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	v[x].pb(y);
      	v[y].pb(x);
      }
      vector <set <lld> > val;
      memset(vis, -1, sizeof(vis));
      for(lld i = 1; i <= n; i += 1){
      	if (vis[i] == -1){
      		order.clear();
      		dfs(v,i);
      		if (order.size() > 3)
      			{cout << "-1"; return 0;}
      		else{
      			if (order.size() == 1)
      				vis[i] = -1;
      			else{
      				set <lld> s;
      				for(lld j = 0; j < order.size(); j += 1)
      					s.insert(order[j]);
      				val.pb(s);
      			}
      		}
      	}
      }
      lld j = 1;
      for(lld i = 0; i < val.size(); i += 1){
      	if (val[i].size() == 2){
      		for(; j <= n;j++){
      			if (vis[j] == -1)
      				{val[i].insert(j); vis[j] = 1; break;}
      		}
      	}
      }
      set <lld> s;
      for(lld i = 1; i <= n; i += 1){
      	if (vis[i] == -1){
      		s.insert(i);
      		vis[i] = 1;
      		if (s.size() == 3){
      			val.pb(s);
      			s.clear();
      		}
      	}
      }
      for(lld i = 0; i < val.size(); i += 1){
      	if (val[i].size() < 3)
      		{cout << "-1"; return 0;}
      }
      for(lld i = 0; i < val.size(); i += 1){
      	for(auth itr = val[i].begin(); itr != val[i].end(); itr++)
      		cout << *itr << " ";
      	cout << "\n";
      }
      return 0;
}