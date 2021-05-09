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
vector <lld> bin_ (lld x)
{
	vector <lld> ans;
	while(x){
		ans.push_back(x%2);
		x/=2;
	}
	lld len = ans.size();
	while(len != 6){ans.push_back(0);len += 1;}
	reverse(ans.begin(), ans.end());
	return ans;
}
lld get_ (char c)
{
	lld x;
	if (c >= '0' && c <= '9')
		x = (lld)c-48;
	if (c >= 'a' && c <= 'z')
		x = (lld)c-61;
	if (c >= 'A' && c <= 'Z')
		x = (lld)c-55;
	if (c == '-')
		x = 62;
	if (c == '_')
		x = 63;
	vector <lld> v = bin_(x);
	lld p = 1;
	for(lld i = 0; i < v.size(); i += 1)
		if (v[i] == 0)
			p = ((p%MOD)*3)%MOD;
	return p;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string s;
      cin >> s;
      lld n = s.size();
      lld prod = 1;
      for(lld i = 0; i < n; i += 1)
      	prod = ((prod%MOD)*(get_(s[i])%MOD))%MOD;
      cout << prod;
      return 0;
}