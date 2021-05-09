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
      lld t, l;
      cin >> t;
      foi(l,t){
      	string s;
      	cin >> s;
      	stack <char> stk;
      	for(lld i = 0; i < s.size(); i += 1){
      		if (s[i] == 'A'){
      			stk.push(s[i]);
      		}
      		else{
      			if (stk.empty()){
      				stk.push(s[i]);
      			}
      			else{
      				char x = stk.top();
      				if (x == 'A'){
      					stk.pop();
      				}
      				else{
      					stk.push(s[i]);
      				}
      			}
      		}
      	}
      	vector <char> v;
      	while(!stk.empty()){
      		v.pb(stk.top());
      		stk.pop();
      	}
      	reverse(v.begin(),v.end());
      	lld cnt = 0;
      	lld sum = 0;
      	for(lld i = 0; i < v.size(); i += 1){
      		if (v[i] == 'B'){
      			cnt++;
      		}
      		else{
      			if (cnt%2 != 0)
      				sum++;
      			sum++;
      			cnt=0;
      		}
      	}
      	if (cnt%2 != 0)
      		sum++;
      	cout << sum << "\n";
      }
      return 0;
}