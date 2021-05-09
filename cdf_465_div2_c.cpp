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
void set_ (dbl x, dbl y, dbl r) {cout << fixed << setprecision(16) << x << " " << y << " " << r;}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      dbl R;
      dbl x1, y1;
      dbl x2, y2;
      cin >> R >> x1 >> y1 >> x2 >> y2;
      dbl dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
      if (dist >= R){
      	set_(x1,y1,R);
      }
      else{
      	dbl t = 2,x, y;
      	if (dist == 0){
      		x = x1+R;
      		y = y1;
      	}
      	else{
      		x = (((dist+R)*x1)-(R*x2))/dist;
      		y = (((dist+R)*y1)-(R*y2))/dist;
      	}
      	dbl r = (dist+R)/t;
      	dbl mid_x = (x+x2)/t;
      	dbl mid_y = (y+y2)/t;
      	set_(mid_x,mid_y, r);
      }
      return 0;
}