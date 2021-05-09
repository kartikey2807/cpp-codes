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
#define LEN 400000
lld vis[LEN];
vector <lld> order;
vector <lld> component;
void dfs1 (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1)
			dfs1(v,v[pos][i]);
	}
	order.pb(pos);
}
void dfs2 (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	component.pb(pos);
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1)
			dfs2(v,v[pos][i]);
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n;
      	string s;
      	cin >> n >> s;
      	lld start = 1, end = 2;
      	vector <lld> v[n+1];
      	vector <lld> vr[n+1];
      	for(lld i = 0; i < n-1; i += 1){
      		if (s[i] == '-') {v[start].pb(end); v[end].pb(start); vr[end].pb(start); vr[start].pb(end);}
      		if (s[i] == '>') {v[start].pb(end); vr[end].pb(start);}
      		if (s[i] == '<') {v[end].pb(start); vr[start].pb(end);}
      		start++; end++;
      	}
      	if (s[n-1] == '-') {v[1].pb(n); v[n].pb(1); vr[n].pb(1); vr[1].pb(n);}
      	if (s[n-1] == '>') {v[n].pb(1); vr[1].pb(n);}
      	if (s[n-1] == '<') {v[1].pb(n); vr[n].pb(1);}
      	memset(vis, -1, sizeof(vis));
      	order.clear();
      	for(lld i = 1; i <= n; i += 1){
      		if (vis[i] == -1)
      			dfs1(v,i);
      	}
      	memset(vis, -1, sizeof(vis));
      	reverse(order.begin(), order.end());
      	lld c = 0;
      	for(lld i = 0; i < order.size(); i += 1){
      		if (vis[order[i]] == -1){
      			component.clear();
      			dfs2(vr,order[i]);
      			if (component.size() == 1)
      				c++;
      		}
      	}
      	cout << n-c << "\n";
      }
      return 0;
}