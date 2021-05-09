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
      lld n;
      cin >> n;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      lld start = 0;
      map <lld, lld> cnt;
      vector <pair <lld, lld> > v;
      for(lld i = 0; i < n; i += 1){
      	cnt[A[i]]++;
      	if (cnt[A[i]] == 2){
      		v.push_back({start,i});
      		start = i+1;
      		cnt.clear();
      	}
      }
      if (v.empty()){cout << "-1\n"; return 0;}
      else{
      	lld len = v.size()-1;
      	cout << len+1 <<"\n";
      	for(lld i = 0; i < len; i += 1)
      		cout << v[i].first+1 << " " << v[i].second+1 << "\n";
      	cout << v[len].first+1 << " " << n;
      }
      return 0;
}