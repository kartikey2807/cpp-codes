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
      lld t, l;
      cin >> t;
      foi(l,t){
      	dbl ang;
      	cin >> ang;
      	if (ang == 180)
      		{cout << "-1"; continue;}
      	for(dbl i = 3; i <= 1000; i += 1){
      		dbl x = (((2*i)-4)*90)/i;
      		dbl y = x/(i-2);
      		dbl p = 1;
      		lld f = 0;
      		while(true){
      			if (p > (i-2)){
      				break;
      			}
      			if (y*p== ang){
      				f = i;
      				break;
      			}
      			p++;
      		}
      		if (f != 0) {cout << i; break;}
      	}
      	cout << "\n";
      }
      return 0;
}