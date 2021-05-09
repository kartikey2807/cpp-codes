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
lld change (queue <char> str, char c[])
{
	lld i = 0;
	lld cnt = 0;
	while(!str.empty()){
		if (str.front() != c[i])
			cnt++;
		str.pop();
		i++;
	}
	return cnt;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n, k;
      	string s;
      	cin >> n >> k >> s;
      	char c1[k], c2[k], c3[k];
      	for(lld i = 0; i < k; i += 1){
      		switch(i%3){
      			case 0 : c1[i] = 'R'; c2[i] = 'G'; c3[i] = 'B'; break;
      			case 1 : c1[i] = 'G'; c2[i] = 'B'; c3[i] = 'R'; break;
      			case 2 : c1[i] = 'B'; c2[i] = 'R'; c3[i] = 'G'; break;
      		}
      	}
      	lld ans = MAX;
      	queue <char> str;
      	for(lld i = 0; i < k; i += 1){
      		str.push(s[i]);
      	}
      	ans = min(ans, min(change(str, c3), min(change(str, c1), change(str, c2))));
      	for(lld i = 1; i < n-k+1; i += 1){
      		str.pop();
      		str.push(s[i+k-1]);
      		ans = min(ans, min(change(str, c3), min(change(str, c1), change(str, c2))));
      	}
      	cout << ans << "\n";
      }
      return 0;
}