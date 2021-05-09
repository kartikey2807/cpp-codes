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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      string s;
      cin >> n >> s;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	A[i] = (lld)s[i]-48;
      }
      lld B[2*n];
      lld m[n];
      for(lld i = 0; i < n; i += 1){
      	B[i] = B[i+n] = A[i];
      	m[i] = A[i];
      }
      for(lld i = 0; i < n; i += 1){
      	lld diff = (10-B[i])%10;
      	for(lld j = i; j<i+n; j += 1){
      		B[j] = (B[j]+diff)%10;
      	}
      	lld f = 0;
      	for(lld j = 0; j < n; j += 1){
      		if (m[j] != B[j+i]){
      			if (m[j] < B[j+i])
      				f = 1;
      			else  f =-1;
      			break;
      		}
      	}
      	if (f == -1){
      		for(lld j = 0; j < n; j += 1){
      			m[j] = B[j+i];
      		}
      	}
      	for(lld j = i; j<i+n; j += 1){
      		B[j] = (B[j]-diff)%10;
      		if (B[j] < 0)
      			B[j]+=10;
      	}
      }
      for(lld i = 0; i < n; i += 1)
      	cout << m[i];
      return 0;
}