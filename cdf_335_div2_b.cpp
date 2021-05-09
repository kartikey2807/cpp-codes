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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld x,y,x0,y0;
      cin >> x >> y;
      cin >> x0>>y0;
      string s;
      cin >> s;
      lld n = s.size();
      vector <lld> ans(n+1);
      set <pair <lld, lld> > vis;
      pair <lld, lld> p = make_pair(x0,y0);
      vis.insert(p);
      ans[0] = 1;
      for(lld i = 0; i < s.size(); i += 1){
      	if (s[i] == 'U')
      		p.first = max(p.first-1, (lld)1);
      	if (s[i] == 'D')
      		p.first = min(p.first+1, (lld)x);
      	if (s[i] == 'L')
      		p.second= max(p.second-1,(lld)1);
      	if (s[i] == 'R')
      		p.second= min(p.second+1,(lld)y);
      	if (!vis.count(p)){
      		ans[i+1] = 1;
      		vis.insert(p);
      	}
      }
      lld len = vis.size();
      ans[n] += (x*y)-len;
      for(lld i = 0; i <= n; i += 1)
      	cout << ans[i] << " ";
      return 0;
}