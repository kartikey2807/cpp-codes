// マップやその他の非常に複雑なタプルは使用しないでください。そして、文字列
// で遊ぶとき、それを整数配列に変換します。それは不思議です。パニックになら
// ないでください。それに慣れているときは常に競争をしてください。評価が下がっ
// たときに強調しないでください、それは起こります。だから、冷静ですが重要なコード:)
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
#define MOD 1000000007
#define len 3000
lld ifac[len];
lld inv[len];
void init_ifac ()
{
	ifac[0] = 1;
	ifac[1] = 1;
	inv [1] = 1;
	for(lld i = 2; i < len; i += 1){
		inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
		ifac[i]= ifac[i-1]*inv[i]%MOD;
	}
}
lld get_pow (lld a, lld n)
{
	if (n == 0) return 1;
	if (n == 1) return a;
	if (n%2==0) return ((get_pow(a,n/2)%MOD)*(get_pow(a,n/2)%MOD))%MOD;
	else return ((((get_pow(a,n/2)%MOD)*(get_pow(a,n/2)%MOD))%MOD)*(a%MOD))%MOD;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      init_ifac();
      lld n;
      cin >> n;
      lld A[n],B[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      sort(A,A+n);
      B[0] = 0;
      lld sum = 0;
      for(lld i = 1; i < n; i += 1){
      	sum = ((sum%MOD)+(get_pow(2,i-1)%MOD))%MOD;
      	B[i] = ((A[i]%MOD)*(sum%MOD))%MOD;
      }
      lld m = n-2;
      sum = 0;
      for(lld i = 0; i<n-1; i += 1){
      	lld p = ((A[i]%MOD)*(get_pow(2,m)%MOD))%MOD;
      	sum = ((sum%MOD)+(p%MOD))%MOD;
      	m--;
      }
      lld total = 0;
      for(lld i = n-1; i > 0; i -= 1){
      	lld temp = ((B[i]%MOD)-(sum%MOD))%MOD;
      	if (temp < 0) temp = MOD+temp;
      	total =  ((total%MOD)+(temp%MOD))%MOD;
      	sum = ((sum%MOD)-(A[i-1]%MOD))%MOD;
      	if (sum < 0) sum = MOD+sum;
      	sum = ((sum%MOD)*(ifac[2]%MOD))%MOD;
      }
      cout << total;
      return 0;
}