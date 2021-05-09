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
	lld a, b;
	lld minimum = MAX;
	for(i = 1; i<=sqrt(n); i++)
	{
		if (n % i == 0)
		{
			lld min = i < (n/i) ? i : (n/i);
			lld max = i > (n/i) ? i : (n/i);
			while (min!= 0)
			{
				lld rem = max%min;
				max = min;
				min = rem;
			}
			if ((i*(n/i))%max == 0 && (i*(n/i))/max == n)
			{
				lld M = i > (n/i) ? i :(n/i);
				if (M <  minimum)
				{
					minimum = M;
					a = i;
					b = n/i;
				}
			}
		}
	}
	cout << a << " " << b  <<  "\n";
      return 0;
}