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
#define MOD 1000000007
void no () {cout << "NO\n";}
void yes() {cout << "YES\n";}
lld pow_ (lld a, lld n)
{
	if (n == 0) return 1;
	if (n == 1) return a;
	if (n%2==0) return ((pow_(a,n/2)%MOD)*(pow_(a,n/2)%MOD))%MOD;
	else return ((((pow_(a,n/2)%MOD)*(pow_(a,n/2)%MOD))%MOD)*(a%MOD))%MOD;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, q;
      string s;
      cin >> n >> q >> s;
      lld o = 0;
      lld z = 0;
      vector <pair<lld,lld> >v(n+1);
      v[0] = make_pair(0,0);
      for(lld i = 0; i < n; i += 1){
      	if (s[i] == '1')
      		o++;
      	if (s[i] == '0')
      		z++;
      	v[i+1] = make_pair(o,z);
      }
      for(lld i = 0; i < q; i += 1){
      	lld l, r;
      	cin >> l >> r;
      	lld len = r-l+1, ones = v[r].first-v[l-1].first;
      	lld a = pow_(2,len-ones)%MOD, b = ((pow_(2,ones)%MOD)-(1%MOD))%MOD;
      	if (b < 0)
      		b += MOD;
      	cout << ((a%MOD)*(b%MOD))%MOD << "\n";
      }
      return 0;
}