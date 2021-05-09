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
      lld t;
      cin >> t;
      while(t--){
      	lld n, m, k;
      	cin >> n >> m >> k;
      	if (k < max(n, m)){
      		cout << "-1";
      	}
      	else{
      		lld a1 = min(n,m), a2 = max(n,m);
      		lld dmove = a1;
      		if ((a2-a1)%2){
      			dmove += (a2-a1-1);
      			k -= dmove;
      			dmove += k-1;
      		}
      		else{
      			dmove += (a2-a1);
      			k -= dmove;
      			if (k%2)
      				dmove += k-2;
      			else
      				dmove += k-0;
      		}
      		cout << dmove;
      	}
      	cout << "\n";
      }
      return 0;
}