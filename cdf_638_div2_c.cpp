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
      	lld n, k;
      	string s;
      	set <char> vis; 
      	cin >> n >> k >> s;
      	map <lld,string> m;
      	sort(s.begin(), s.end());
      	for(lld i = 0; i < k; i += 1){
      		m[i] += s[i];
      		vis.insert(s[i]);
      	}
      	if (vis.size() == 1){
      		set <char> pc; 
      		for(lld i = k; i < n; i += 1)
      			pc.insert(s[i]);
      		if (pc.size()  ==  1){
      			for(lld i = k; i < n; i += 1)
      				m[i%k] += s[i];
      		}
      		else{
      			for(lld i = k; i < n; i += 1)
      				m[0%k] += s[i];
      		}
      		set <string> cmp;
      		for(map <lld, string> :: iterator itr = m.begin(); itr != m.end(); itr++)
      			cmp.insert(itr->second);
      		set <string>::iterator pos = cmp.end();
      		pos--;
      		cout << *pos << "\n";
      	}
      	else{
      		set <char> :: iterator pos = vis.end();
      		pos--;
      		cout << *pos << "\n";
      	}
      }
      return 0;
}