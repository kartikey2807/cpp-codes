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
#define MOD 1000000007
lld pow_ (lld a, lld n)
{
	if (n == 0) return 1;
	if (n == 1) return a;
	if (n%2==0) return (((pow_(a,n/2)%MOD)*(pow_(a,n/2)%MOD))%MOD);
	else return ((((pow_(a,n/2)%MOD)*(pow_(a,n/2)%MOD))%MOD)*(a%MOD))%MOD;
}
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
      map <char, lld> cnt;
      for(lld i = 0; i < n; i += 1)
      	cnt[s[i]]++;
      lld ans = MIN;
      for(char a = 'A';a<='Z'; a++)
      	ans = max(ans,cnt[a]);
      lld c = 0;
      for(char a = 'A';a<='Z'; a++)
      	if (ans == cnt[a])
      		c++;
      cout << pow_(c,n)%MOD;
      return 0;
}