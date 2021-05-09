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
#define LEN 100000
lld vis[LEN];
map <lld, lld> dist_s, dist_t;
map <lld, lld> bfs (set <lld> path[], lld pos)
{
	memset(vis, -1, sizeof(vis));
	map <lld, lld> temp;
	queue <lld> q;
	q.push(pos);
	vis[pos] = 1;
	temp[pos] = 0;
	while(!q.empty()){
		lld x = q.front();
		q.pop();
		for(auth itr = path[x].begin(); itr != path[x].end(); itr++){
			if (vis[*itr] == -1){
				vis[*itr]= 1;
				q.push(*itr);
				temp[*itr] = temp[x]+1;
			}
		}
	}
	return temp;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m, s, t;
      cin >> n >> m >> s >> t;
      set <lld> path[n+1];
      for(lld i = 1; i <= m; i += 1){
      	lld a, b;
      	cin >> a >> b;
      	path[a].insert(b); path[b].insert(a);
      }
      dist_s = bfs(path,s);
      dist_t = bfs(path,t);
      lld orig = dist_s[t];
      vector <pair <lld, lld> > mac;
      for(lld i = 1; i <= n; i += 1){
      	for(lld j = i+1; j <= n; j += 1){
      		if (!path[i].count(j))
      			mac.pb(make_pair(i,j));
      	}
      }
      lld cnt = 0;
      for(lld i = 0; i < mac.size(); i += 1){
      	set <lld> play;
      	play.insert(dist_s[mac[i].first]+dist_t[mac[i].first]); play.insert(dist_s[mac[i].second]+dist_t[mac[i].second]); play.insert(1+dist_s[mac[i].first]+dist_t[mac[i].second]); play.insert(1+dist_s[mac[i].second]+dist_t[mac[i].first]);
      	auth itr = play.begin();
      	if ((*itr) >= orig)
      		cnt++;
      }
      cout << cnt;
      return 0;
}