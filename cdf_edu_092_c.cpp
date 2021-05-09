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
      	lld A[n];
      	for(lld i = 0; i < n; i += 1){
      		A[i] = (lld)s[i]-48;
      	}
      	set <lld> vis[10];
      	for(lld i = 0; i < n; i += 1){
      		vis[A[i]].insert(i);
      	}
      	lld ans = MIN;
      	for(lld i = 0; i < 10; i += 1){
      		ans = max(ans, (lld)vis[i].size());
      	}
      	for(lld i = 0; i < 10; i += 1){
      		for(lld j = 0; j < 10; j += 1){
      			if (j == i || vis[i].empty() || vis[j].empty())
      				continue;
      			lld pos = i;
      			lld par = j;
      			lld cnt = 0;
      			set <lld> :: iterator itr = vis[pos].begin();
      			lld index = *itr;
      			while(true){
      				vis[par].insert(index);
      				set <lld> :: iterator it = vis[par].find(index);
      				it++;
      				if (it  ==  vis[par].end()){
      					vis[par].erase(index);
      					break;
      				}
      				else{
      					vis[par].erase(index);
      					cnt++;
      					index = (*it);
      					swap(pos,par);
      				}
      			}
      			cnt++;
      			if (cnt%2 != 0)
      				cnt--;
      			ans = max(ans, cnt);
      		}
      	}
      	cout << n-ans << "\n";
      }
      return 0;
}