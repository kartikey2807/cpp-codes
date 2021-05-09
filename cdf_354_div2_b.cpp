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
void rec (dbl arr[], lld h, lld n, dbl val, lld pos)
{
	if (h > n)
		{return;}
	if (arr[pos]+val > 1){dbl x = 1-arr[pos]; arr[pos] = 1; rec(arr, h+1, n, (val-x)/2, pos+h); rec(arr, h+1, n, (val-x)/2, pos+h+1);}
	else {arr[pos] += val; return;}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, t;
      cin >> n >> t;
      lld total = (n*(n+1))/2;
      dbl arr[total+1];
      memset(arr, 0, sizeof(arr));
      for(lld i = 1; i <= t; i += 1)
      	rec(arr,1,n,1,1);
      lld c = 0;
      for(lld i = 1; i <= total; i += 1)
      	if (arr[i] == 1)
      		c++;
      cout << c;
      return 0;
}