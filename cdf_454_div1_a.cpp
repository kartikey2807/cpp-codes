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
      set <char> options;
      for(char a = 'a'; a<='z';a++)
      	options.insert(a);
      lld n;
      cin >> n;
      lld after = 0;
      for(lld i = 0; i < n; i += 1){
      	if (options.size()!= 1){
      		char c;
      		string s;
      		cin >> c >> s;
      		if (c == '!'){
      			set <char> ans;
      			for(lld j = 0; j < s.size(); j += 1)
      				if (options.count(s[j]))
      					ans.insert(s[j]);
      			options = ans;
      		}
      		if (c == '.'){
      			for(lld j = 0; j < s.size(); j += 1)
      				options.erase(s[j]);
      		}
      		if (c == '?'){
      			options.erase(s[0]);
      		}
      	}
      	else{
      		char c;
      		string s;
      		cin >> c >> s;
      		if (c == '!'){
      			after++;
      		}
      		if (c == '?'){
      			if (i < n-1)
      				after++;
      		}
      	}
      }
      cout << after;
      return 0;
}