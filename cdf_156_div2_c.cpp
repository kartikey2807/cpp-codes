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
#define LEN 1000010
set <lld> loc[LEN];
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld B[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> B[i];
      }
      vector <lld> val;
      set <lld> vis;
      for(lld i = 0; i < n; i += 1){
      	loc[B[i]].insert(i);
      	if (!vis.count(B[i]))
      		{val.pb(B[i]); vis.insert(B[i]);}
      }
      lld ans = MIN;
      for(lld i = 0; i < n; i += 1){
      	ans = max(ans, (lld)loc[B[i]].size());
      }
      for(lld i = 0; i < val.size(); i += 1){
      	for(lld j = i+1; j < val.size(); j += 1){
      		lld cnt = 0,pos = val[i], par = val[j];
      		set <lld> :: iterator itr = loc[par].begin();
      		lld index = *itr;
      		while(true){
      			loc[pos].insert(index);
      			set <lld> :: iterator it = loc[pos].find(index);
      			it++;
      			if (it  ==  loc[pos].end()){
      				loc[pos].erase(index);
      				break;
      			}
      			else{
      				cnt++;
      				loc[pos].erase(index);
      				index = (lld)*it;
      				swap(pos,par);
      			}
      		}
      		ans = max(ans, cnt+2);
      	}
      }
      cout << ans;
      return 0;
}