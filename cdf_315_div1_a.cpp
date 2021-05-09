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
#define LEN 2000000
lld prime[LEN];
void sieve ()
{
	prime[0] = 0;
	prime[1] = 0;
	for(lld i = 2; i < LEN; i += 1){
		prime[i] = 1;
	}
	for(lld i = 4; i < LEN; i += 2){
		prime[i] = 0;
	}
	for(lld i = 3; i*i<LEN; i += 1){
		if (prime[i]){
			for(lld j = i*i; j < LEN; j += i)
				prime[j] = 0;
		}
	}
}
lld palin (lld x)
{
	vector  <lld>  ans;
	while(x){
		ans.pb(x%10);
		x/=10;
	}
	lld len = ans.size();
	for(lld i = 0; i < len/2; i += 1){
		if (ans[i] != ans[len-i-1])
			return 0;
	}
	return 1;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      sieve();
      lld p, q;
      cin >> p >> q;
      lld pi = 0, rub = 0;
      lld res= 0;
      for(lld i = 1; i < LEN; i += 1){
      	if (prime[i])
      		pi++;
      	if (palin(i))
      		rub++;
      	if ((q*pi) <= (p*rub))
      		res = i;
      }
      if (res > 0) cout << res;
      else cout << "Palndromic tree is better than splay tree";
      return 0;
}