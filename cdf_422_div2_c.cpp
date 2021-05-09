// NEVER USE STRING DIRECTLY. IF THERE ARE CHARACTERS
// USE CHAR ARRAY OTHERWISE CHANGE IT INTO NUMBER
// ARRAY. IT SPAWNS TRAGEDY, IT HAS ALREADY HAPPENED
// TWICE. PLEASE NEVER AGAIN. :(
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
map <lld, vector <lld> > val;
map <pair <lld,lld>,lld> mac;
map <lld, vector <lld> > cst;
map <lld, lld> len;
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      // READ UPPER CLAUSE
      lld n, x;
      cin >> n >> x;
      pair <lld, lld> A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i].first >> A[i].second;
      	lld cost;
      	cin >> cost;
      	if (!mac.count(A[i]))
      		mac[A[i]] = cost;
      	else  mac[A[i]] = min(mac[A[i]],cost);
      }
      for(map <pair <lld,lld>,lld> :: iterator itr = mac.begin(); itr != mac.end(); itr++){
      	val[(itr->first).second-(itr->first).first+1].pb((itr->first).first);
      }
      for(map <lld, vector <lld> > :: iterator itr = val.begin(); itr != val.end(); itr++){
      	vector <lld> v = itr->second;
      	sort(v.begin(),v.end());
      	itr->second = v;
      }
      for(map <lld, vector <lld> > :: iterator itr = val.begin(); itr != val.end(); itr++){
      	lld ans = MAX;
      	lld dur = itr->first;
      	vector <lld> v = itr->second;
      	for(lld i = v.size()-1; i >= 0; i -= 1){
      		ans = min(ans,mac[make_pair(v[i],v[i]+dur-1)]);
      		cst[dur].pb(ans);
      	}
      	reverse(cst[dur].begin(),cst[dur].end());
      }
      for(map <lld, vector <lld> > :: iterator itr = val.begin(); itr != val.end(); itr++){
      	len[itr->first] = (itr->second).size();
      }
      lld f = 0;
      lld ans = MAX;
      for(lld i = 0; i < n; i += 1){
      	lld d = A[i].second-A[i].first+1;
      	lld r = x-d;
      	if (len[r]  == 0)
      		continue;
      	lld upp = upper_bound(val[r].begin(),val[r].end(),A[i].second) - val[r].begin();
      	if (upp < len[r]){
      		f = 1;
      		ans = min(ans,cst[r][upp]+mac[A[i]]);
      	}
      }
      if (f == 0) cout << "-1";
      else cout << ans;
      return 0;
}