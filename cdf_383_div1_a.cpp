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
lld gcd_ (lld a, lld b)
{
	lld max = a > b ? a : b;
	lld min = a < b ? a : b;
	while(min){
		lld rem = max%min;
		max = min;
		min = rem;
	}
	return max;
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
      map <lld, lld> in_deg;
      for(lld i = 1; i <= n; i += 1){
      	lld x;
      	cin >> x;
      	v[i].pb(x);
      	in_deg[x]++;
      }
      memset(vis, -1, sizeof(vis));
      vector <lld> ans;
      for(lld i = 1; i <= n; i += 1){
      	if (vis[i] == -1){
      		orz.clear();
      		dfs(v,i);
      		lld f= 1;
      		for(lld j = 0; j < orz.size(); j += 1){
      			if (in_deg[orz[j]] != 1)
      				f = 0;
      		}
      		if (f == 0){
      			cout << "-1";  return 0;
      		}
      		else{
      			lld len = orz.size();
      			if (len%2 == 0)
      				ans.pb(len/2);
      			else 
      				ans.pb(len/1);
      		}
      	}
      }
      lld g = ans[0];
      lld p = ans[0];
      for(lld i = 1; i < ans.size(); i += 1){
      	g = gcd_(g,ans[i]);
      	p = p*ans[i];
      	lld x =  p/g;
      	p = g = x;
      }
      cout<< p;
      return 0;
}