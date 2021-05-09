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
      lld n, m, k, x, s;
      cin >> n >> m >> k >> x >> s;
      lld A[m],B[m];
      lld C[k],D[k];
      for(lld i = 0; i < m; i += 1){
      	cin >> A[i];
      }
      for(lld i = 0; i < m; i += 1){
      	cin >> B[i];
      }
      for(lld i = 0; i < k; i += 1){
      	cin >> C[i];
      }
      for(lld i = 0; i < k; i += 1){
      	cin >> D[i];
      }
      psort(A,B,m);
      psort(B,A,m);
      for(lld i = 1; i < m; i += 1){
      	A[i] = min(A[i-1],A[i]);
      }
      lld ans;
      lld upp = upper_bound(B+0, B+m, s)-(B+0);
      if (upp > 0)
      	ans = n*A[upp-1];
      else  ans = n*x;
      for(lld i = 0; i < k; i += 1){
      	if (D[i] <= s){
      		// n-C[i]
      		// s-D[i]
      		lld left = max((lld)0,n-C[i]);
      		lld remn = s-D[i];
      		lld upp  = upper_bound(B+0,B+m,remn)-(B+0);
      		lld sum;
      		if (upp > 0)
      			sum = left*A[upp-1];
      		else
      			sum = left*x;
      		ans = min(ans,sum);
      	}
      }
      cout << ans;
      return 0;
}