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
      lld A[n];
      for(lld i = 0; i < n; i += 1){
            cin >> A[i];
      }
      lld c[n+1];
      lld b[n+1];
      memset(b, 0, sizeof(b));
      for(lld i = 0; i < n; i += 1){
            lld max = MIN;
            lld val;
            memset(c, 0, sizeof(c));
            for(lld j = i; j < n; j += 1){
                  c[A[j]]++;
                  if (c[A[j]]> max){
                        max=c[A[j]];
                        val=A[j];
                  }
                  if (c[A[j]]==max){
                        if (A[j] < val){
                              val=A[j];
                        }
                  }
                  b[val]++;
            }
      }
      for(lld i = 1; i <= n; i += 1)
            cout << b[i] << " ";
      return 0;
}