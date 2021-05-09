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
void psort (lld A[], lld B[], lld n)
{
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1){
		P[i].first  = A[i];
		P[i].second = B[i];
	}
	sort(P,P+n);
	for(lld i = 0; i < n; i += 1){
		A[i] = P[i].first;
		B[i] = P[i].second;
	}
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
      lld l[n],r[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> l[i] >> r[i];
      }
      psort(r,l,n);
      psort(l,r,n);
      pair <lld, lld> up[n],dw[n];
      up[0] = make_pair(MIN, MAX);
      for(lld i = 1; i < n; i += 1){
      	up[i] = make_pair(max(up[i-1].first, l[i-1]), min(up[i-1].second, r[i-1]));
      }
      dw[n-1] = make_pair(MIN, MAX);
      for(lld i = n-2;i>=0; i -= 1){
      	dw[i] = make_pair(max(dw[i+1].first, l[i+1]), min(dw[i+1].second, r[i+1]));
      }
      pair <lld, lld> p;
      lld ans = MIN;
      for(lld i = 0; i < n; i += 1){
      	p = make_pair(max(up[i].first,dw[i].first),min(up[i].second,dw[i].second));
      	ans = max(ans, max((lld)0, p.second-p.first));
      }
      cout << ans;
      return 0;
}