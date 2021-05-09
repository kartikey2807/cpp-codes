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
lld val[LEN];
lld vis[LEN];
lld tal[LEN];
set <lld> ans;
map <lld,lld> cnt;
map <pair <lld, lld>, lld> mac;
void dfs (vector <lld> v[], lld pos, lld sum)
{
	vis[pos] = 1;
	auth itr =ans.begin();
	tal[pos] = sum-(*itr);
	cnt[sum]++;
	if (cnt[sum] == 1)
		ans.insert(sum);
	for(lld i = 0; i < v[pos].size(); i+=1)
		if (vis[v[pos][i]] == -1)
			dfs(v,v[pos][i],sum+mac[make_pair(pos,v[pos][i])]);
	cnt[sum]--;
	if (cnt[sum] == 0)
		ans.erase (sum);
}
void dfs1(vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs1(v,v[pos][i]);
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
      for(lld i = 1; i <= n; i += 1){
      	cin >> val[i];
      }
      vector <lld> g[n+1];
      vector <lld> v[n+1];
      for(lld i = 2; i <= n; i += 1){
      	lld p, c;
      	cin >> p >> c;
      	g[p].pb(i);
      	v[i].pb(p);v[p].pb(i);
      	mac[make_pair(i,p)]=c;
      	mac[make_pair(p,i)]=c;
      }
      memset(vis,-1, sizeof(vis));
      dfs(v,1,0);
      set <lld> res;
      for(lld i = 1; i <= n; i += 1){
      	if (tal[i] > val[i])
      		res.insert(i);
      }
      memset(vis,-1, sizeof(vis));
      for(lld i = 1; i <= n; i += 1){
      	if (res.count(i))
      		dfs1(g,i);
      }
      lld c = 0;
      for(lld i = 1; i <= n; i += 1){
      	if (vis[i] == 1)
      		c++;
      }
      cout<< c;
      return 0;
}