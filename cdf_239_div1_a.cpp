// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. do not use
// complex data structures if double matrix can be used..
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
#define LEN 1000
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      dbl a, b;
      cin >> a >> b;
      dbl aa = (a*a);
      dbl bb = (b*b);
      dbl cc = (a*a)+(b*b);
      pair <dbl, dbl> p1 = make_pair(0,0);
      for(dbl x = -1*LEN; x <= LEN; x ++){
      	dbl d = sqrt(bb-pow(0-x,2));
      	if (d == floor(d)){
      		dbl y = 0+d;
      		if (x != 0 && y != 0){
      			for(dbl altx = -1*LEN; altx <= LEN; altx ++){
      				dbl d = sqrt(cc-pow(0-altx,2));
      				if (d == floor(d)){
      					dbl alty=d;
      					if (altx != 0 && alty != 0){
      						if (pow(altx-x,2)+pow(alty-y,2) == aa){
      							cout << "YES\n";
      							cout << "0 0\n";
      							cout << x << " " << y << "\n";
      							cout << altx << " " << alty << "\n";
      							return 0;
      						}
      					}
      				}
      			}
      		}
      	}
      }
      cout << "NO\n";
      return 0;
}