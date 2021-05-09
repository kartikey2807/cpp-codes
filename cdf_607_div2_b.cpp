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
      lld q;
      cin >> q;
      while(q--){
      	string s, t;
      	cin >> s >> t;
      	lld n = s.size(),m = t.size();
      	lld g = 0;
      	for(lld i = 0; i < n; i += 1){
      		char ans = s[i];
      		lld pos = i;
      		for(lld j = i+1; j < n; j += 1){
      			if (s[j] <= ans){
      				ans = s[j];
      				pos = j;
      			}
      		}
      		swap(s[i],s[pos]);
      		lld len= min(n,m);
      		lld f = 0;
      		for(lld j = 0; j < len; j += 1){
      			if (s[j] < t[j])
      				{f = 1; break;}
      			if (t[j] < s[j])
      				{f =-1; break;}
      		}
      		if (f == 1){
      			g = 1;
      			break;
      		}
      		if (f == 0){
      			if (n < m){
      				g = 1;
      				break;
      			}
      		}
      		swap(s[i],s[pos]);
      	}
      	if (g == 1) cout << s << "\n";
      	else cout << "---\n";
      }
      return 0;
}