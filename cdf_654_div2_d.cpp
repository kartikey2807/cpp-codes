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
      	lld n, k;
      	cin >> n >> k;
      	lld dda[n][n];
      	for(lld i = 0; i < n; i += 1){
      		for(lld j = 0; j < n; j += 1){
      			dda[i][j] = 0;
      		}
      	}
      	lld pos[n];
      	for(lld i = 0; i < n; i += 1){
      		pos[i] = i;
      	}
      	while(k){
      		for(lld i = 0; i < n; i += 1){
      			dda[i][pos[i]] = 1;
      			k--;
      			pos[i] = (pos[i]+1)%n;
      			if (k == 0)
      				break;
      		}
      	}
      	lld max_r = MIN, max_c = MIN;
      	lld min_r = MAX, min_c = MAX;
      	for(lld i = 0; i < n; i += 1){
      		lld sum = 0;
      		for(lld j = 0; j < n; j += 1){
      			sum += dda[i][j];
      		}
      		max_r = max(max_r,sum);
      		min_r = min(min_r,sum);
      	}
      	for(lld j = 0; j < n; j += 1){
      		lld sum = 0;
      		for(lld i = 0; i < n; i += 1){
      			sum += dda[i][j];
      		}
      		max_c = max(max_c,sum);
      		min_c = min(min_c,sum);
      	}
      	cout << pow(max_r-min_r,2) + pow(max_c-min_c,2) << "\n";
      	for(lld i = 0; i < n; i += 1){
      		for(lld j = 0; j < n; j += 1){
      			cout << dda[i][j];
      		}
      		cout << "\n";
      	}
      }
      return 0;
}