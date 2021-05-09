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
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n, m, x, y;
      	cin >> n >> m >> x >> y;
      	char dda[n][m];
      	for(lld i = 0; i < n; i += 1){
      		for(lld j = 0; j < m; j += 1){
      			cin >> dda[i][j];
      		}
      	}
      	lld total = 0;
      	for(lld i = 0; i < n; i += 1){
      		lld count = 0, sum1 = 0, sum2 = 0, sum3 = 0;
      		for(lld j = 0; j < m; j += 1){
      			if (dda[i][j] == '.'){
      				count++;
      			}
      			else{
      				sum1 += count/2;
      				sum2 += count;
      				sum3 += (count%2 == 0 ? 0 : 1);
      				count = 0;
      			}
      		}
      		sum1 += count/2;
      		sum2 += count;
      		sum3 += (count%2 == 0 ? 0 : 1);
      		total += min(((sum1*y)+(sum3*x)),(sum2*x));
      	}
      	cout << total << "\n";
      }
      return 0;
}