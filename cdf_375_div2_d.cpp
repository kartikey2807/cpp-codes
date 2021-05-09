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
#define LEN 100
char dda[LEN][LEN];
set <pair <lld, lld> > vis;
vector <pair <lld, lld> > orz;
vector <vector <pair <lld, lld> > > order;
map <pair <lld, lld>, vector <pair <lld, lld> > >v;
void dfs (pair <lld, lld> pos)
{
	vis.insert(pos);
	orz.pb(pos);
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (dda[v[pos][i].first][v[pos][i].second] == '.' && !vis.count(v[pos][i]))
			dfs(v[pos][i]);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m, k;
      cin >> n >> m >> k;
     	for(lld i = 0; i < n; i += 1){
     		for(lld j = 0; j < m; j += 1){
     			cin >> dda[i][j];
     		}
     	}
     	for(lld i = 0; i < n; i += 1){
     		for(lld j = 1; j < m; j += 1){
     			v[make_pair(i,j)].pb(make_pair(i,j-1));
     			v[make_pair(i,j-1)].pb(make_pair(i,j));
     		}
     	}
     	for(lld j = 0; j < m; j += 1){
     		for(lld i = 1; i < n; i += 1){
     			v[make_pair(i,j)].pb(make_pair(i-1,j));
     			v[make_pair(i-1,j)].pb(make_pair(i,j));
     		}
     	}
     	lld cnt = 0;
     	for(lld i = 0; i < n; i += 1){
     		for(lld j = 0; j < m; j += 1){
     			if (dda[i][j] == '.' && !vis.count(make_pair(i,j))){
     				orz.clear();
     				dfs(make_pair(i,j));
     				lld f = 1;
     				for(lld j = 0; j < orz.size(); j += 1){
     					if ((orz[j].first == 0 || orz[j].first == n-1) || (orz[j].second == 0 || orz[j].second == m-1))
     						f = 0;
     				}
     				if (f == 1){
     					cnt++;
     					order.pb(orz);
     				}
     			}
     		}
     	}
     	set <lld> del;
     	while(cnt > k){
     		lld pos;
     		lld ans = MAX;
     		for(lld i = 0; i < order.size(); i += 1){
     			if (del.count(i))
     				continue;
     			lld len = order[i].size();
     			if (len < ans){
     				ans=len;
     				pos = i;
     			}
     		}
     		del.insert(pos);
     		cnt-= 1;
     	}
     	lld sum = 0;
     	for(auth itr = del.begin(); itr != del.end(); itr++){
     		sum += order[*itr].size();
     	}
     	cout << sum << "\n";
     	for(auth itr = del.begin(); itr != del.end(); itr++){
     		for(lld j = 0; j < order[*itr].size(); j += 1){
     			dda[order[*itr][j].first][order[*itr][j].second] = '*';
     		}
     	}
     	for(lld i = 0; i < n; i += 1){
     		for(lld j = 0; j < m; j += 1){
     			cout << dda[i][j];
     		}
     		cout << "\n";
     	}
      return 0;
}