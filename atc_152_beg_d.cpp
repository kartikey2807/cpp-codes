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
      lld n, i;
      cin >> n;
      lld j, s;
      lld dda[10][10];
      foi(i, 10)
      {
      	foi(j, 10)
      	{
      		dda[i][j] = 0;
      	}
      }
      for(i = 1; i <= n; i += 1)
      {
      	lld z = log10(i +0);
      	lld x = i/pow(10,z);
      	lld y = i%10;
      	dda[x][y]+=1;
      }
      s = 0;
      for(i = 1; i < 10; i += 1)
      {
      	for(j = 1;j<10;j+=1)
      	{
      		s += dda[i][j] * dda[j][i];
      	}
      }
      cout<< s;
      return 0;
}