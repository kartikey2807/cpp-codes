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
#define auth set <lld> :: iterator
#define pb push_back
#define LEN 200010
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, k;
      cin >> n >> k;
      lld A[n];
      map <lld, lld> sum, cnt;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      sort(A,A+n);
      for(lld i = 0; i < n; i += 1){
      	lld temp = A[i];
      	lld moves = 0;
      	while(temp){
      		if (cnt[temp]< k)
      			{sum[temp] += moves; cnt[temp]++;}
      		temp /= 2;
      		moves+= 1;
      	}
      	if (cnt[temp] < k)
      		{sum[temp] += moves; cnt[temp]++;}
      }
      lld ans = MAX;
      for(lld i = 0; i < LEN; i += 1){
      	if (cnt[i] == k)
      		ans = min(ans, sum[i]);
      }
      cout << ans;
      return 0;
}