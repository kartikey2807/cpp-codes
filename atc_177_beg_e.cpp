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
#define len 1000010
lld spf[len];
void sieve ()
{
	spf[0] = 1;
	spf[1] = 1;
	for(lld i = 2; i < len; i += 1){
		spf[i] = i;
	}
	for(lld i = 2; i < len; i += 2){
		spf[i] = 2;
	}
	for(lld i = 3; i*i<len; i += 1){
		if (spf[i] == i){
			for(lld j = i*i; j < len; j += i){
				if (spf[j] == j)
					spf[j]= i;
			}
		}
	}
}
set <lld> fact (lld x)
{
	set <lld> ans;
	while(x != 1){
		ans.insert(spf[x]);
		x /= spf[x];
	}
	return ans;
}
lld gcd_ (lld a, lld b)
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
      sieve();
      lld n;
      cin >> n;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      map <lld, lld> mac;
      for(lld i = 0; i < n; i += 1){
      	set <lld> s= fact(A[i]);
      	for(auth itr = s.begin(); itr != s.end(); itr++)
      		mac[*itr]++;
      }
      lld f = 1;
      for(map <lld, lld> :: iterator itr = mac.begin(); itr != mac.end(); itr++)
      	if (itr->second > 1)
      		f = 0;
      if (f == 1) {cout << "pairwise coprime"; return 0;}

      lld g = A[0];
      for(lld i = 0; i < n; i += 1){
      	g = gcd_(g, A[i]);
      }
      if (g == 1) {cout << "setwise coprime";  return 0;}

      cout << "not coprime";
      return 0;
}