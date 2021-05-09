// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. do not use
// complex data structures if double matrix can be used..
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
#define mp make_pair
#define LEN 2000
lld dda[LEN][LEN];
lld dp1[LEN][LEN];
lld dp2[LEN][LEN];
lld dp3[LEN][LEN];
lld dp4[LEN][LEN];
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      for(lld i = 1; i <= n; i += 1)
      	for(lld j = 1; j <= m; j += 1)
      		cin >> dda[i][j];
      for(lld i = 1; i <= n; i += 1)
      	for(lld j = 1; j <= m; j += 1)
      		dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1]) + dda[i][j];
      for(lld i = 1; i <= n; i += 1)
      	for(lld j = m; j >= 1; j -= 1)
      		dp2[i][j] = max(dp2[i-1][j],dp2[i][j+1]) + dda[i][j];
      for(lld i = n; i >= 1; i -= 1)
      	for(lld j = 1; j <= m; j += 1)
      		dp3[i][j] = max(dp3[i+1][j],dp3[i][j-1]) + dda[i][j];
      for(lld i = n; i >= 1; i -= 1)
      	for(lld j = m; j >= 1; j -= 1)
      		dp4[i][j] = max(dp4[i+1][j],dp4[i][j+1]) + dda[i][j];
      lld ans = MIN;
      for(lld i = 2; i < n; i += 1){
      	for(lld j = 2; j < m; j += 1){
      		lld ans1 = dp1[i-1][j]+dp4[i+1][j]+dp2[i][j+1]+dp3[i][j-1];
      		lld ans2 = dp1[i][j-1]+dp4[i][j+1]+dp2[i-1][j]+dp3[i+1][j];
      		ans = max(ans,max(ans1,ans2));
      	}
      }
      cout << ans;
      return 0;
}