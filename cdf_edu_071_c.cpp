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
      	lld n, a, b;
      	string s;
      	lld p = -1;
      	lld sum = 0;
      	cin >> n >> a >> b >> s;
      	for(lld i = 0; i < n; i += 1){
      		if (s[i] == '1'){
      			p = i;
      			break;
      		}
      	}
      	if (p == -1){
      		cout << (n*a)+((n+1)*b) << "\n";
      		continue;
      	}
      	lld q = 0;
      	sum+= (p-1)*(b+a) + (b+(2*a));
      	for(lld i = 0; i < n; i += 1){
      		if (s[i] == '1')
      			q = i;
      	}
      	lld c = n-1-q;
      	sum+= (c-1)*(b+a) + b +2*(a+b);
      	for(lld i = p; i <= q; i += 1){
      		if (s[i] == '1')
      			sum+= (2*b)+a;
      		else{
      			lld pos;
      			for(lld j = i; j < n; j += 1){
      				if (s[j] == '1'){
      					pos = j-1;
      					break;
      				}
      			}
      			// cout << i << " " << pos << "\n";
      			if (pos-i+1 >= 2) sum+= min(((2*b)+a)*(pos-i+1), (a+b)*(pos-i-1) + (2*(a+b)) + b+(2*a));
      			else sum+= a+(2*b);
      			i = pos;
      		}
      	}
      	cout << sum << "\n";
      }
      return 0;
}