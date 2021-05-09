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
      string s;
      cin >> n >> s;
      set <lld> types;
      for(lld i = 0; i < n; i += 1)
      	types.insert(s[i]);
      lld total = types.size();
      lld len = 0;
      map <char, lld> cnt;
      lld start;
      for(lld i = n-1; i >= 0; i -= 1){
      	cnt[s[i]]++;
      	if (cnt[s[i]]==1)
      		len++;
      	if (len == total){
      		start = i;
      		break;
      	}
      }
      lld ans = n-start;
      for(lld i = n-1; i >= 0; i -= 1){
      	cnt[s[i]]--;
      	if (cnt[s[i]]==0)
      		len--;
      	if (len != total){
      		lld j;
      		for(j = start-1; j >= 0; j -= 1){
      			cnt[s[j]]++;
      			if (cnt[s[j]]==1)
      				len++;
      			if (len == total)
      				break;
      		}
      		if (j == -1)
      			break;
      		else start = j;
      	}
      	ans = min(ans, i-start);
      }
      cout << ans;
      return 0;
}