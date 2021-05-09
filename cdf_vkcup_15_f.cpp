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
#define LEN 1000100
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
      lld dp[LEN];
      memset(dp, 0, sizeof(dp));
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	dp[A[i]]= 1;
      }
      sort(A,A+n);
      for(lld i = 1; i<LEN; i += 1){
      	if (dp[i] != 0){
      		for(lld j = 2*i; j < LEN; j += i){
      			if (dp[j] != 0){
      				dp[j] = max(dp[j], dp[i]+1);
      			}
      		}
      	}
      }
      lld ans = MIN;
      for(lld i = 1; i<LEN; i += 1){
      	ans = max(ans, dp[i]);
      }
      cout << ans;
      return 0;
}