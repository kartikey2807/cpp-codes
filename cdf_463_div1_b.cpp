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
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LEN 1000001
lld get_ (lld x)
{
	while (x >= 10){
		lld y = x;
		lld p = 1;
		while (y != 0){
			lld r = y % 10;
			if (r != 0){
				p*=r;
			}
			y/=10;
		}
		x = p;
	}
	return x;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld dda[LEN][10];
      for(lld i = 0; i < LEN; i += 1){
      	for(lld j = 0; j < 10;j += 1){
      		dda[i][j] = 0;
      	}
      }
      dda[LEN-1][get_(LEN-1)]++;
      for(lld i = LEN-2; i >= 0; i--){
      	for(lld j = 0; j < 10;j += 1){
      		dda[i][j] += dda[i+1][j];
      	}
      	dda[i][get_(i)]++;
      }
      lld q;
      cin >> q;
      for(lld i = 0; i < q; i += 1){
      	lld l, r, k;
      	cin >> l >> r >> k;
      	if (get_(r)  == k){
      		cout << dda[l][k]-dda[r][k]+1 << "\n";
      	}
      	else{
      		cout << dda[l][k] - dda[r][k] << "\n";
      	}
      }
      return 0;
}