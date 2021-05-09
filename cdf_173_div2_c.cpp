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
      string s;
      string r;
      cin >> s >> r;
      if (s.size() != r.size()){
      	cout << "NO";
      }
      else{
      	lld len = s.size();
      	if (len == 1){
      		if (r == s)
      			cout << "YES";
      		else  cout <<  "NO";
      	}
      	if (len >= 2){
      		lld f = 0;
      		for(lld i = 0; i < len; i += 1)
      			if (s[i] == '1')
      				f = 1;
      		lld g = 0;
      		for(lld i = 0; i < len; i += 1)
      			if (r[i] == '1')
      				g = 1;
      		if (f == 1){
      			if (g == 1) cout << "YES";
      			else cout << "NO";
      		}
      		else{
      			if (g == 0) cout << "YES";
      			else cout << "NO";
      		}
      	}
      }
      return 0;
}