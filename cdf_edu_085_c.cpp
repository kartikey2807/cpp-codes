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
      		cin >> A[i] >> B[i];
      	}
      	lld T[n];
      	for(lld i = 0; i < n; i += 1){
      		T[i] = A[i];
      	}
      	lld sum = 0;
      	for(lld i = 0; i < n; i += 1){
      		if (T[i] > 0)
      			sum += T[i];
      		if (i == n-1)
      			continue;
      		T[i+1] = max(T[i+1]-B[i], (lld)0);
      	}
      	lld j = n-1;
      	lld ans = sum;
      	for(lld i = 0; i<n-1; i += 1){
      		sum -= (A[i]+T[i+1]);
      		sum += A[i+1];
      		sum += max((lld)0, A[i]-B[j]);
      		j = (j+1)%n;
      		ans = min(ans, sum);
      	}
      	cout << ans << "\n";
      }
      return 0;
}