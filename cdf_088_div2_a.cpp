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
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      for(lld i = 0; i < n; i += 1){
      	lld s, f, t;
      	cin >> s >> f >>  t;
      	lld q = t/(m-1);
      	lld r = t%(m-1);
      	if (s == f)
      	{
      		cout << t << "\n";
      		continue;
      	}
      	if (q % 2 == 0){
      		lld floor = r+1;
      		if (s >= floor){
      			t += (s-floor);
      			if (f >= s){
      				t += (f-s);
      			}
      			else{
      				t += (m-s)+(m-f);
      			}
      		}
      		else{
      			t += (m-floor) + (m-s);
      			if (f > s){
      				t += (s-1)+(f-1);
      			}
      			else{
      				t += (s-f);
      			}
      		}
      	}
      	else{
      		lld floor = m-r;
      		if (s <= floor){
      			t += (floor-s);
      			if (f <= s){
      				t += (s-f);
      			}
      			else{
      				t += (s-1)+(f-1);
      			}
      		}
      		else{
      			t += (floor-1) + (s-1);
      			if (f >= s){
      				t += (f-s);
      			}
      			else{
      				t += (m-s)+(m-f);
      			}
      		}
      	}
      	cout << t << "\n";
      }
      return 0;
}