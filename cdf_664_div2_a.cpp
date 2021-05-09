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
#define auth set <lld> :: iterator
#define pb push_back
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t;
      cin >> t;
      while(t--){
      	lld A[4];
      	for(lld i = 0; i < 4; i += 1)
      		cin >> A[i];
      	if (A[0] == 0 || A[1] == 0 || A[2] == 0){
      		lld e = 0, o = 0;
      		for(lld i = 0; i < 4; i += 1){
      			if (A[i]%2 == 0)
      				e++;
      			else  o++;
      		}
      		if (o == 0 || o == 1)
      			cout << "Yes";
      		else  cout << "No";
      	}
      	else{
      		lld e = 0, o = 0;
      		for(lld i = 0; i < 4; i += 1){
      			if (A[i]%2 == 0)
      				e++;
      			else  o++;
      		}
      		if (e == 0 || e == 1 || o == 0 || o == 1)
      			cout << "Yes";
      		else  cout << "No";
      	}
      	cout << "\n";
      }
      return 0;
}