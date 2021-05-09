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
lld get1 (lld A[], lld n, lld l, lld r, lld Ql, lld Qr)
{
      lld sum = A[n-1]*r;
      for(lld i = n-2; i >= 0; i -= 1){
      	sum += ((A[i]*r)+Qr);
      }
      lld ans = sum;
      lld cum = 0;
      lld mum = 0;
      if (n%2 != 0){
      	for(lld i = 0; i < (n/2); i += 1){
      		cum += A[i]*l;
      		mum += ((A[i]*r)+Qr);
      		ans = min(ans, sum-mum-((i+1)*Qr)+cum);
      	}
      }
      else{
      	for(lld i = 0; i<(n/2)-1; i += 1){
      		cum += A[i]*l;
      		mum += ((A[i]*r)+Qr);
      		ans = min(ans, sum-mum-((i+1)*Qr)+cum);
      	}
      	lld acc = 0;
      	for(lld i = 0; i < (n/2); i += 1){
      		acc += (A[i]*l)+(A[i+(n/2)]*r);
      	}
      	ans = min(ans, acc);
      }
      return ans;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      lld l, r, Ql, Qr;
      cin >> n >> l >> r >> Ql>> Qr;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      lld B[n];
      lld j = n-1;
      for(lld i = 0; i < n; i += 1){
      	B[j] = A[i];
      	j--;
      }
      cout << min(get1(A,n,l,r,Ql,Qr), get1(B,n,r,l,Qr,Ql));
      return 0;
}