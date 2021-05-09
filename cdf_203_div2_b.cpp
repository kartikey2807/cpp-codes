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
#define LEN 100010
#define pb push_back
lld hotel[LEN];
lld lenth[LEN];
lld vis[LEN];
lld cnt[LEN];
vector <lld> order;
lld err;
void dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	order.pb(pos);
	if (hotel[pos]== 1){
		err= 0;
		return;
	}
	if (lenth[pos] > 1){
		err=-2;
		return;
	}
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] != -1)
			err=cnt[v[pos][i]];
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs(v,v[pos][i]);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      for(lld i = 1; i <= n; i += 1){
      	cin >> hotel[i];
      }
      vector <lld> v[n+1];
      for(lld i = 1; i <= n; i += 1){
      	lld r;
      	cin >> r;
      	if (r != 0){
      		v[r].pb(i);
      		lenth[r]++;
      	}
      }
      memset(vis, -1, sizeof(vis));
      lld ans = MIN;
      lld pos;
      for(lld i = 1; i <= n; i += 1){
      	if (vis[i] == -1){
      		order.clear();
      		err = -1;
      		dfs(v,i);
      		if (err ==-1){
      			for(lld j = 0; j < order.size(); j += 1)
      				cnt[order[j]] = err;
      		}
      		else{
      			if (err == -2){
      				for(lld j = 0; j < order.size(); j += 1){
      					cnt[order[j]] = err;
      				}
      			}
      			else{
      				reverse(order.begin(), order.end());
      				for(lld j = 0; j < order.size(); j += 1){
      					err++;
      					cnt[order[j]] = err;
      				}
      				reverse(order.begin(), order.end());
      				if (err > ans){
      					ans=err;
      					pos=order[0];
      				}
      			}
      		}
      	}
      }
      cout << ans << "\n";
      while(hotel[pos] != 1){
      	cout<<pos<< " ";
      	pos = v[pos][0];
      }
      cout << pos << "\n";
      return 0;
}