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
#define LEN 1001
lld dda[LEN][LEN];
bool xyz (lld x, lld y, lld n)
{
	lld count = 0;
	for(lld i = x; i <= min(x+2, n); i += 1){
		for(lld j = y; j <= min(y+2, n); j += 1){
			if (dda[i][j] == 1){
				count++;
			}
		}
	}
	if (count == 9)
		return true;
	count = 0;
	for(lld i = x; i <= min(x+2, n); i += 1){
		for(lld j = y; j >= max(y-2, (lld)1); j -= 1){
			if (dda[i][j] == 1){
				count++;
			}
		}
	}
	if (count == 9)
		return true;
	count = 0;
	for(lld i = x; i >= max(x-2, (lld)1); i -= 1){
		for(lld j = y; j <= min(y+2,n); j += 1){
			if (dda[i][j] == 1){
				count++;
			}
		}
	}
	if (count == 9)
		return true;
	count = 0;
	for(lld i = x; i >= max(x-2, (lld)1); i -= 1){
		for(lld j = y; j >= max(y-2, (lld)1); j -= 1){
			if (dda[i][j] == 1){
				count++;
			}
		}
	}
	if (count == 9)
		return true;
	return false;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      for(lld i = 1; i <= n; i += 1){
      	for(lld j = 1; j <= n; j += 1){
      		dda[i][j] =  -1;
      	}
      }
      lld p = -1;
      for(lld i = 1; i <= m; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	dda[x][y] = 1;
      	for(lld j = x; j <= min(x+2, n); j += 1){
      		for(lld k = y; k <= min(y+2, n); k += 1){
      			if (xyz(j,k,n)){
      				cout<< i;
      				return 0;
      			}
      		}
      	}
      	for(lld j = x; j <= min(x+2, n); j += 1){
      		for(lld k = y; k >= max(y-2, (lld)1); k -= 1){
      			if (xyz(j,k,n)){
      				cout<< i;
      				return 0;
      			}
      		}
      	}
      	for(lld j = x; j >= max(x-2, (lld)1); j -= 1){
      		for(lld k = y; k <= min(y+2,n); k += 1){
      			if (xyz(j,k,n)){
      				cout<< i;
      				return 0;
      			}
      		}
      	}
      	for(lld j = x; j >= max(x-2, (lld)1); j -= 1){
      		for(lld k = y; k >= max(y-2, (lld)1); k -= 1){
      			if (xyz(j,k,n)){
      				cout<< i;
      				return 0;
      			}
      		}
      	}
      }
      cout<< p;
      return 0;
}