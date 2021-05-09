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
#define MOD 1000000007
lld pow_ (lld a, lld x)
{
	if (x == 0)
		return 1;
	if (x == 1)
		return a;
	if (x%2==0)
		return ((pow_(a,x/2)%MOD)*(pow_(a,x/2)%MOD))%MOD;
	else
		return ((((pow_(a,x/2)%MOD)*(pow_(a,x/2)%MOD))%MOD)*(a%MOD))%MOD;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld h, w;
      cin >> h >> w;
      lld dda[h][w];
      lld row[h];
      lld col[w];
      for(lld i = 0; i < h; i += 1){
      	for(lld j = 0; j < w; j += 1){
      		dda[i][j] = 0;
      	}
      }
      for(lld i = 0; i < h; i += 1){
      	lld r, j = 0;
      	cin >> r;
      	row[i] = r;
      	for(j = 0; j<r; j += 1){
      		dda[i][j] = 1;
      	}
      	if (j < w){
      		dda[i][j] =-1;
      	}
      }
      for(lld j = 0; j < w; j += 1){
      	lld r, i = 0;
      	cin >> r;
      	col[j] = r;
      	for(i = 0; i<r; i += 1){
      		dda[i][j] = 1;
      	}
      	if (i < h){
      		dda[i][j] =-1;
      	}
      }
      for(lld i = 0; i < h; i += 1){
      	lld count = 0;
      	for(lld j = 0; j < w; j += 1){
      		if (dda[i][j] != 1){
      			break;
      		}
      		count++;
      	}
      	if (count != row[i]){
      		cout << "0";
      		return 0;
      	}
      }
      for(lld j = 0; j < w; j += 1){
      	lld count = 0;
      	for(lld i = 0; i < h; i += 1){
      		if (dda[i][j] != 1){
      			break;
      		}
      		count++;
      	}
      	if (count != col[j]){
      		cout << "0";
      		return 0;
      	}
      }
      lld count = 0;
      for(lld i = 0; i < h; i += 1){
      	for(lld j = 0; j < w; j += 1){
      		if (dda[i][j] == 0){
      			count++;
      		}
      	}
      }
      cout << pow_(2,count)%MOD;
      return 0;
}