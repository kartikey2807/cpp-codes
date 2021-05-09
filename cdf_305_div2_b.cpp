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
      lld n, m, q;
      cin >> n >> m >>q;
      lld dda[n+1][m+1];
      for(lld i = 1; i <= n; i += 1){
      	for(lld j = 1; j <= m; j += 1){
      		cin >> dda[i][j];
      	}
      }
      set <lld> ones;
      map <lld, lld> index;
      for(lld i = 1; i <= n; i += 1){
      	lld count = 0;
      	lld max = MIN;
      	for(lld j = m; j >= 1; j -= 1){
      		if (dda[i][j] == 1){
      			count++;
      		}
      		else{
      			if (count > max){
      				max=count;
      			}
      			count = 0;
      		}
      	}
      	if (count > max){
      		max=count;
      	}
      	ones.insert(max);
      	index[max]++;
      }
      for(lld i = 0; i < q; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	lld count = 0;
      	lld max = MIN;
      	for(lld j = m; j >= 1; j -= 1){
      		if (dda[x][j] == 1){
      			count++;
      		}
      		else{
      			if (count > max){
      				max=count;
      			}
      			count = 0;
      		}
      	}
      	if (count > max){
      		max=count;
      	}
      	index[max]--;
      	if (index[max]  == 0){
      		ones.erase(max);
      	}
      	dda[x][y] = 1-dda[x][y];
      	count = 0;
      	max = MIN;
      	for(lld j = m; j >= 1; j -= 1){
      		if (dda[x][j] == 1){
      			count++;
      		}
      		else{
      			if (count > max){
      				max=count;
      			}
      			count = 0;
      		}
      	}
      	if (count > max){
      		max=count;
      	}
      	index[max]++;
      	if (index[max]  == 1){
      		ones.insert(max);
      	}
      	set <lld> :: iterator itr = ones.end(); itr--;
      	cout << (*itr) << "\n";
      }
      return 0;
}