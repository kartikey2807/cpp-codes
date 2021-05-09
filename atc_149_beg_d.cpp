#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef char chr;
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
      lld n, k;
      cin >> n;
      cin >> k;
      lld r, s;
      lld p, i;
      cin >> r;
      cin >> s;
      cin >> p;
      string t;
      cin >> t;
      chr c[n];
      foi(i, n)
      {
      	if (t[i] == 'r')
      		c[i]= 'p';
      	if (t[i] == 'p')
      		c[i]= 's';
      	if (t[i] == 's')
      		c[i]= 'r';
      }
      for(i = k; i < n; i++)
      {
      	if (c[i] == c[i-k])
      	{
      		if (t[i] == t[i-k])
      		{
      			c[i] = t[i];
      		}
      		else
      		{
      			if (t[i-k] == 'r')
      				c[i-k]= 's';
      			if (t[i-k] == 's')
      				c[i-k]= 'p';
      			if (t[i-k] == 'p')
      				c[i-k]= 'r';
      		}
      	}
      }
      lld  sum;
      sum  = 0;
      foi(i, n)
      {
      	if (t[i] == 'r' && c[i] == 'p')
      		sum+= p;
      	if (t[i] == 'p' && c[i] == 's')
      		sum+= s;
      	if (t[i] == 's' && c[i] == 'r')
      		sum+= r;
      }
      cout << sum << "\n";
      return 0;
}