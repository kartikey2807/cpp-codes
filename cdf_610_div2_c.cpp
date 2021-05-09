// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
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
#define pb push_back
map <pair <lld, lld>, lld> fval;
map <pair <lld, lld>, lld> sval;
void put (lld a, lld b, lld c)
{
	if (fval[{a,b}] == 0)
		{fval[{a,b}] = fval[{b,a}] = c;}
	else
		{sval[{a,b}] = sval[{b,a}] = c;}
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
      map <lld, lld> cnt;
      vector <lld> v[n+1];
      for(lld i = 0; i < n-2; i += 1){
      	lld a, b, c;
      	cin >> a >> b >> c;
      	v[a].pb(b); v[b].pb(a); v[b].pb(c); v[c].pb(b); v[a].pb(c); v[c].pb(a);
      	put(a,b,c);put(b,c,a); put(c,a,b);
      	cnt[a]++; cnt[b]++; cnt[c]++;
      }
      lld i;
      for(i = 1; i <= n; i += 1)
      	if (cnt[i] == 1)
      		break;
      lld pos;
      for(lld j = 0; j < v[i].size(); j += 1){
      	if (cnt[v[i][j]] == 2)
      		pos = v[i][j];
      }
      set <lld> vis;
      vis.insert(i); vis.insert(pos);
      cout << i << " " << pos << " ";
      n-=2;
      while(n--){
      	if (!vis.count(fval[{i,pos}])){
      		cout << fval[{i,pos}] << " ";
      		vis.insert(fval[{i,pos}]);
      		lld temp = i;
      		i = pos;
      		pos = fval[{temp,pos}];
      	}
      	else{
      		cout << sval[{i,pos}] << " ";
      		vis.insert(sval[{i,pos}]);
      		lld temp = i;
      		i = pos;
      		pos = sval[{temp,pos}];
      	}
      }
      return 0;
}