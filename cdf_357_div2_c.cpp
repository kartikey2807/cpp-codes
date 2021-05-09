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
#define VALUE -1000000000
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      set <lld> vis;
      map <lld,lld> mac;
      vector <string> a;
      vector <lld> vals;
      for(lld i = 0; i < n; i += 1){
      	string s;
      	cin >> s;
      	if (s == "insert"){
      		lld r;
      		cin >> r;
      		mac[r]++;
      		if (mac[r] == 1){
      			vis.insert(r);
      		}
      		a.pb(s);
      		vals.pb(r);
      	}
      	if (s ==  "removeMin"){
      		if (vis.empty()){
      			a.pb("insert");
      			vals.pb(VALUE);
      			mac[VALUE]++;
      			if (mac[VALUE] == 1){
      				vis.insert(VALUE);
      			}
      		}
      		auth itr = vis.begin();
      		mac[*itr]--;
      		if (mac[*itr] == 0)
      			vis.erase(*itr);
      		a.pb(s);
      		vals.pb(0);
      	}
      	if (s == "getMin"){
      		lld r;
      		cin >> r;
      		while(!vis.empty()){
      			auth itr = vis.begin();
      			if (*itr>= r){
      				break;
      			}
      			a.pb("removeMin");
      			vals.pb(0);
      			mac[*itr]--;
      			if (mac[*itr] == 0)
      				vis.erase(*itr);
      		}
      		if (vis.empty()){
      			a.pb("insert");
      			vals.pb(r);
      			mac[r]++;
      			if (mac[r] == 1)
      				vis.insert(r);
      		}
      		else{
      			auth itr = vis.begin();
      			if (*itr!= r){
      				a.pb("insert");
      				vals.pb(r);
      				mac[r]++;
      				if (mac[r] == 1)
      					vis.insert(r);
      			}
      		}
      		a.pb(s);
      		vals.pb(r);
      	}
      }
      cout << a.size() << "\n";
      for(lld i = 0; i < a.size(); i += 1){
      	if (a[i] == "removeMin")
      		cout << a[i] << "\n";
      	else
      		cout << a[i] << " " << vals[i] << "\n";
      }
      return 0;
}