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
dbl mod_ (dbl x, dbl y)
{
	dbl q = x/y;
	q = floor(q);
	return (x-(y*q));
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      dbl a, d;
      lld n;
      cin >> a >> d >> n;
      lld edge = 1;
      dbl x = 0, y = 0;
      for(lld i = 0; i < n; i += 1){
      	dbl dist = mod_(d, 4*a);
      	if (edge == 1){
      		if (dist >= (a-x)){
      			dist-=(a-x);
      			x = a;
      			y = 0;
      			edge = 2;
      		}
      		else{
      			x+= dist;
      			y = 0;
      			dist = 0;
      		}
      	}
      	else{
      		if (edge == 2){
      			if (dist >= (a-y)){
      				dist-=(a-y);
      				x = a;
      				y = a;
      				edge = 3;
      			}
      			else{
      				y+= dist;
      				x = a;
      				dist = 0;
      			}
      		}
      		else{
      			if (edge == 3){
      				if (dist >= (x-0)){
      					dist-=(x-0);
      					x = 0;
      					y = a;
      					edge = 4;
      				}
      				else{
      					x-= dist;
      					y = a;
      					dist = 0;
      				}
      			}
      			else{
      				if (dist >= (y-0)){
      					dist-=(y-0);
      					x = 0;
      					y = 0;
      					edge = 1;
      				}
      				else{
      					y-= dist;
      					x = 0;
      					dist = 0;
      				}
      			}
      		}
      	}
      	while(dist){
      		if (dist >= a){
      			dist-=a;
      			if (edge == 2) {edge = 3; x = a; y = a; continue;}
      			if (edge == 3) {edge = 4; x = 0; y = a; continue;}
      			if (edge == 4) {edge = 1; x = 0; y = 0; continue;}
      			if (edge == 1) {edge = 2; x = a; y = 0; continue;}
      		}
      		else{
      			if (edge == 1) x += dist;
      			if (edge == 2) y += dist;
      			if (edge == 3) x -= dist;
      			if (edge == 4) y -= dist;
      			dist = 0;
      		}
      	}
      	cout << fixed << setprecision(10) << x << " " << y << "\n";
      }
      return 0;
}