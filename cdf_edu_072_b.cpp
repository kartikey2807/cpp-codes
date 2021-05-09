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
      	lld n, x;
      	cin >> n >> x;
      	lld D[n],H[n];
      	for(lld i = 0; i < n; i += 1){
      		cin >> D[i] >> H[i];
      	}
      	lld f = 0;
      	for(lld i = 0; i < n; i += 1){
      		if (x <= D[i])
      			f = 1;
      	}
      	if (f == 1)
      		{cout << "1\n"; continue;}
      	else{
      		lld g = 0;
      		for(lld i = 0; i < n; i += 1){
      			if (D[i] > H[i])
      				g = 1;
      		}
      		if (g == 0)
      			{cout << "-1\n"; continue;}
      		else{
      			lld ans = MIN;
      			for(lld i = 0; i < n; i += 1){
      				if (D[i] > H[i])
      					ans = max(ans, D[i]-H[i]);
      			}
      			lld tot = MAX;
      			for(lld i = 0; i < n; i += 1){
      				lld cnt = (x-D[i])/ans;
      				if ((x-D[i])%ans == 0)
      					cnt+=1;
      				else
      					cnt+=2;
      				tot = min(tot, cnt);
      			}
      			cout << tot << "\n";
      		}
      	}
      }
      return 0;
}