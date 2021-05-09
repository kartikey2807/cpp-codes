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
      lld n;
      string s;
      cin >> n >> s;
      lld orign = n;
      for(char a = 'z'; a >= 'a'; a -= 1){
      	for(lld i = 0; i < n; i += 1){
      		if (s[i] == a){
      			if ((i+1 < n && (lld)s[i]-(lld)s[i+1] == 1) || (i-1 >= 0 && (lld)s[i]-(lld)s[i-1] == 1)){
					string temp1 = "";
      				string temp2 = "";
      				for(lld j = 0; j < i; j += 1)
      					temp1 += s[j];
      				for(lld j = i+1; j<n; j += 1)
      					temp2 += s[j];
      				s = temp1+temp2;
      				n--; i = -1;
      			}
      		}
      	}
      }
      cout << orign-n << "\n";
      return 0;
}