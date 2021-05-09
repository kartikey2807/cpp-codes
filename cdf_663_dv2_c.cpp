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
#define MOD 1000000007
#define LEN 1000005
lld fac[LEN];
lld ifac[LEN];
lld inv[LEN];
void init_fac ()
{
	fac[0] = 1;
	fac[1] = 1;
	for(lld i = 2; i < LEN; i += 1){
		fac[i] = fac[i-1]*i%MOD;
	}
}
void init_ifac()
{
	ifac[0] = 1;
	ifac[1] = 1;
	inv [1] = 1;
	for(lld i = 2; i < LEN; i += 1){
		inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
		ifac[i]= ifac[i-1]*inv[i]%MOD;
	}
}
lld nCr_ (lld n, lld r)
{
	if (n < 0 || n < r || r < 0)
		return 0;
	return ((((fac[n]%MOD)*(ifac[r]%MOD))%MOD)*(ifac[n-r]%MOD))%MOD;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      init_fac();
      init_ifac();
      lld n;
      cin >> n;
      lld sum = 0;
      for(lld i = 1; i < n-1; i += 1){
      	lld left = n-1;
      	lld gap1 = n-1-i;
      	sum = ((sum%MOD)+(nCr_(left,gap1)%MOD))%MOD;
      }
      sum = ((sum%MOD)+2)%MOD;
      lld ans = ((fac[n]%MOD)-(sum%MOD))%MOD;
      if (ans < 0) cout << MOD+ans;
      else cout << ans;
      return 0;
}