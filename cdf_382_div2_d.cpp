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
lld check (lld x)
{
	for(lld i = 2; i <= sqrt(x); i += 1)
		if (x % i == 0)
			return 0;
	return 1;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      // Goldbach's conjecture <- any even number ( > 2) can be represented as a sum of 2 primes
      lld n;
      cin >> n;
      if (n == 2 || n == 3){
      	cout << "1";
      }
      else{
      	if (n % 2 == 0){
      		cout<<"2";
      	}
      	else{
      		if (check(n-0)){
      			cout<<"1";
      		}
      		else{
      			if (check(n-2)){
      				cout<<"2";
      			}
      			else{
      				cout<<"3";
      			}
      		}
      	}
      }
      return 0;
}