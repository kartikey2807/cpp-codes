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
lld f;
set <lld> vis;
void dfs (set <lld> s[], lld pos, lld dest)
{
	vis.insert(pos);
	if (pos ==dest){
		f = 1;
		return;
	}
	for(set <lld> :: iterator itr = s[pos].begin(); itr != s[pos].end(); itr++)
		if (!vis.count((*itr)))
			dfs(s,*itr,dest);
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
      lld j = 1;
      set <lld> s[n+1];
      pair <lld, lld> p[n+1];
      for(lld i = 0; i < n; i += 1){
      	lld step;
      	cin >> step;
      	if (step == 1){
      		lld x, y;
      		cin >> x >> y;
      		p[j] = {x, y};
      		if (j != 1){
      			for(lld k = 1; k <= j; k += 1){
      				for(lld l = 1; l <= j; l += 1){
      					if ((p[k].first > p[l].first && p[k].first < p[l].second) || (p[k].second > p[l].first && p[k].second < p[l].second))
      						s[k].insert(l);
      				}
      			}
      		}
      		j++;
      	}
      	else{
      		lld a, b;
      		cin >> a >> b;
      		f = 0;
      		vis.clear();
      		dfs(s,a,b);
      		if (f == 1) cout << "YES\n";
      		else cout << "NO\n";
      	}
      }
      return 0;
}