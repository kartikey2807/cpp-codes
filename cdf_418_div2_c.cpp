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
      // to get longest subsegment after changing atmost m values
      // make l and r and run along for k non values and get max.

      lld n;
      string s;
      cin >> n >> s;
      map <pair <lld, char>, lld> gt;
      for(lld i = 1; i <= n; i += 1){
      	for(char a = 'a'; a <= 'z'; a += 1){
      		lld start = 0, end = n-1;
      		string temp = s;
      		lld cnt = 0;
      		for(lld j = 0; j < n; j += 1){
      			if (temp[j] != a)
      				cnt++;
      			if (cnt > i){
      				end = j-1;
      				cnt--;
      				break;
      			}
      		}
      		lld ans = end-start+1;
      		while(end < n){
      			start++;
      			if (temp[start-1] != a){
      				cnt--;
      				while(end < n){
      					end++;
      					if (temp[end] != a)
      						cnt++;
      					if (cnt > i){
      						end--;
      						cnt--;
      						break;
      					}
      				}
      				ans = max(ans,end-start+1);
      			}
      			if (start >= n)
      				break;
      		}
      		gt[make_pair(i,a)] = ans;
      	}
      }
      lld q;
      cin >> q;
      for(lld i = 0; i < q; i += 1){
      	lld m;
      	char c;
      	cin >> m >> c;
      	cout << gt[make_pair(m,c)] << "\n";
      }
      return 0;
}