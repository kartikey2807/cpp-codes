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
lld n;
lld cst[LEN], vis[LEN];
map <pair <lld, lld>, lld> dp;
map <pair <lld, lld>, string > val;
map <pair <lld, lld>, vector <pair <lld, lld> > > v;
lld dfs (pair <lld, lld> pos)
{
	if (!dp.count(pos)){
		vector <lld> ans;
		for(lld i = 0; i < v[pos].size(); i += 1){
			if (val[v[pos][i]] >= val[pos]){
				ans.pb(dfs(v[pos][i]));
			}
		}
		if (ans.empty()){
			if (pos.first != n-1)
				dp[pos] = -1;
			else
				dp[pos] = (pos.second == 0) ? 0 : cst[pos.first];
		}
		else{
			lld res = MAX;
			for(lld i = 0; i < ans.size(); i += 1){
				if (ans[i] != -1)
					res = min(res, ans[i]);
			}
			if (res == MAX)
				dp[pos] = -1;
			else
				dp[pos] = res+((pos.second == 0)? 0 : cst[pos.first]);
		}
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
      cin >> n;
      for(lld i = 0; i < n; i += 1){
      	cin >> cst[i];
      }
      for(lld i = 0; i < n; i += 1){
      	string s, r;
      	cin >> s;
      	r = s;
      	reverse(r.begin(),r.end());
      	val[make_pair(i,0)] = s;
      	val[make_pair(i,1)] = r;
      }
      for(lld i = 0; i<n-1; i += 1){
      	v[make_pair(i,0)].pb(make_pair(i+1,0)); v[make_pair(i,0)].pb(make_pair(i+1,1));
      	v[make_pair(i,1)].pb(make_pair(i+1,0)); v[make_pair(i,1)].pb(make_pair(i+1,1));
      }
      dfs(make_pair(0,0));
      dfs(make_pair(0,1));
      if (dp[make_pair(0,0)] == -1 && dp[make_pair(0,1)] == -1){
      	cout << "-1";
      }
      else{
      	if (dp[make_pair(0,0)]  == -1){
      		cout<<dp[make_pair(0,1)];
      	}
      	else{
      		if (dp[make_pair(0,1)]  == -1){
      			cout<<dp[make_pair(0,0)];
      		}
      		else{
      			cout << min(dp[make_pair(0,0)],dp[make_pair(0,1)]);
      		}
      	}
      }
      return 0;
}