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
void psort(lld A[], lld B[], lld n){
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
      lld n, k;
      cin >> n >> k;
      lld A[n],B[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      for(lld i = 0; i < n; i += 1){
      	cin >> B[i];
      }
      lld C[n],D[n],T[n];
      for(lld i = 0; i < n; i += 1){
      	C[i] = B[i]/A[i];
      	T[i] = B[i]/A[i];
      	D[i] = B[i]%A[i];
      }
      psort(C,D,n);
      psort(T,A,n);
      lld sum1 = 0, sum2 = 0, gap=0;
      for(lld i = 1; i < n; i += 1){
      	if (C[i] == C[i-1]){
      		sum1+=D[i-1];
      		sum2+=A[i-1];
      	}
      	else{
      		sum1+=D[i-1];
      		sum2+=A[i-1];
      		lld diff = C[i]-C[i-1];
      		if ((diff*sum2)-sum1 <= k){
      			k-= (diff*sum2)-sum1;
      			gap += diff;
      		}
      		else{
      			k+= sum1;
      			lld p = k/sum2;
      			for(lld j = 0; j < i; j += 1)
      				C[j] += p;
      			k = 0;
      			break;
      		}
      		sum1 = 0;
      	}
      }
      for(lld i = 0; i < n; i += 1)
      	C[i] += gap;
      if (k != 0){
      	lld sum = 0;
      	for(lld i = 0; i < n; i += 1){
      		sum += A[i];
      	}
      	lld q = k/sum;
      	for(lld i = 0; i < n; i += 1){
      		C[i] += q;
      	}
      }
      lld ans = MAX;
      for(lld i = 0; i < n; i += 1)
      	ans = min(ans,C[i]);
      cout << ans;
      return 0;
}