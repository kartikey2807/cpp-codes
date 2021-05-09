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
lld gdc_ (lld a, lld b)
{
	lld max = a > b ? a : b;
	lld min = a < b ? a : b;
	while (min != 0)
	{
		lld rem = max%min;
		max = min;
		min = rem;
	}
	return max;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n, i;
      cin >> n;
      lld A[n];
      lld B[n];
      lld m, j;
      lld x, s;
      m = 0;
      foi(i, n)
      {
      	cin >> A[i];
      	if (A[i]>m)
      	{
      		m = A[i];
      	}
      }
      j = 0;
      foi(i, n)
      {
      	if (m-A[i]!=0)
      	{
      		B[j] = m-A[i];
      		j++;
      	}
      }
      x = B [0];
      for(i = 1; i < j; i += 1){
      	x = gdc_(B [i] , x);
      }
      s = 0;
      foi(i, j)
      {
      	s+= B[i]/x;
      }
      cout << s << " "<<x<<"\n";
      return 0;
}