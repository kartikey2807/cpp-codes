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
lld gcd (lld a, lld b)
{
	lld max = a > b ? a : b;
	lld min = a < b ? a : b;
	while(min){
		lld rem = max%min;
		max = min;
		min = rem;
	}
	return max;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld l, r, x, y;
      cin >> l >> r >> x >> y;
      if (y%x != 0)
      	{cout << "0"; return 0;}
      lld p = y/x;
      lld cnt = 0;
      for(lld i = 1; i <= sqrt(p); i += 1){
      	if (p%i == 0){
      		lld a = i;
      		lld b = p/i;
      		if ((a*x >= l && a*x <= r) && (b*x >= l && b*x <= r) && gcd(a,b) == 1){
      			if (a == b)
      				cnt += 1;
      			else  cnt += 2;
      		}
      	}
      }
      cout << cnt;
      return 0;
}