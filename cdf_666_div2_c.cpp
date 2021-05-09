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
      lld n;
      cin >> n;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      if (n == 1){
      	cout << "1 1\n";
      	cout << -1*A[0] << "\n";
      	cout << "1 1\n" << "0\n" << "1 1\n" << "0\n";
      	return 0;
      }
      lld k = n-1;
      cout << "1 " << k << "\n";
      for(lld i = 0; i < k; i += 1){
      	cout << A[i]*k << " ";
      	A[i]+= (A[i]*k);
      	A[i]*=-1;
      }
      cout << "\n" << n << " " << n << "\n";
      cout << n-A[n-1] << "\n";
      A[n-1] = n;
      A[n-1]*=-1;
      cout << "1 " << n << "\n";
      for(lld i = 0; i < n; i += 1){
      	cout << A[i] << " ";
      }
      return 0;
}