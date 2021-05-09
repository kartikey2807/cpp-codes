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
vector <lld> orz;
void dfs (vector <lld> v[], lld pos)
{
	vis[pos]= 1;
	orz.pb(pos);
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs(v,v[pos][i]);
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
      vector <lld>v[n+1];
      lld C[n+1];
      for(lld i = 1; i <= n; i += 1){
      	cin >> C[i];
      }
      for(lld i = 1; i <= m; i += 1){
      	lld l, r;
      	cin >> l >> r;
      	v[l].pb(r);v[r].pb(l);
      }
      memset(vis, -1,sizeof(vis));
      lld sum = 0;
      for(lld i = 1; i <= n; i += 1){
      	if (vis[i] == -1){
      		orz.clear();
      		dfs(v,i);
      		map <lld, lld> cnt;
      		for(lld j = 0; j < orz.size(); j += 1){
      			cnt[C[orz[j]]]++;
      		}
      		lld ans = MIN;
      		for(map <lld, lld> :: iterator itr = cnt.begin(); itr != cnt.end(); itr++){
      			ans = max(ans,itr->second);
      		}
      		lld len = orz.size();
      		sum += len-ans;
      	}
      }
     	cout << sum;
      return 0;
}