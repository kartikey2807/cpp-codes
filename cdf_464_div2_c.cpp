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
      lld s, f;
      cin >> s >> f;
      vector <lld>  mac;
      for(lld i = 0; i < n; i += 1){
      	mac.pb(A[i]);
      }
      for(lld i = 0; i < n; i += 1){
      	mac.pb(A[i]);
      }
      lld sum = 0;
      for(lld i = s-1; i < f-1; i += 1){
      	sum += mac[i];
      }
      lld ans = sum;
      lld pos = 1;
      lld j = n;
      lld start = s, end = f;
      while(j > 1){
      	sum -= mac[start-1];
      	sum += mac[end-1];
      	if (sum >= ans){
      		ans=sum;
      		pos = j;
      	}
      	start++; end++;
      	j-= 1;
      }
      cout << pos;
      return 0;
}