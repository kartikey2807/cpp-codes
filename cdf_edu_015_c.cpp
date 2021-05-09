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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      lld C[n],T[m];
      for(lld i = 0; i < n; i += 1){
      	cin >> C[i];
      }
      set <lld> towers;
      for(lld i = 0; i < m; i += 1){
      	cin >> T[i];
      	towers.insert(T[i]);
      }
      map <lld, lld> dist;
      for(lld i = n-1; i >= 0; i -= 1){
      	if (towers.count(C[i]))
      		continue;
      	towers.insert(C[i]);
      	set <lld> :: iterator itr = towers.find(C[i]);
      	if (itr == towers.begin()){
      		itr++;
      		dist[*itr] = max(dist[*itr], abs(C[i]-(*itr)));
      	}
      	else{
      		set <lld> :: iterator pos = itr;
      		pos++;
      		if (pos == towers.end()){
      			itr--;
      			dist[*itr] = max(dist[*itr], abs(C[i]-(*itr)));
      		}
      		else{
      			set <lld> :: iterator a = itr; a++;
      			set <lld> :: iterator b = itr; b--;
      			if (abs(C[i]-(*a)) < abs(C[i]-(*b))) {dist[*a] = max(dist[*a], abs(C[i]-(*a)));}
      			else {dist[*b] = max(dist[*b], abs(C[i]-(*b)));}
      		}
      	}
      	towers.erase(C[i]);
      }
      lld ans = MIN;
      for(lld i = 0; i < m; i += 1)
      	ans = max(ans, dist[T[i]]);
      cout << ans;
      return 0;
}