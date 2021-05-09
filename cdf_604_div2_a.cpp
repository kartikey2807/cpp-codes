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
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld T, i;
      cin >> T;
      foi(i, T)
      {
      	lld A[3], j;
      	cin >> A[0];
      	cin >> A[1];
      	cin >> A[2];
      	sort(A,A+3);
      	if (A[2] <= A[0]+A[1])
      		cout <<  ((A[0] + A[1] + A[2])/2) << "\n";
      	else
      		cout <<  ((A[0] + A[1])) << "\n";
      }
      return 0;
}