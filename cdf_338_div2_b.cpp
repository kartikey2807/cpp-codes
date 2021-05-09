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
lld dp[LEN];
lld sz[LEN];
lld dfs (vector <lld> v[], lld pos)
{
	if (dp[pos] == 0){
		lld ans  = 0;
		for(lld i = 0; i < v[pos].size(); i += 1)
			if (v[pos][i] < pos)
				ans = max(ans,dfs(v,v[pos][i]));
		dp[pos] = ans+1;
	}
	return dp[pos];
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
      	v[a].pb(b);sz[a]++;
      	v[b].pb(a);sz[b]++;
      }
      for(lld i = 1; i <= n; i += 1){
      	dfs(v,i);
      }
      lld res = MIN;
      for(lld i = 1; i <= n; i += 1){
      	res=max(res,dp[i]*sz[i]);
      }
      cout << res;
      return 0;
}