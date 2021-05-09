// Fact - the prime numbers in order of 10^9 do not have a gap exceeding 300 so little time complexity.
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
bool isPrime (lld x, lld p)
{
	for(lld i = 2; i <= sqrt(x); i+=1){
		if (x%i == 0 && i <= p){
			return false;
		}
	}
	return true;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld p, y;
      cin >> p >> y;
      for(lld i = y; i > p; i -= 1){
      	if (isPrime(i, p)){
      		cout << i << "\n";
      		return 0;
      	}
      }
      cout << "-1";
      return 0;
}