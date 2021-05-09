// みなさん私はカーティキー・シャルマです。LNMIITで勉強しています。私は2年目で、コロナパンデミックが発
// 生しています。世界は終わりそうだ。だから私はそれを最大限に生きたいと思っています。それはつまり、コー
// ドを最大限に意味しているのです。私の好きなアニメは「キメツノヤイバ」で、私の一番の男の子はゼニツで、
// 私の一番の女の子はネズコです。私の好きな呼吸スタイルは息吹です。私の最高の悪魔の血の芸術は、
// ククシボによって使用される月の息です。ムーザンは亡くなり、今ではタンジローがポップの新しい魔王です。
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
#define LEN 1000
lld fac[LEN];
lld inv[LEN];
lld ifac[LEN];
void fac_init ()
{
	fac[0] = 1;
	fac[1] = 1;
	for(lld i = 2; i < LEN; i += 1){
		fac[i] = fac[i-1]*i%MOD;
	}
}
void ifac_init()
{
	ifac[0] = 1;
	ifac[1] = 1;
	inv [1] = 1;
	for(lld i = 2; i < LEN; i += 1){
		inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
		ifac[i]= ifac[i - 1] * inv[i] % MOD;
	}
}
lld nCr_ (lld n, lld r)
{
	if (r > n || n < 0 || r < 0)
		return 0.0;
	return ((((fac[n]%MOD)*(ifac[r]%MOD))%MOD)*(ifac[n-r]%MOD))%MOD;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      fac_init();
      ifac_init();
      string drazil;
      string dreemn;
      cin >> drazil >> dreemn;
      map <char , lld> count1;
      map <char , lld> count2;
      foi(i, drazil.length()){
      	count1[drazil[i]]++;
      }
      foi(i, dreemn.length()){
      	count2[dreemn[i]]++;
      }
      dbl p = 0;
      if (count2['+'] > count1['+'] || count2['-'] > count1['-']){
      	p = 0;
      }
      else{
      	if (count2['+'] == count1['+'] && count2['-'] == count1['-']){
      		p = 1;
      	}
      	else{
      		lld x = count1['+'] - count2['+'];
      		lld y = count1['-'] - count2['-'];
      		lld z = count2['?'];
      		lld a = nCr_(z, x);
      		dbl b = a/pow(2,z);
      		p = b;
      	}
      }
      cout << fixed << setprecision(12) << p;
      return 0;
}