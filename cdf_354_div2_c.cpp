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
lld get_ (string s, lld n, lld k, char a, char b)
{
	lld i = 0;
	lld cnt = 0;
	set <lld> point;
	while(cnt < k && i < n){
		if (s[i] == b){
			s[i]=a;
			point.insert(i);
			cnt+=1;
		}
		i++;
	}
	for(; i < n; i += 1){
		if (s[i] == b){
			break;
		}
	}
	lld ans = i;
	lld end = i;
	for(lld j = 1; j < n; j += 1){
		if (point.count(j-1)) {point.erase(j-1); s[j-1] = b; cnt--;}
		if (cnt < k){
			if (s[end] == b){
				s[end] = a;
				point.insert(end);
				cnt++;
				for(; end < n; end += 1){
					if (s[end] == b)
						break;
				}
			}
		}
		ans = max(ans, end-j);
	}
	return ans;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, k;
      string s;
      cin >> n >> k >> s;
      if (k == 0){
      	lld c = 0, ans = MIN;
      	for(lld i = 1; i < n; i += 1){
      		if (s[i] == s[i-1]){
      			c++;
      		}
      		else{
      			c++;
      			ans = max(ans,c);
      			c=0;
      		}
      	}
      	c++;
      	ans = max(ans,c);
      	cout << ans;
      }
      else cout << max(get_(s,n,k,'a','b'), get_(s,n,k,'b','a'));
      return 0;
}