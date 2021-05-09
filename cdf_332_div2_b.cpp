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
      lld n, m;
      cin >> n >> m;
      lld F[n],B[m];
      for(lld i = 0; i < n; i += 1){
      	cin >> F[i];
      }
      for(lld i = 0; i < m; i += 1){
      	cin >> B[i];
      }
      lld cnt1[n+1], cnt2[n+1];
      memset(cnt1, 0, sizeof(cnt1));
      memset(cnt2, 0, sizeof(cnt2));
      for(lld i = 0; i < n; i += 1){
      	cnt1[F[i]]++;
      }
      for(lld i = 0; i < m; i += 1){
      	cnt2[B[i]]++;
      }
      for(lld i = 1; i <=n; i += 1){
      	if (cnt1[i] == 0 && cnt2[i] != 0)
      		{cout << "Impossible"; return 0;}
      }
      for(lld i = 0; i < m; i += 1){
      	if (cnt1[B[i]] > 1)
      		{cout << "Ambiguity";  return 0;}
      }
      map <lld, lld> mac;
      for(lld i = 0; i < n; i += 1){
      	mac[F[i]] = i+1;
      }
      lld A[m];
      for(lld i = 0; i < m; i += 1){
      	A[i] = mac[B[i]];
      }
      cout << "Possible\n";
      for(lld i = 0; i < m; i += 1){
      	cout << A[i] << " ";
      }
      return 0;
}