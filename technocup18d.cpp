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
      string phone[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> phone[i];
      }
      map <string, lld> cnt;
      for(lld i = 0; i < n; i += 1){
      	set <string>vis;
      	for(lld x = 0; x < phone[i].size(); x += 1){
      		string ans = "";
      		for(lld y = x; y < phone[i].size(); y += 1){
      			ans += phone[i][y];
      			vis.insert(ans);
      		}
      	}
      	for(set <string> :: iterator itr = vis.begin(); itr != vis.end(); itr++)
      		cnt[*itr]++;
      }
      for(lld i = 0; i < n; i += 1){
      	lld len = MAX;
      	string val;
      	for(lld x = 0; x < phone[i].size(); x += 1){
      		string ans = "";
      		for(lld y = x; y < phone[i].size(); y += 1){
      			ans += phone[i][y];
      			if (cnt[ans] == 1){
      				if (y-x+1 < len){
      					len=y-x+1;
      					val=ans;
      				}
      			}
      		}
      	}
      	cout << val << "\n";
      }
      return 0;
}