// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <list>
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
#define LEN 100010
lld cnt[LEN];
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
      memset(A, 0, sizeof(A));
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	cnt[A[i]]++;
      }
      lld sum = 0;
      map <lld, lld> calc;
      for(lld i = 1; i<LEN; i += 1){
      	if (cnt[i] != 0){
      		calc[i%2] += i*cnt[i];
      		if (calc[1-(i%2)] >= calc[i%2]){
      			sum += calc[1-(i%2)];
      			calc[0] = calc[1] = 0;
      		}
      	}
      	else{
      		sum += max(calc[0],calc[1]);
      		calc[0] = calc[1] = 0;
      	}
      }
      cout << sum;
      return 0;
}