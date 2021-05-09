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
void no () {cout << "NO\n";}
void yes() {cout << "YES\n";}
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
      	lld n, m;
      	cin >> n >> m;
      	lld dda[n][4];
      	for(lld i = 0; i < n; i += 1){
      		cin >> dda[i][0] >> dda[i][1] >> dda[i][2] >> dda[i][3];
      	}
      	if (m%2 != 0){
      		no();
      	}
      	else{
      		lld f = 0;
      		for(lld i = 0; i < n; i += 1){
      			if (dda[i][1] == dda[i][2])
      				f = 1;
      		}
      		if (f == 0) no();
      		else yes();
      	}
      }
      return 0;
}