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
      lld n, m;
      cin >> n >> m;
      lld S[n],R[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> S[i] >> R[i];
      }
      vector <lld> v[m+1];
      for(lld i = 0; i < n; i += 1){
      	v[S[i]].pb(R[i]);
      }
      for(lld i = 1; i <=m; i += 1){
      	sort(v[i].begin(), v[i].end(), greater<lld>());
      }
      map <lld, lld> sum;
      for(lld i = 1; i <=m; i += 1){
      	lld acc = 0;
      	for(lld j = 0; j < v[i].size(); j += 1){
      		acc += v[i][j];
      		if (acc > 0)
      			sum[j+1] += acc;
      	}
      }
      lld ans = 0;
      for(map <lld, lld> :: iterator itr = sum.begin(); itr != sum.end(); itr++){
      	if (itr->second >= 0)
      		ans = max(ans, itr->second);
      }
      cout << ans;
      return 0;
}