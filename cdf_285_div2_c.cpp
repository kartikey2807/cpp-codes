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
#define auth set <lld> :: iterator
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
 	lld A[n],B[n];
 	set <lld> vis[n];
 	map <lld, lld> mac, ans;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i] >> B[i];
      	vis[A[i]].insert(i);
      	mac[i] = A[i];
      	ans[i] = B[i];
      }
      vector <pair<lld,lld> > v;
      while(!vis[1].empty()){
      	auth itr = vis[1].begin();
      	lld x  = (*itr);
      	vis[1].erase(x);
      	v.push_back({x,ans[x]});
      	mac[ans[x]]--;
      	ans[ans[x]] = ans[ans[x]] xor x;
      	vis[mac[ans[x]]].insert(ans[x]);
      	vis[mac[ans[x]]+1].erase(ans[x]);
      }
      cout << v.size() << "\n";
      foi(i, v.size())
      	cout << v[i].first << " " << v[i].second << "\n";
      return 0;
}