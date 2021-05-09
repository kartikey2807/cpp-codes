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
      lld n;
      cin >> n;
      pair <lld, lld> P[n];
      map <lld, lld> left, right;
      for(lld i = 0; i < n; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	P[i] = {x,y};
      	left[x]  = y;
      	right[y] = x;
      }
      lld A[n+2];
      memset(A, -1, sizeof(A));
      A[0]  = 0;
      lld j = 2;
      lld start = 0;
      while(true){
      	A[j] = left[start];
      	j += 2;
      	start= left[start];
      	if (!left.count(start) || j > n+1)
      		break;
      }
      lld p;
      for(lld i = 0; i < n; i += 1){
      	if (P[i].first != 0 && !right.count(P[i].first)){
      		p = P[i].first;
      	}
      }
      A[1] = p;
      j = 3;
      start = p;
      while(true){
      	A[j] = left[start];
      	j += 2;
      	start= left[start];
      	if (!left.count(start) || A[j] != -1)
      		break;
      }
      for(lld i = 1; i < n+1; i += 1)
      	cout << A[i] << " ";
      return 0;
}