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
      lld t, l;
      cin >> t;
      foi(l,t){
      	string s;
      	cin >> s;
      	lld n = s.size();
      	vector <lld> eve, odd;
      	for(lld i = 0; i < n; i += 1){
      		lld x = (lld)s[i]-48;
      		if (x%2 == 0)
      			eve.pb(x);
      		else  odd.pb(x);
      	}
      	vector <lld> order;
      	lld i = 0, j = 0;
      	lld len1 = eve.size(), len2 = odd.size();
      	while(i < len1&& j < len2){
      		if (eve[i] < odd[j])
      			{order.pb(eve[i]); i++;}
      		else
      			{order.pb(odd[j]); j++;}
      	}
      	while(i < len1)
      		{order.pb(eve[i]);i++;}
      	while(j < len2)
      		{order.pb(odd[j]);j++;}
      	for(lld i = 0; i < order.size(); i += 1)
      		cout << order[i];
      	cout << "\n";
      }
      return 0;
}