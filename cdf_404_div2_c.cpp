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
#define LEN 2000000000
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      if (m >= n-2){cout << n; return 0;}
      lld x = n-m;
      lld l = 1;
      lld r = LEN;
      while(l < r){
      	lld mid = (l+r)/2;
      	if ((mid*(mid+1))/2 >= x)
      		r = mid-1;
      	else
      		l = mid+1;
      }
      lld p = l-1;
      lld q = l+1;
      if (x-((p*(p+1))/2) <= 0) {cout << m+p << "\n"; return 0;}
      if (x-((l*(l+1))/2) <= 0) {cout << m+l << "\n"; return 0;}
      if (x-((q*(q+1))/2) <= 0) {cout << m+q << "\n"; return 0;}
      return 0;
}