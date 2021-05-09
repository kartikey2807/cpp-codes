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
      lld n;
      cin >> n;
      map <lld, pair<lld, lld> > mac;
      for(lld i = 1; i <= n; i += 1){
      	cin >> mac[i].first >> mac[i].second;
      }
      vector <lld> ans;
      ans.pb(1);
      lld x = 1;
      lld len = 1;
      while(len < n){
      	lld a = mac[x].first, b = mac[x].second;
      	set <lld> temp1, temp2;

      	// intersection with a
      	temp1.insert(a); temp1.insert(b); temp1.insert(mac[a].first); temp1.insert(mac[a].second);

      	// intersectin with b
      	temp2.insert(a); temp2.insert(b); temp2.insert(mac[b].first); temp2.insert(mac[b].second);

      	lld len1 = temp1.size();
      	lld len2 = temp2.size();
      	if (len1 == 3)
      		{ans.pb(a); ans.pb(b); x = b; len += 2;}
      	if (len2 == 3)
      		{ans.pb(b); ans.pb(a); x = a; len += 2;}
      }
      for(lld i = 0; i < n; i += 1)
      	cout << ans[i] << " ";
      return 0;
}