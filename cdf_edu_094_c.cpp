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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
      	string s;
      	lld x, n;
      	cin >> s >> x;
      	n = s.size();
      	lld A[n],B[n];
      	for(lld i = 0; i < n; i += 1){
      		A[i] = (lld)s[i]-48;
      		B[i] = 1;
      	}
      	lld f = 1;
      	for(lld i = 0; i < n; i += 1){
      		if (i-(2*x) >= 0){
      			if (A[i] == A[i-(2*x)]){
      				if (i+x < n)
      					B[i+x] = A[i];
      			}
      			else{
      				if (A[i-(2*x)] == 0){
      					if (i+x < n) B[i+x] = 1;
      					else {f = 0; break;}
      				}
      				else{
      					if (i-(3*x) >= 0 && B[i-(3*x)] == 1){
      						B[i-x] = 0;
      						if (i+x < n)
      							B[i+x] = 0;
      					}
      					else {f = 0; break;}
      				}
      			}
      		}
      		else{
      			if (A[i] == 1){
      				if (i-x < 0 && i+x >= n){
      					f = 0;
      					break;
      				}
      				if (i-x >= 0) B[i-x] = 1;
      				if (i+x <  n) B[i+x] = 1;
      			}
      			else{
      				if (i-x >= 0) B[i-x] = 0;
      				if (i+x <  n) B[i+x] = 0;
      			}
      		}
      	}
      	if (f == 0) 
      		{cout << "-1\n";}
      	else{
      		for(lld i = 0; i < n; i += 1)
      			cout << B[i];
      		cout << "\n";
      	}
      }
      return 0;
}