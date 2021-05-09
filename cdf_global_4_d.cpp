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
#define LEN 10000
lld prime[LEN];
lld nextp[LEN];
void seive (){
	prime[0] = prime[1] = 0;
	for(lld i = 2; i < LEN; i += 1)
		prime[i] = 1;
	for(lld i = 4; i < LEN; i += 2)
		prime[i] = 0;
	for(lld i = 3; i*i < LEN; i+=1){
		if (prime[i] == 1){
			for(lld j = i*i; j < LEN; j += i){
				prime[j] = 0;
			}
		}
	}
	lld p;
	for(lld i = LEN; i > 0; i -= 1){
		if (prime[i] == 1){
			p = i;
			break;
		}
	}
	for(lld i = p; i >= 0; i -= 1){
		if (prime[i] == 1){
			p = i;
		}
		nextp[i]= p;
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      seive();
      lld n;
      cin >> n;
      vector <pair<lld, lld> > v;
      for(lld i = 2; i <= n; i += 1){
      	v.push_back({i-1,i});
      }
      v.push_back({n,1});
      lld len = v.size();
      lld j = 1;
      while(len < nextp[len]){
      	v.push_back({j,j+(n/2)});
      	len++;
      	j+= 1;
      }
      cout << v.size() << "\n";
      foi(i,v.size())
      	cout << v[i].first << " " << v[i].second << "\n";
      return 0;
}