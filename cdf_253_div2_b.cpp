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
      lld k;
      string s;
      cin >> s >> k;
      lld n = s.size();
      if (k >= n){
      	if (k%2 == n%2) cout << n+k;
      	else cout << n+k-1;
      }
      else{
      	lld ans = 2*k;
      	lld j = n;
      	lld p = n;
      	for(lld i = n-k; i >= 0; i -= 2){
      		lld start = i;
      		lld f = 1;
      		for(lld pos = j; pos < n; pos += 1){
      			if (s[start] != s[pos])
      				f = 0;
      			start++;
      		}
      		if (f == 1){
      			p = i;
      			ans = max(ans, 2*(j-i));
      		}
      		j--;
      	}
      	lld c = p+(ans/2);
      	for(lld i = c; i < n; i += 1)
      		p++;
      	for(lld i = p; i < c; i += 1)
      		s += s[i];
      	lld m = s.size();
      	// cout << s << " " << m << "\n";
      	lld calc = 0;
      	for(lld len = 2; len <= m; len+=2){
      		lld cap = len/2;
      		for(lld i = 0; i <= m-len; i += 1){
      			lld f = 1;
      			for(lld j = i; j < i+cap; j += 1){
      				if (s[j] != s[j+cap])
      					f = 0;
      			}
      			if (f == 1)
      				calc = max(calc, len);
      		}
      	}
      	cout << calc;
      }
      return 0;
}