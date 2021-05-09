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
#define auth set <lld> :: iterator
#define pb push_back
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, k;
      cin >> n >> k;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
            cin >> A[i];
      }
      vector <lld> d (n-k+2, 0);
      lld sum = 0;
      for(lld i = 0; i < k; i += 1){
            sum += A[i];
      }
      d[1] = sum;
      for(lld i = 1; i < n-k+1; i += 1){
            sum -= A[i-1];
            sum += A[i+k-1];
            d[i+1] = sum;
      }
      set <lld> vis;
      map <lld, lld> cnt;
      for(lld i = k+1; i <= n-k+1; i += 1){
            vis.insert(d[i]);
            cnt[d[i]]++;
      }
      lld ans = MIN;
      lld pos;
      for(lld i = 1; i <= n-(2*k)+1; i += 1){
            auth itr = vis.end();
            itr--;
            if ((d[i]+(*itr)) > ans){
                  ans = d[i]+(*itr);
                  pos = i;
            }
            cnt[d[i+k]]--;
            if (cnt[d[i+k]] == 0)
                  vis.erase(d[i+k]);
      }
      ans -= d[pos];
      lld sos;
      for(lld i = pos+k; i <= n-k+1; i += 1){
            if (d[i] == ans){
                  sos=i;
                  break;
            }
      }
      cout << pos << " " << sos;
      return 0;
}