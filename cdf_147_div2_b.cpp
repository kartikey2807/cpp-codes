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
      lld n;
      cin >> n;
      lld C[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> C[i];
      }
      vector <lld> v[n];
      map <lld, pair <lld, lld> > p;
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < C[i]; j += 1){
      		lld r;
      		cin >> r;
      		v[i].pb(r);
      		p[r] = {i,j};
      	}
      }
      lld cnt = 0;
      vector <pair <lld, lld> > kyo;
      vector <pair <lld, lld> > ryu;
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < C[i]; j += 1){
      		cnt++;
      		if (v[i][j] == cnt)
      			continue;
      		kyo.pb({i,j});
      		ryu.pb(p[cnt]);
      		lld temp = v[i][j];
      		v[i][j] = cnt;
      		v[p[cnt].first][p[cnt].second] = temp;
      		p[temp] = p[cnt];
      		p[cnt] = {i,j};
      	}
      }
      cout << ryu.size() << "\n";
      for(lld i = 0; i < ryu.size(); i += 1)
      	cout << kyo[i].first+1 << " " << kyo[i].second+1 << " " << ryu[i].first+1 << " " << ryu[i].second+1 << "\n";
      return 0;
}