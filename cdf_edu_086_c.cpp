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
lld lcm_ (lld a, lld b)
{
      lld max = a > b ? a : b;
      lld min = a < b ? a : b;
      while(min){
            lld rem = max%min;
            max = min;
            min = rem;
      }
      return ((a*b)/max);
}
lld cnt_ (lld n, lld x, lld big)
{
      lld num = n/x;
      if (num == 0)
            return min(n,big-1);
      // if num >= 1
      lld ans = num*x;
      if (n-ans+1 <= big) return (n-ans+1)+(big*(num-1))+(big-1);
      else return (big*num)+(big-1);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t;
      cin >> t;
      while(t--){
            lld a, b, q;
            cin >> a >> b >> q;
            lld x = lcm_(a, b);
            while(q--){
                  lld l, r;
                  cin >> l >> r;
                  l--;
                  lld p1 = r-cnt_(r,x,max(a,b));
                  lld p2 = l-cnt_(l,x,max(a,b));
                  cout << p1-p2 << " ";
            }
            cout << "\n";
      }
      return 0;
}