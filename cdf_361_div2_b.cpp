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
lld dis[LEN];
void bfs (vector <lld> v[], lld pos)
{
	memset(vis, -1, sizeof(vis));
	queue <lld> q;
	q.push(pos);
	vis[pos]= 1;
	dis[pos]= 0;
	while(!q.empty()){
		lld x = q.front();
		q.pop();
		for(lld i = 0; i < v[x].size(); i += 1){
			if (vis[v[x][i]] == -1){
				vis[v[x][i]]= 1;
				dis[v[x][i]]= dis[x]+1;
				q.push(v[x][i]);
			}
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
      lld n;
      cin >> n;
      vector <lld> v[n+1];
      for(lld i = 1; i <= n; i += 1){
      	lld r;
      	cin >> r;
      	v[i].pb(r);
      	if (i < n){
      		v[i].pb(i+1);
      		v[i+1].pb(i);
      	}
      }
      bfs(v,1);
      for(lld i = 1; i <= n; i += 1){
      	cout << dis[i] << " ";
      }
      return 0;
}