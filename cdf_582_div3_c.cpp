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
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld T, l;
      cin >> T;
      foi(l, T)
      {
      	lld n, m;
      	cin >> n;
      	cin >> m;
      	lld s, r;
      	s = 0;
      	for(lld i = 1; i <= 10; i+=1)
      	{
      		r = m *i;
      		if (r%10==0)
      		{
      			break;
      		}
      		s+= r%10;
      	}
      	lld q = n/r;
      	lld p = n%r;
      	s = s*q;
      	for(lld i = m; i <= p;  i+=m)
      	{
      		s+= i%10;
      	}
      	cout << s << "\n";
      }
      return 0;
}