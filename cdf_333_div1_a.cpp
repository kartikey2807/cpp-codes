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
#define LEN 1000
lld tak[LEN];
lld dis[LEN];
set <pair <lld, lld> > vis;
pair <lld, lld> bfs (vector <lld> v[], lld n)
{
	memset(tak,-1, sizeof(tak));
	memset(dis, 0, sizeof(dis));
	queue <lld> q;
	q.push(1);
	tak[1]= 1;
	dis[1]= 0;
	lld x , c = 0;
	while(!q.empty()){
		x = q.front();
		q.pop();
		if (x == n)
			break;
		for(lld i = 0; i < v[x].size(); i += 1){
			if (tak[v[x][i]] == -1){
				tak[v[x][i]] = 1;
				q.push(v[x][i]);
				dis[v[x][i]] = dis[x]+1;
			}
		}
	}
	return make_pair(x,dis[x]);
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
      	lld a, b;
      	cin >> a >> b;
      	v[a].pb(b);
      	v[b].pb(a);
      	vis.insert(make_pair(a,b));
      	vis.insert(make_pair(b,a));
      }
      vector <lld> g[n+1];
      for(lld i = 1; i <= n; i += 1){
      	for(lld j = i+1; j <= n; j += 1){
      		if ( !vis.count(make_pair(i,j))){
      			g[i].pb(j);
      			g[j].pb(i);
      			vis.insert(make_pair(i,j));
      		}
      	}
      }
      pair <lld, lld> p1 = bfs(v,n);
      pair <lld, lld> p2 = bfs(g,n);
      if (p1.first == n && p2.first == n){
      	cout << max(p1.second,p2.second);
      }
      else{
      	cout << "-1";
      }
      return 0;
}