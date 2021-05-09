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
map <pair<lld, lld>, lld> dist;
lld lev (lld a){
	lld c = 0;
	while(a != 1){a /= 2; c++;}
	return c;
}
lld get_root (lld x, lld y)
{
	if (x < y) swap(x,y);
	lld levx = lev(x);
	lld levy = lev(y);
	while(levx != levy){
		x /= 2;
		levx--;
	}
	while(x != y){
		x /= 2;
		y /= 2;
	}
	return x;
}
void update (lld x, lld y, lld w)
{
	lld root = get_root(x,y);
	while(x!=root){
		dist[{x,x/2}] += w;
		dist[{x/2,x}] += w;
		x/=2;
	}
	while(y!=root){
		dist[{y,y/2}] += w;
		dist[{y/2,y}] += w;
		y/=2;
	}
}
lld dist_path (lld x, lld y)
{
	lld root = get_root(x,y);
	lld sum = 0;
	while(x!=root){
		sum+=dist[{x,x/2}];
		x/=2;
	}
	while(y!=root){
		sum+=dist[{y,y/2}];
		y/=2;
	}
	return sum;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld q;
      cin >> q;
      for(lld i = 0; i < q; i += 1){
      	lld query;
      	cin >> query;
      	lld x, y, w;
      	if (query == 1){cin >> x >> y >> w; update(x,y,w);}
      	else{cin >> x >> y; cout << dist_path(x,y) <<"\n";}
      }
      return 0;
}