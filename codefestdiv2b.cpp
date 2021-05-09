// first method is to loop on all of i and get
// the best fit for j and then get index of j
// and find best fit for k. Otherwise get fit
// for k and then get j;
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
lld first (lld A[], lld n, lld p, lld q, lld r)
{
	pair <lld, lld> val_end[n];
	pair <lld, lld> val_fit[n];
	lld max = MIN, min = MAX;
	for(lld i = n-1; i >= 0; i -= 1){
		if (A[i] < min)
			min=A[i];
		if (A[i] > max)
			max=A[i];
		val_end[i] = {min,max};
	}
	min = MAX;
	max = MIN;
	for(lld i = 0; i < n; i += 1){
		if (A[i] < min)
			min=A[i];
		if (A[i] > max)
			max=A[i];
		val_fit[i] = {min,max};
	}
	lld ans = MIN;
	for(lld i =  0; i < n; i += 1){
		lld sum = A[i]*q;
		if (p >= 0) sum += p*val_fit[i].second; else sum += p*val_fit[i].first;
		if (r >= 0) sum += r*val_end[i].second; else sum += r*val_end[i].first;
		if (sum > ans)
			ans = sum;
	}
	return ans;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, p, q, r;
      cin >> n >> p >> q >> r;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      cout << first(A,n,p,q,r);
      return 0;
}