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
#define LEN 100010
lld X[LEN];
lld Y[LEN];
lld Z[LEN];
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string s;
      cin >> s;
      lld l = s.size();
      for(lld i = 0; i < l; i += 1){
      	if (s[i] == 'x')
      		X[i+1]++;
      	if (s[i] == 'y')
      		Y[i+1]++;
      	if (s[i] == 'z')
      		Z[i+1]++;
      }
      for(lld i = 1; i <= l; i += 1){
      	X[i] += X[i-1];
      	Y[i] += Y[i-1];
      	Z[i] += Z[i-1];
      }
      lld n;
      cin >> n;
      lld cnt[3];
      for(lld i = 0; i < n; i += 1){
      	lld l, r;
      	cin >> l >> r;
      	cnt[0] = X[r]-X[l-1], cnt[1] = Y[r]-Y[l-1], cnt[2] = Z[r]-Z[l-1];
      	sort(cnt,cnt+3);
      	if (r-l+1 <= 2)
      		cout << "YES\n";
      	else{
      		if (cnt[2]-cnt[0] <= 1)
      			cout << "YES\n";
      		else
      			cout <<  "NO\n";
      	}
      }
      return 0;
}