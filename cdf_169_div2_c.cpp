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
#define LEN 200010
lld A[LEN];
lld B[LEN];
lld C[LEN];
void psort (lld n){
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1){
		P[i].first  = A[i];
		P[i].second = B[i];
	}
	sort(P,P+n);
	for(lld i = 0; i < n; i += 1){
		A[i] = P[i].first;
		B[i] = P[i].second;
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      pair <lld, lld> p[m];
      vector <lld> val (n);
      for(lld i = 0; i < n; i += 1){
      	cin >> val[i];
      	B[i] = i;
      }
      for(lld i = 0; i < m; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	x--; y--;
      	A[x]++;
      	A[y+1]--;
      	p[i] = {x, y};
      }
      for(lld i = 1; i <=n; i += 1){
      	A[i] += A[i-1];
      }
      psort(n);
      sort(val.begin(), val.end(), greater<lld>());
      lld j = n-1;
      for(lld i = 0; i < n; i += 1){
      	C[B[j]] = val[i];
      	j--;
      }
      map <lld, lld> mac;
      mac[-1] = 0;
      lld sum = 0;
      for(lld i = 0; i < n; i += 1){
      	sum += C[i];
      	mac[i]= sum;
      }
      lld acc = 0;
      for(lld i = 0; i < m; i += 1){
      	acc += mac[p[i].second]-mac[p[i].first-1];
      }
      cout << acc;
      return 0;
}