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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      set <lld> vis;
      map <lld, lld> cnt, mac;
      for(lld i = 0; i < n; i += 1){
      	cnt[A[i]]++;
      }
      for(map <lld, lld> :: iterator itr = cnt.begin(); itr != cnt.end(); itr++){
      	mac[itr->second]++;
      	vis.insert(itr->second);
      }
      for(lld i = n-1; i >= 0; i -= 1){
      	if (vis.size() == 1){
      		auth itr = vis.begin();
      		if (*itr == 1 || mac[*itr] == 1){
      			cout << i+1;
      			return 0;
      		}
      	}
      	else{
      		auth itr = vis.begin();
      		auth pos = vis.end(); pos--;
      		if (vis.size() == 2){
      			if ((((*pos)-(*itr)) == 1 && mac[*pos] == 1) || (*itr == 1 && mac[*itr] == 1)){
      				cout << i+1;
      				return 0;
      			}
      		}
      	}
      	mac[cnt[A[i]]]--;
      	if (mac[cnt[A[i]]] == 0)
      		vis.erase(cnt[A[i]]);
      	cnt[A[i]]--;
      	if (cnt[A[i]] > 0){
      		mac[cnt[A[i]]]++;
      		vis.insert(cnt[A[i]]);
      	}
      }
      return 0;
}