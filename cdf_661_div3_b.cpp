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
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n;
      	cin >> n;
      	lld A[n],B[n];
      	for(lld i = 0; i < n; i += 1){
      		cin >> A[i];
      	}
      	for(lld i = 0; i < n; i += 1){
      		cin >> B[i];
      	}
      	psort(A,B,n);
      	lld ans = MAX;
      	for(lld i = 0; i < n; i += 1){
      		ans = min(ans,B[i]);
      	}
      	lld moves = 0;
      	for(lld i = 1; i < n; i += 1){
      		lld d1 = A[i]-A[i-1];
      		lld d2 = B[i]-ans;
      		if (d2 < d1){
      			moves += d2;
      			A[i]  -= d2;
      			B[i]  -= d2;
      			moves += (A[i]-A[i-1]);
      			A[i] = A[i-1];
      		}
      		else{
      			moves += d1;
      			A[i]  -= d1;
      			B[i]  -= d1;
      		}
      	}
      	for(lld i = 0; i < n; i += 1){
      		moves += B[i]-ans;
      	}
      	cout << moves << "\n";
      }
      return 0;
}