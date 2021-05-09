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
bool check (lld x)
{
	for(lld i = 2; i <= sqrt(x); i+=1)
		if (x%i == 0)
			return true;
	return false;
}
set <lld> prime (lld x)
{
	set <lld> p;
	while(x%2 == 0){
		p.insert(2);
		x/=2;
	}
	for(lld i = 3; i <= sqrt(x); i+=2){
		while(x%i == 0){
			p.insert(i);
			x/=i;
		}
	}
	if (x > 2)
		p.insert(x);
	return p;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      if (check(n)){
      	set <lld> fact = prime(n);
      	if (fact.size() != 1){
      		cout << "1";
      	}
      	else{
      		set <lld> :: iterator pos = fact.begin();
      		cout << *pos;
      	}
      }
      else cout << n;
      return 0;
}