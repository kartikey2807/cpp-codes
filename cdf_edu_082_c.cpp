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
      	set <lld> vis;
      	lld n = s.size();
      	map <char, lld> mac;
      	vis.insert(0);
      	mac[s[0]] = 0;
      	lld f = 1;
      	for(lld i = 1; i < n; i += 1){
      		lld pos =mac[s[i-1]];
      		if (mac.count(s[i])){
      			lld loc = mac[s[i]];
      			if (abs(pos-loc) != 1)
      				{f = 0; break;}
      		}
      		else{
      			if (!vis.count(pos+1)){
      				vis.insert(pos+1);
      				mac[s[i]]= pos+1;
      			}
      			else{
      				if (!vis.count(pos-1)){
      					vis.insert(pos-1);
      					mac[s[i]]= pos-1;
      				}
      				else
      					{f = 0; break;}
      			}
      		}
      	}
      	if (f == 0)
      		{cout << "NO\n"; continue;}
      	cout << "YES\n";
      	vector <pair <lld, char> > v;
      	for(map <char, lld> :: iterator itr = mac.begin(); itr != mac.end(); itr++)
      		v.pb({itr->second, itr->first});
      	sort(v.begin(), v.end());
      	for(lld i = 0; i < v.size();i++)
      		cout << v[i].second;
      	for(char a = 'a'; a <= 'z'; a++)
      		if (!mac.count(a))
      			cout << a;
      	cout << "\n";
      }
      return 0;
}