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
#define len 6
lld B[len];
lld ans;
void rec (lld p, lld A[])
{
	if (p == len){
		lld sum1 = 0, sum2 = 0;
		for(lld i = 0; i < len/2; i += 1)
			sum1 += B[i];
		for(lld i = len/2; i<len; i += 1)
			sum2 += B[i];
		if (sum1 == sum2){
			lld cnt = 0;
			for(lld i = 0; i < len; i += 1)
				if (A[i] != B[i])
					cnt++;
			ans = min(ans,cnt);
		}
		return;
	}
	for(lld i = 0; i < 10; i += 1){
		B[p]= i;
		rec(p+1,A);
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string s;
      cin >> s;
      lld A[len];
      for(lld i = 0; i < len; i += 1){
      	A[i] = (lld)s[i]-48;
      }
      ans = MAX;
      rec(0, A);
      cout << ans;
      return 0;
}