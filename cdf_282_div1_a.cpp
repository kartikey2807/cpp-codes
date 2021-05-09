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
      string s;
      cin >> s;
      lld n = s.size();
      lld A[n];
      memset(A, 0, sizeof(A));
      for(lld i = 0; i < n; i += 1){
      	if (s[i] == '(')
      		A[i] = 1;
      	if (s[i] == ')')
      		A[i] =-1;
      }
      lld sum = 0, cnt = 0;
      for(lld i = 0; i < n; i += 1){
      	if (A[i] == 0){
      		if (sum >= 1)
      			{sum--; cnt++; A[i] =-1;}
      		else
      			{cout << "-1"; return 0;}
      	}
      	else{
      		sum += A[i];
      		if (sum < 0)
      			{cout << "-1"; return 0;}
      	}
      }
      for(lld i = n-1; i >= 0; i -= 1){
      	if (s[i] == '#'){
      		A[i]-=sum;
      		break;
      	}
      }
      lld acm = 0;
      for(lld i = 0; i < n; i += 1){
      	acm += A[i];
      	if (acm < 0)
      		{cout << "-1"; return 0;}
      }
      for(lld i = 1; i<cnt; i += 1){
      	cout << "1\n";
      }
      cout << 1+sum;
      return 0;
}