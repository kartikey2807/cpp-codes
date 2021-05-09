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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      lld D[m],H[m];
      for(lld i = 0; i < m; i += 1){
      	cin >> D[i] >> H[i];
      }
      lld f = 1;
      for(lld i = 1; i < m; i += 1){
      	if (abs(H[i]-H[i-1]) > (D[i]-D[i-1]))
      		f = 0;
      }
      if (f == 1){
      	lld ans = H[0]+(D[0]-1);
      	for(lld i = 1; i < m; i += 1){
      		lld diff = (D[i]-D[i-1])-abs(H[i]-H[i-1]);
      		diff/=2;
      		ans = max(ans,max(H[i],H[i-1])+diff);
      	}
      	cout << max(ans,H[m-1]+(n-D[m-1]));
      }
      else
      	cout << "IMPOSSIBLE";
      return 0;
}