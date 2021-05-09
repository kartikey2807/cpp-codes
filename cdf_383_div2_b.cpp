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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, x;
      cin >> n >> x;
      lld A[n];
      set <lld> vis;
      map <lld, lld> cnt;
      for(lld i = 0; i < n; i += 1){
      	lld r;
      	cin >> r;
      	A[i] = r;
      	vis.insert(r);
      	cnt[r]++;
      }
      lld c = 0;
      for(lld i = 0; i < n; i += 1){
      	cnt[A[i]]--;
      	if (cnt[A[i]] == 0)
      		vis.erase(A[i]);
      	lld y = A[i] xor x;
      	if (vis.count(y))
      		c += cnt[y];
      	cnt[A[i]]++;
      	if (cnt[A[i]] == 1)
      		vis.insert(A[i]);
      }
      cout << c/2;
      return 0;
}