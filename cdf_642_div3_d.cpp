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
#define LEN 200010
set <pair <lld, lld> > pos[LEN];
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t;
      cin >> t;
      while(t--){
      	lld n;
      	cin >> n;
      	set <lld> len;
      	len.insert(n);
      	pos[n].insert({0,n-1});
      	vector <lld> arr(n);
      	lld cnt = 1;
      	while(!len.empty()){
      		set <lld> :: iterator itr = len.end();
      		itr--;
      		set <pair <lld, lld> > :: iterator loc = pos[*itr].begin();
      		lld l = (*loc).first;
      		lld r = (*loc).second;
      		lld m = (r-l+1)%2 == 0 ? (l+r-1)/2 : (l+r)/2;
      		arr[m] = cnt;
      		pos[*itr].erase({l,r});
      		if (pos[*itr].empty())
      			len.erase(*itr);
      		// m+1 to r
      		// l to m-1
      		if (m+1 <= r) {lld len1 = r-(m+1)+1; len.insert(len1); pos[len1].insert({m+1,r});}
      		if (l <= m-1) {lld len2 = (m-1)-l+1; len.insert(len2); pos[len2].insert({l,m-1});}
      		cnt++;
      	}
      	for(lld i = 0; i < n; i += 1)
      		cout << arr[i] << " ";
      	cout << "\n";
      }
      return 0;
}