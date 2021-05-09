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
      lld n, x;
      lld y, i;
      cin >> n;
      cin >> x;
      cin >> y;
      string s;
      cin >> s;
      string t;
      t = s;
      lld count;
      count = 0;
      lld flagy;
      flagy = 0;
      lld c = 0;
      fod(i, n){
      	if (count== x)
      		break;
      	if (count== y)
      	{
      		if (s[i] == '0')
      			c  += 1;
      	}
      	if (count < y)
      	{
      		if (s[i] == '1')
      			c  += 1;
      	}
      	if (count > y)
      	{
      		if (s[i] == '1')
      			c  += 1;
      	}
      	count += 1 ;
      }
      cout<< c;
      return 0;
}