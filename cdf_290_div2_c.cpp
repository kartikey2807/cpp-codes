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
set <char> vis;
vector <char> compn;
vector <char> order;
void dfs (map <char, vector <char> > v, char pos)
{
	vis.insert(pos);
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (!vis.count(v[pos][i]))
			dfs(v,v[pos][i]);
	order.pb(pos);
}
void dfs2(map <char, vector <char> > v, char pos)
{
	vis.insert(pos);
	compn.pb(pos);
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (!vis.count(v[pos][i]))
			dfs2(v,v[pos][i]);
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
      string ans[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> ans[i];
      }
      map <char, vector <char> > v;
      map <char, vector <char> > g;
      for(lld i = 1; i < n; i += 1){
      	lld f = 0;
      	for(lld j = 0; j < min(ans[i].size(),ans[i-1].size()); j += 1){
      		if (ans[i][j] != ans[i-1][j]){
      			char a = ans[i-0][j];
      			char b = ans[i-1][j];
      			v[b].pb(a);
      			g[a].pb(b);
      			f = 1;
      			break;
      		}
      	}
      	if (f == 0){
      		if (ans[i].size() < ans[i-1].size()){
      			cout << "Impossible";
      			return 0;
      		}
      	}
      }
      for(char a = 'a'; a <= 'z'; a += 1){
      	if (!vis.count(a))
      		dfs(v,a);
      }
      lld f = 1;
      vis.clear();
      reverse(order.begin(), order.end());
      for(lld i = 0; i<order.size(); i++){
      	if (!vis.count(order[i])){
      		compn.clear();
      		dfs2(g,order[i]);
      		if (compn.size()>1){
      			f = 0;
      		}
      	}
      }
      if (f == 0){
      	cout << "Impossible";
      }
      else{
      	for(lld i = 0; i < order.size(); i += 1)
      		cout << order[i];
      }
      return 0;
}