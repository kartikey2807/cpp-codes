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
lld solve (lld a, lld b, lld x, lld y, lld n)
{
	lld diff = a-x;
	if (n >= diff){
		n-=diff;
		a = x;
	}
	else{
		a-= n;
		n = 0;
	}
	diff = b-y;
	if (n >= diff){
		n-=diff;
		b = y;
	}
	else{
		b-= n;
		n = 0;
	}
	return (a*b);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld a, b, x, y, n;
      	cin >> a >> b >> x >> y >> n;
      	cout << min(solve(a,b,x,y,n),solve(b,a,y,x,n)) << "\n";
      }
      return 0;
}