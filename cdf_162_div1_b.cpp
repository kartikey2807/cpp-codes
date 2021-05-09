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
#define LEN 100010
lld spf[LEN];
void seive ()
{
	spf[1] = 1;
	for(lld i = 2; i < LEN; i += 1){
		spf[i] = i;
	}
	for(lld i = 2; i < LEN; i += 2){
		spf[i] = 2;
	}
	for(lld i = 3; i*i<LEN; i += 1){
		if (spf[i] == i){
			for(lld j = i*i; j < LEN; j += i){
				if (spf[j] == j)
					spf[j]= i;
			}
		}
	}
}
set <lld> get_fact (lld x)
{
	set <lld> an;
	while(x != 1)
		{an.insert(spf[x]); x/=spf[x];}
	return an;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      seive();
      lld n;
      cin >> n;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      if (n == 1)
      	{cout << "1"; return 0;}
      set <lld> fac;
      map <lld, lld> cnt;
      for(lld i = n-1; i >= 0; i--){
      	if (A[i] == 1)
      		continue;
      	fac.clear();
      	lld ans = MIN;
      	fac = get_fact(A[i]);
      	for(set <lld> :: iterator itr = fac.begin(); itr != fac.end(); itr++)
      		ans = max(ans, cnt[(*itr)]);
      	ans++;
      	for(set <lld> :: iterator itr = fac.begin(); itr != fac.end(); itr++)
      		cnt[(*itr)] = ans;
      }
      lld acc = MIN;
      for(map <lld, lld> :: iterator  itr = cnt.begin(); itr != cnt.end(); itr++)
      	acc = max(acc, itr->second);
      cout << acc;
      return 0;
}