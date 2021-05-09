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
#define LEN 1000
set <pair <lld, lld> > mac;
lld vis[LEN];
void dfs (set <lld> v[], lld pos)
{
	vis[pos] = 1;
	for(auth itr = v[pos].begin(); itr != v[pos].end(); itr++){
		if (vis[*itr] == -1){
			mac.insert(make_pair(pos, *itr));
			dfs(v,*itr);
		}
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      string a, b;
      cin >> n >> a >> b;
      set <lld> v[26];
      for(lld i = 0; i < n; i += 1){
      	if (a[i] == b[i])
      		continue;
      	v[(lld)a[i]-97].insert((lld)b[i]-97);v[(lld)b[i]-97].insert((lld)a[i]-97);
      }
      memset(vis,  -1, sizeof(vis));
      for(lld i = 0; i <26; i += 1){
      	if (vis[i] == -1 && !v[i].empty())
      		dfs(v,i);
      }
      cout << mac.size() << "\n";
      for(set <pair <lld, lld> > :: iterator itr = mac.begin(); itr!=mac.end();itr++)
      	cout << (char)((*itr).first+97) << " " << (char)((*itr).second+97)<< "\n";
      return 0;
}