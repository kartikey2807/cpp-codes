// Trick --> Either you add +1 to the starting index and -1 to next of the ending index, OR You can use a map to index the positions
// and increment on each start and decrement on each end.
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
#define LEN 200005
lld countSmaller (lld A[], lld l, lld r, lld x) {return upper_bound(A+l,A+r,x) - (A+l);}
bool bin (lld A[], lld l, lld r, lld x)
{
	while(l <= r){
		lld mid = (l+r)/2;
		if (A[mid] == x)
			return true;
		if (A[mid]  < x)
			l = mid+1;
		if (A[mid]  > x)
			r = mid-1;
	}
	return false;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, k, q;
      cin >> n >> k >> q;
      vector <lld> index (LEN);
      for(lld i = 0; i < n; i += 1){
      	lld l, r;
      	cin >> l >> r;
      	index[l] += 1;
      	index[r+1]-=1;
      }
      for(lld i = 1; i < LEN; i+=1){
      	index[i] += index[i-1];
      }
      lld A[LEN];
      lld j =  0;
      for(lld i = 1; i < LEN; i+=1){
      	if (index[i] >= k){
      		A[j] = i;
      		j++;
      	}
      }
      for(lld i = 0; i < q; i += 1){
      	lld a, b;
      	cin >> a >> b;
      	lld count1 = countSmaller(A, 0, j, b);
      	lld count2 = (bin(A,0,j-1,a) == true) ? countSmaller(A,0,j,a-1) : countSmaller(A,0,j,a);
      	cout << count1-count2 << "\n";
      }
      return 0;
}