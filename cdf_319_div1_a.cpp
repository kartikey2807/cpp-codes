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
#define LEN 5000
bool prime[LEN];
void sieve ()
{
	prime[0] = false;
	prime[1] = false;
	for(lld i = 2; i < LEN; i += 1)
		prime[i] = true;
	for(lld i = 4; i < LEN; i += 2)
		prime[i] = false;
	for(lld i = 3; i*i<LEN; i += 1){
		if (prime[i]){
			for(lld j = i*i; j < LEN; j += i)
				prime[j] = false;
		}
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      sieve();
      lld n;
      cin >> n;
      vector <lld> order;
      for(lld i = 2; i <= n; i += 1){
      	if (prime[i]){
      		order.push_back(i);
      		for(lld j = i*i; j <= n; j *= i)
      			order.push_back(j);
      	}
      }
      cout << order.size() << "\n";
      foi(i,order.size()) cout << order[i] << " ";
      return 0;
}