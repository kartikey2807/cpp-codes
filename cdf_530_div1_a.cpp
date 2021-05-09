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
lld f;
lld s[LEN];
map <lld, lld> mac;
void dfs (vector <lld> v[], lld pos, lld lvl, lld acc)
{
	if (lvl%2){
		for(lld i = 0; i < v[pos].size(); i += 1){
			dfs(v,v[pos][i],lvl+1,s[pos]);
		}
	}
	else{
		lld len = v[pos].size();
		lld ans = MAX;
		if (len > 0){
			for(lld i = 0; i < v[pos].size(); i += 1){
				ans = min(ans, s[v[pos][i]]);
			}
			if (ans < acc)
				f = 0;
			mac[pos] = ans-acc;
			for(lld i = 0; i < v[pos].size(); i += 1){
				mac[v[pos][i]] = s[v[pos][i]]-ans;
			}
		}
		for(lld i = 0; i < v[pos].size(); i += 1){
			dfs(v,v[pos][i],lvl+1,ans);
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
      for(lld i = 2; i <= n; i += 1){
      	lld r;
      	cin >> r;
      	v[r].pb(i);
      }
      for(lld i = 1; i <= n; i += 1){
      	cin >> s[i];
      }
      f = 1;
      mac[1]=s[1];
      dfs(v,1,1,s[1]);
      if (f == 0)
      	cout <<"-1";
      else{
      	lld sum = 0;
      	for(lld i = 1; i <= n; i += 1)
      		sum += mac[i];
      	cout << sum;
      }
      return 0;
}