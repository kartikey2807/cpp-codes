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
      lld n, x1, y1, x2, y2;
      cin >> n >> x1 >> y1 >> x2 >> y2;
      lld A[n],B[n];
      for(lld i = 0; i < n; i += 1){
            cin >> A[i] >> B[i];
      }
      lld ans = 0;
      for(lld i = 0; i < n; i += 1){
            lld dist = (lld)pow(A[i]-x1,2)+pow(B[i]-y1,2);
            ans = max(ans, dist);
      }
      set<lld>vis;
      lld sum = 0;
      while(true){
            lld pos =  -1;
            lld res = MIN;
            for(lld i = 0; i < n; i += 1){
                  if (vis.count(i))
                        continue;
                  lld dist = (lld)pow(A[i]-x1,2)+pow(B[i]-y1,2);
                  if (dist > res){
                        res=dist;
                        pos=i;
                  }
            }
            if (pos == -1)
                  break;
            vis.insert(pos);
            lld acc = (lld)pow(A[pos]-x2,2)+pow(B[pos]-y2,2);
            sum = max(sum,acc);
            lld crt = 0;
            for(lld i = 0; i < n; i += 1){
                  if (vis.count(i))
                        continue;
                  lld dist = (lld)pow(A[i]-x1,2)+pow(B[i]-y1,2);
                  crt = max(crt,dist);
            }
            ans = min(ans,crt+sum);
      }
      cout << ans;
      return 0;
}