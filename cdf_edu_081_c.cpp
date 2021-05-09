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
#define auth set <lld> :: iterator
#define pb push_back
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld q;
      cin >> q;
      while(q--){
      	string s, t;
      	cin >> s >> t;
      	set <lld> loc[26];
      	for(lld i = 0; i < s.size(); i += 1)
      		loc[(lld)s[i]-97].insert(i);
      	lld f = 1;
      	for(lld i = 0; i < t.size(); i += 1)
      		if (loc[(lld)t[i]-97].empty())
      			f = 0;
      	if (f == 0)
      		{cout << "-1\n"; continue;}
      	auth itr = loc[(lld)t[0]-97].begin();
      	lld pos = (*itr);
      	lld c = 0;
      	for(lld i = 1; i < t.size(); i += 1){
      		if (t[i] == t[i-1]){
      			auth itr = loc[(lld)t[i]-97].find(pos);
      			itr++;
      			if (itr == loc[t[i]-97].end()){
      				c++;
      				auth it = loc[(lld)t[i]-97].begin();
      				pos = *it;
      			}
      			else
      				pos = *itr;
      		}
      		else{
      			loc[(lld)t[i]-97].insert(pos);
      			lld temp = pos;
      			auth itr = loc[(lld)t[i]-97].find(pos);
      			itr++;
      			if (itr == loc[t[i]-97].end()){
      				c++;
      				auth it = loc[(lld)t[i]-97].begin();
      				pos = *it;
      			}
      			else
      				pos = *itr;
      			loc[(lld)t[i]-97].erase(temp);
      		}
      	}
      	cout << c+1 << "\n";
      }
      return 0;
}