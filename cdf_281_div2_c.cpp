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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      cin >> m;
      lld B[m];
      for(lld i = 0; i < m; i += 1){
      	cin >> B[i];
      }
      sort(A,A+n);
      sort(B,B+m);

      vector <lld> ans;
      ans.pb(0);
      for(lld i = 0; i < n; i += 1){
      	ans.pb(A[i]+0);
      	ans.pb(A[i]+1);
      }
      for(lld i = 0; i < m; i += 1){
      	ans.pb(B[i]+0);
      	ans.pb(B[i]+1);
      }
      lld res = MIN;
      for(lld i = 0; i < ans.size(); i += 1){
      	lld pos = upper_bound(A+0,A+n,ans[i])-(A+0), los = upper_bound(B+0,B+m,ans[i])-(B+0);
      	lld val1 = (pos*2)+((n-pos)*3), val2 = (los*2)+((m-los)*3);
      	if ((val1-val2) >= res){
      		res = val1-val2;
      	}
      }
      pair <lld, lld> p = make_pair(MIN,MIN);
      for(lld i = 0; i < ans.size(); i += 1){
      	lld pos = upper_bound(A+0,A+n,ans[i])-(A+0), los = upper_bound(B+0,B+m,ans[i])-(B+0);
      	lld val1 = (pos*2)+((n-pos)*3), val2 = (los*2)+((m-los)*3);
      	if ((val1-val2) == res){
      		if (val1>p.first)
      			p = make_pair(val1,val2);
      	}
      }
      cout << p.first << ":" << p.second;
      return 0;
}