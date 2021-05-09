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
      string s;
      cin >> s;
      lld n = s.size();
      lld f = 1;
      for(lld i = 0; i < n/2; i += 1){
      	switch(s[i]){
      		case 'A':
      		case 'H':
      		case 'I':
      		case 'M':
      		case 'O':
      		case 'T':
      		case 'U':
      		case 'V':
      		case 'W':
      		case 'X':
      		case 'Y':
      		case 'o':
      		case 'v':
      		case 'w':
      		case 'x': {
      			if (s[n-i-1] != s[i])
      				f = 0;
      			break;
      		}
      		case 'b': {
      			if (s[n-i-1] != 'd')
      				f = 0;
      			break;
      		}
      		case 'd': {
      			if (s[n-i-1] != 'b')
      				f = 0;
      			break;
      		}
      		case 'p': {
      			if (s[n-i-1] != 'q')
      				f = 0;
      			break;
      		}
      		case 'q': {
      			if (s[n-i-1] != 'p')
      				f = 0;
      			break;
      		}
      		default : { f = 0; break;}
      	}
      }
      if (n%2 != 0){
      	if (s[n/2] == 'A' || s[n/2] == 'H' || s[n/2] == 'I' || s[n/2] == 'M' || s[n/2] == 'O' || s[n/2] == 'T' || s[n/2] == 'U' || s[n/2] == 'V' || s[n/2] == 'W' || s[n/2] == 'X' || s[n/2] == 'Y' || s[n/2] == 'o' || s[n/2] == 'v' || s[n/2] == 'w' || s[n/2] == 'x'){
      		// do nothing
      	}
      	else
      		f = 0;
      }
      if (f == 1) cout << "TAK";
      else cout << "NIE";
      return 0;
}