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
      	lld n, m;
      	cin >> n >> m;
      	lld dda[n][m];
      	for(lld i = 0; i < n; i += 1){
      		for(lld j = 0; j < m; j += 1){
      			cin >> dda[i][j];
      		}
      	}
      	lld count = 0;
      	while(true){
      		lld g = 0;
      		for(lld i = 0; i < n; i += 1){
      			for(lld j = 0; j < m; j += 1){
      				lld f = 1;
      				for(lld k = 0; k < m; k += 1){
      					if (dda[i][k] == 1){
      						f = 0;
      						break;
      					}
      				}
      				for(lld k = 0; k < n; k += 1){
      					if (dda[k][j] == 1){
      						f = 0;
      						break;
      					}
      				}
      				if (f == 1){
      					dda[i][j] = 1;
      					count++;
                                    g = 1;
      					break;
      				}
      			}
      			if (g == 1)
                              break;
      		}
                  if (g == 0)
                        break;
      	}
            if (count%2 == 0) cout << "Vivek\n";
            else cout << "Ashish\n";
      }
      return 0;
}