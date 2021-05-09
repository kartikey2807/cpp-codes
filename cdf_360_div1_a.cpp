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
set <lld> part[2];
void dfs (vector <lld> v[], lld pos, lld x)
{
	vis[pos] = 1;
	part[x].insert(pos);
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]]  == -1)
			dfs(v,v[pos][i],1-x);
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
      pair <lld, lld> edge[m];
      for(lld i = 0; i < m; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	edge[i] = {x,y};
      	v[x].push_back(y);
      	v[y].push_back(x);
      }
      memset(vis, -1, sizeof(vis));
      for(lld i = 1; i <= n;i += 1){
      	if (vis[i] == -1)
      		dfs(v,i,0);
      }
      lld f = 1;
      for(lld i = 0; i < m; i += 1){
      	if ((part[0].count(edge[i].first) && part[0].count(edge[i].second)) || (part[1].count(edge[i].first) && part[1].count(edge[i].second)))
      		f = 0;
      }
      if (f == 0){cout << "-1";}
      else{
      	cout << part[0].size() << "\n";
      	for(set <lld> :: iterator itr = part[0].begin(); itr != part[0].end(); itr++)
      		cout << *itr << " ";
      	cout << "\n";
      	cout << part[1].size() << "\n";
      	for(set <lld> :: iterator itr = part[1].begin(); itr != part[1].end(); itr++)
      		cout << *itr << " ";
      }
      return 0;
}