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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m, d;
      cin >> n >> m >> d;
      lld A[n];
      set <lld> vis;
      map <lld, lld> mac;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	vis.insert(A[i]);
      }
      vector <lld> order;
      lld len = vis.size(), cnt = 1;
      while(len){
      	order.clear();
      	auth itr = vis.begin();
      	lld x = *itr;
      	order.pb(x);
      	while (true){
      		lld y = x+d+1;
      		if (vis.count(y)){
      			x = y;
      			order.pb(x);
      		}
      		else{
      			vis.insert(y);
      			auth pos = vis.find(y);
      			pos++;
      			if (pos == vis.end()){
      				vis.erase(y);
      				break;
      			}
      			else{
      				x = *pos;
      				order.pb(x);
      				vis.erase(y);
      			}
      		}
      	}
      	for(lld i = 0; i < order.size(); i += 1){
      		len--;
      		vis.erase(order[i]);
      		mac[order[i]] = cnt;
      	}
      	cnt++;
      }
      lld ans = MIN;
      for(lld i = 0; i < n; i += 1)
      	ans = max(ans,mac[A[i]]);
      cout << ans << "\n";
      for(lld i = 0; i < n; i += 1)
      	cout << mac[A[i]] << " ";
      return 0;
}