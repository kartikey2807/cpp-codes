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
lld pay_ (char c, lld a, lld b)
{
	return (c == 'A' ? a : b);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld a, b, p;
      	cin >> a >> b >> p;
      	string s;
      	cin >> s;
      	lld L = s.length();
      	stack <lld>  index;
      	lld sum = 0;
      	lld f = 1;
      	index.push(L-1);
      	for(lld i = L-3; i >= 0; i -= 1){
      		if (s[i] != s[i+1]){
      			sum+= pay_(s[i+1], a, b);
      			index.push(i+1);
      		}
      		if (sum > p){
      			index.pop();
      			f = 0;
      			break;
      		}
      	}
      	if (f == 0){
      		cout << index.top() + 1 <<"\n";
      	}
      	else{
      		sum+= pay_(s[0], a, b);
      		if (sum > p){
      			cout << index.top()+1 << "\n";
      		}
      		else{
      			cout << "1\n";
      		}
      	}
      }
      return 0;
}