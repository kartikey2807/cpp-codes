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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld X[n],H[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> X[i] >> H[i];
      }
      if (n == 1) {cout << "1"; return 0;}
      lld cnt = 1;
      lld lim = X[0];
      for(lld i = 1; i<n-1; i += 1){
      	if (X[i]-H[i] > lim){
      		cnt++;
      		lim = X[i];
      	}
      	else{
      		if (X[i]+H[i] < X[i+1]){
      			cnt++;
      			lim = X[i]+H[i];
      		}
      		else  lim = X[i];
      	}
      }
      cout << cnt+1;
      return 0;
}