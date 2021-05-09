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
      	lld dda[2][3];
      	cin >> dda[0][0] >> dda[0][1] >> dda[0][2];
      	cin >> dda[1][0] >> dda[1][1] >> dda[1][2];
      	lld sum = 0;
      	if (dda[0][2] <= dda[1][1]){
      		sum += 2*dda[0][2];
      		dda[1][1]-= dda[0][2];
      		dda[0][2] = 0;
      		lld x = min(dda[0][1], dda[1][1]);
      		dda[0][1]-= x;
      		dda[1][1]-= x;
      	}
      	else{
      		sum += 2*dda[1][1];
      		dda[0][2]-= dda[1][1];
      		dda[1][1] = 0;
      		lld x = min(dda[0][2], dda[1][2]);
      		dda[0][2] -= x;
      		dda[1][2] -= x;
      	}
      	lld j = 2;
      	while(dda[0][0]){
      		lld x = min(dda[0][0], dda[1][j]);
      		dda[0][0] -= x;
      		dda[1][j] -= x;
      		j--;
      	}
      	lld k = 2;
      	while(dda[1][0]){
      		lld x = min(dda[1][0], dda[0][k]);
      		dda[1][0] -= x;
      		dda[0][k] -= x;
      		k--;
      	}
      	sum -= 2*min(dda[0][1], dda[1][2]);
      	cout << sum << "\n";
      }
      return 0;
}