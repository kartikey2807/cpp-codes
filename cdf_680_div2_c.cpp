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
set <lld> fac;
map <lld, lld> cnt;
void get (lld x)
{
	while(x%2 == 0){
		x /= 2;
		cnt[2]++;
		fac.insert(2);
	}
	for(lld i = 3; i <= sqrt(x); i += 2){
		while(x%i == 0){
			x /= i;
			cnt[i]++;
			fac.insert(i);
		}
	}
	if (x > 2){
		cnt[x]++;
		fac.insert(x);
	}
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
      	lld p, q;
      	cin >> p >> q;
      	if (p%q == 0){
      		fac.clear();
      		cnt.clear();
      		get(q);
      		lld ans = MIN;
      		for(auth itr = fac.begin(); itr != fac.end(); itr++){
      			lld temp = p;
      			lld d = *itr;
      			lld tot = 0;
      			while(temp%d == 0){
      				tot++;
      				temp /= d;
      			}
      			lld c = 0;
      			temp = p;
      			while(temp%d == 0){
      				if ((tot-c) < cnt[d])
      					break;
      				c++;
      				temp /= d;
      			}
      			ans = max(ans, temp);
      		}
      		cout << ans<< "\n";
      	}
      	else{
      		cout << p  << "\n";
      	}
      }
      return 0;
}