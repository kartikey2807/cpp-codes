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
dbl get_ (lld a, lld b, dbl c)
{
	dbl x = (dbl)(a+1);
	dbl y = (dbl)b;
	dbl m = (dbl)c;
	return y-(m*x);
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
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      map <dbl, set <lld> > slope;
      map <dbl, set <dbl> > inter;
      for(lld i = 0; i < n; i += 1){
      	for(lld j = i+1; j < n; j += 1){
      		dbl den = (dbl)(j-i);
      		dbl num =  A[j]-A[i];
      		slope[num/den].insert(i); slope[num/den].insert(j);
      		inter[num/den].insert(get_(i,A[i],num/den));
      		inter[num/den].insert(get_(j,A[j],num/den));
      	}
      }
      lld f = 0;
      for(map <dbl, set <lld> > :: iterator itr = slope.begin(); itr != slope.end(); itr++){
      	dbl p = itr->first;
      	if ((slope[p].size() == n && inter[p].size() == 2) || (slope[p].size() == n-1 && inter[p].size() == 1))
      		f = 1;
      }
      if (f == 0) cout << "No";
      else cout << "Yes";
      return 0;
}