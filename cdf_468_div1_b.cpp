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
vector <vector <char> > v[26];
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string s;
      cin >> s;
      string r = s + s;
      lld m = s.size();
      for(lld i = 0; i < m; i += 1){
      	vector <char> ans;
      	for(lld j = i; j<i+m; j += 1){
      		ans.pb(r[j]);
      	}
      	v[(lld)r[i]-97].pb(ans);
      }
      dbl sum = 0;
      for(lld k = 0; k < 26; k += 1){
      	lld val = MIN;
      	for(lld j = 0; j < m; j += 1){
      		vector <lld> cnt(26);
      		for(lld i = 0; i < v[k].size(); i += 1){
      			cnt[(lld)v[k][i][j]-97]++;
      		}
      		lld c = 0;
      		for(lld i = 0; i <  cnt.size(); i += 1){
      			if (cnt[i] == 1)
      				c++;
      		}
      		val = max(val,c);
      	}
      	sum+= val;
      }
      dbl dm = (dbl)m;
      cout << fixed << setprecision(15) << sum/dm;
      return 0;
}