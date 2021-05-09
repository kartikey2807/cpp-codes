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
#define auth set <lld> :: iterator
#define pb push_back
lld gcd (lld a, lld b)
{
	lld ma = max(a,b);
	lld mi = min(a,b);
	while(mi){
		lld re = ma%mi;
		ma = mi;
		mi = re;
	}
	return ma;
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
      	lld n;
      	cin >> n;
      	lld A[n];
      	set <lld> vis;
      	map <lld, lld> mac;
      	for(lld i = 0; i < n; i += 1){
      		cin >> A[i];
      		mac[A[i]]++;
      		vis.insert(A[i]);
      	}
      	lld C[n];
      	lld ans = MIN;
      	for(lld i = 0; i < n; i += 1){
      		ans = max(ans, A[i]);
      	}
      	C[0] = ans;
      	mac[ans]--;
      	if (mac[ans] == 0)
      		vis.erase(ans);
      	lld val = C[0];
      	vector <lld> v;
      	v.pb(ans);
      	for(lld i = 1; i < n; i += 1){
      		lld ans = MIN;
      		lld pos;
      		for(auth itr = vis.begin(); itr != vis.end(); itr++){
      			if (gcd(val,(*itr)) > ans){
					ans=gcd(val, (*itr));
					pos = *itr;
				}
      		}
      		// for(set <lld> :: reverse_iterator itr = vis.rbegin(); itr != vis.rend(); itr++){
      		// 	if (gcd(val,(*itr)) > ans){
      		// 		ans=gcd(val, (*itr));
      		// 		pos = *itr;
      		// 	}
      		// }
      		mac[pos]--;
      		if (mac[pos] == 0)
      			vis.erase(pos);
      		val = gcd(val,pos);
      		C[i]= val;
      		v.pb(pos);
      	}
      	for(lld i = 0; i < v.size(); i += 1)
      		cout << v[i] << " ";
      	cout << "\n";
      }
      return 0;
}