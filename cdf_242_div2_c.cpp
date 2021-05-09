// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. do not use
// complex data structures if double matrix can be used..
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
      lld n;
      cin >> n;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      vector <lld> ans(n);
      for(lld i = 1; i <=n; i += 1){
      	ans[i-1]+= n/i;
      	ans[n%i]+= 1;
      }
      for(lld i = n-2;i>=0; i -= 1){
      	ans[i] += ans[i+1];
      }
      lld res = 0;
      for(lld i = 1; i < n; i += 1){
      	if (ans[i]%2)
      		res = res xor i;
      }
      for(lld i = 0; i < n; i += 1){
      	res = res xor A[i];
      }
      cout << res;
      return 0;
}