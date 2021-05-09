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
      	lld n, x, y;
      	cin >> n >> x >> y;
      	lld ans = 2, diff = y-x;
      	for(lld i = 1; i <= 50; i += 1){
      		if ((y-x)%i == 0){
      			lld temp = (y-x)/i;
      			temp+=1;
      			if (temp <= n && temp > ans){
      				ans = temp;
      				diff = i;
      			}
      		}
      	}
      	n -= ans;
      	for(lld i = x; i <= y; i += diff)
      		cout << i << " ";
      	x -= diff;
      	while(n > 0 && x > 0){
      		cout << x << " ";
      		n--;
      		x -= diff;
      	}
      	y += diff;
      	while(n > 0){
      		cout << y << " ";
      		n--;
      		y += diff;
      	}
      	cout << "\n";
      }
      return 0;
}