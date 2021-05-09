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
lld get_pf (lld x)
{
	if (x == 1 || x == 2) {return -1;}
	while(x%2 == 0)
		{x/=2;}
	if (x == 1) {return 2;}
	for(lld i = 3; i <= sqrt(x); i += 2){
		while(x%i == 0)
			{return i; x/=i;}
	}
	if (x > 2)
		return x;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld x = get_pf(n);
      if (x == -1) {cout << "-1"; return 0;}
      if (x ==  2) {
      	lld fac = n/4;
      	cout << (3*fac) << " " << (5*fac);
      	return 0;
      }
      lld m = ((x*x)-1)/2;
      lld f = n/x;
      cout << m*f << " " << (m+1)*f;
      return 0;
}