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
lld xyz_ (lld a  , lld b)
{
	if (a > 0 && b > 0)
	{
		lld max = a > b ? a : b;
		lld min = a < b ? a : b;
		if (min > (max/2))
		{
			lld sum = 0;
			lld y = max - min;
			if (y != 0)
			{
				max-= (2*y);
				min-= (1*y);
				sum+= (y-0);
			}
			lld p = max % 3;
			lld q = max - p;
			q/=3;
			q*=2;
			if (p ==  2)
				q+= 1;
			return(y+q);
		}
		else
			return  min;
	}
	else
		return 0;
}
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
      	lld c, m;
      	lld x, s;
      	cin >> c;
      	cin >> m;
      	cin >> x;
      	if (c <= 0 || m <= 0)
      	{
      		cout <<  "0\n";
      	}
      	else
      	{
      		lld p = (x < m ? x : m) < c ? (x < m ? x : m) : c;
      		x-= p;
      		m-= p;
      		c-= p;
      		s = 0;
      		s+= p;
      		s+= xyz_(c, m);
      		cout <<s<<"\n";
      	}
      }
      return 0;
}