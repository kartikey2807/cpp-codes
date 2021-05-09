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
#define MOD 1073741824
#define LEN 1000001
lld spf[LEN];
void sieve ()
{
	spf[1] = 1;
	for(lld i = 2; i < LEN; i += 1){
		spf[i] = i;
	}
	for(lld i = 4; i < LEN; i += 2){
		spf[i] = 2;
	}
	for(lld i = 3; i*i < LEN; i+=1){
		if (spf[i] == i){
			for(lld j = i*i; j < LEN; j += i){
				if (spf[j] == j){
					spf[j]= i;
				}
			}
		}
	}
}
lld getFact (lld x)
{
	map <lld , lld> count;
	while(x != 1){
		count[spf[x]]++;
		x /= spf[x];
	}
	lld prod = 1;
	for(map <lld, lld> :: iterator itr = count.begin(); itr != count.end(); itr++){
		lld x = itr->second + 1;
		prod *= x%MOD;
		prod %= MOD;
	}
	return prod;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld a, b, c;
      cin >> a >> b >> c;
      sieve();
      lld sum = 0;
      for(lld i = 1; i <= a; i += 1){
      	for(lld j = 1; j <= b; j += 1){
      		for(lld k = 1; k <= c; k += 1){
      			sum = ((sum%MOD) + (getFact(a*b*c)%MOD))%MOD;
      		}
      	}
      }
      cout << sum;
      return 0;
}