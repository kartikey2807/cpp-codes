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
void psort (lld A[], lld B[], lld n)
{
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
      lld n, k;
      cin >> n >> k;
      lld A[n],B[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i] >> B[i];
      }
      psort(A,B,n);
      psort(B,A,n);

      lld ans = MIN;
      lld sum = 0;
      set <lld> vis;
      map <lld, lld> cnt;
      for(lld i = n-1; i >= n-k; i -= 1){
      	vis.insert(A[i]);
      	cnt[A[i]]++;
      	sum += A[i];
      	ans = max(ans, sum*B[i]);
      }
      for(lld i = n-k-1; i >= 0; i -= 1){
      	auth itr = vis.begin();
      	cnt[*itr]--;
      	if (cnt[*itr] == 0)
      		vis.erase(*itr);
      	sum -= (*itr);

      	vis.insert(A[i]);
      	cnt[A[i]]++;
      	sum += A[i];
      	ans = max(ans, sum*B[i]);
      }
      cout << ans;
      return 0;
}