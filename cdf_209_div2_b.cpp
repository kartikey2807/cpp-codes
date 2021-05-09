// Trick -> reverse 2i and 2i-1 for 1 <= i <= k;
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
      lld n, k;
      cin >> n >>  k;
      lld A[(2*n)+1];
      for(lld i = 1; i <= (2*n); i += 1){
      	A[i]= i;
      }
      for(lld i = 1; i <= k; i += 1){
      	swap(A[2*i], A[(2*i)-1]);
      }
      for(lld i = 1; i <= (2*n); i += 1){
      	cout << A[i] << " ";
      }
      return 0;
}