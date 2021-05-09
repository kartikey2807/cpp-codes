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
lld ans[LEN];
lld val[LEN];
lld pow_ (lld x)
{
	vector <lld> res;
	while(x){
		res.pb(x%2);
		x/=2;
	}
	for(lld i = 0; i < res.size(); i += 1)
		if (res[i] == 1)
			return (pow(2,i));
}
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
      lld sum, limit;
      cin >> sum >> limit;
      for(lld i = 1; i <= limit; i += 1){
      	ans[i] = pow_(i);
      	val[i] = i;
      }
      lld tot = 0;
      for(lld i = 1; i <= limit; i += 1){
      	tot += ans[i];
      }
      if (tot < sum) {cout << "-1"; return 0;}
      psort(ans,val,limit+1);
      vector <lld> v;
      for(lld i = limit; i >= 1; i -= 1){
      	if (sum == 0)
      		break;
      	if (sum >= ans[i]){
      		sum-=ans[i];
      		v.pb(val[i]);
      	}
      }
      cout << v.size() << "\n";
      for(lld i = 0; i < v.size(); i += 1)
      	cout << v[i] << " ";
      return 0;
}