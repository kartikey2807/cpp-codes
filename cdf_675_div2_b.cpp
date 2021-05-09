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
lld get_ (lld x, lld a, lld b, lld c, lld d)
{
	return abs(x-a)+abs(x-b)+abs(x-c)+abs(x-d);
}
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
      	lld dda[n][m];
      	for(lld i = 0; i < n; i += 1){
      		for(lld j = 0; j < m; j += 1){
      			cin >> dda[i][j];
      		}
      	}
      	lld cnt = 0;
      	for(lld i = 0; i<n/2; i += 1){
      		for(lld j = 0; j<m/2; j += 1){
      			lld c[4];
      			c[0] = get_(dda[i][j], dda[i][j], dda[i][m-j-1], dda[n-i-1][j], dda[n-i-1][m-j-1]); c[1] = get_(dda[i][m-j-1], dda[i][j], dda[i][m-j-1], dda[n-i-1][j], dda[n-i-1][m-j-1]); c[2] = get_(dda[n-i-1][j], dda[i][j], dda[i][m-j-1], dda[n-i-1][j], dda[n-i-1][m-j-1]); c[3] = get_(dda[n-i-1][m-j-1], dda[i][j], dda[i][m-j-1], dda[n-i-1][j], dda[n-i-1][m-j-1]);
      			cnt += min(min(c[0],c[1]), min(c[2],c[3]));
      		}
      	}
      	if (n%2){
      		for(lld j = 0; j<m/2; j += 1)
      			cnt += abs(dda[n/2][j]-dda[n/2][m-j-1]);
      	}
      	if (m%2){
      		for(lld i = 0; i<n/2; i += 1)
      			cnt += abs(dda[i][m/2]-dda[n-i-1][m/2]);
      	}
      	cout << cnt << "\n";
      }
      return 0;
}