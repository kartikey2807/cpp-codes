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
#define len 1000000000
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld C[n],D[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> C[i] >> D[i];
      }
      lld cnt = 0;
      for(lld i = 0; i < n; i += 1){
      	if (D[i] == 1)
      		cnt++;
      }
      if (cnt == n){
      	cout << "Infinity";
      }
      else{
      	pair <lld, lld> limit = (D[0] == 1) ? make_pair(1900,len) : make_pair(-1*len,1899);
      	lld f = 1;
      	for(lld i = 0; i < n; i += 1){
      		limit.first += C[i];
      		limit.second+= C[i];
      		if (i == n-1)
      			break;
      		if (D[i+1] == 2){
      			if (limit.first <= 1899) {limit.second = min((lld)1899,limit.second);}
      			else {cout << "Impossible"; return 0;}
      		}
      		if (D[i+1] == 1){
      			if (limit.second >= 1900) {limit.first = max((lld)1900, limit.first);}
      			else {cout << "Impossible"; return 0;}
      		}
      	}
      	cout << limit.second;
      }
      return 0;
}