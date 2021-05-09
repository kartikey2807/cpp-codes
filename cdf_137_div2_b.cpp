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
      lld n, m, k;
      cin >> n >> m>> k;
      lld dda[n+1][m+1];
      for(lld i = 1; i <= n; i += 1){
      	for(lld j = 1; j <= m; j += 1){
      		cin >> dda[i][j];
      	}
      }
      map <lld, lld> index_x;
      map <lld, lld> index_y;
      for(lld i = 1; i <= n; i += 1){
      	index_x[i] = i;
      }
      for(lld j = 1; j <= m; j += 1){
      	index_y[j] = j;
      }
      for(lld i = 1; i <= k; i += 1){
      	char c;
      	lld x, y;
      	cin >> c;
      	if (c == 'g'){
      		cin >> x >> y;
      		cout << dda[index_x[x]][index_y[y]] << "\n";
      	}
      	else{
      		if (c == 'r'){
      			lld x1, x2;
      			cin >> x1 >> x2;
      			lld t = index_x[x1];
      			index_x[x1] = index_x[x2];
      			index_x[x2] = t;
      		}
      		if (c == 'c'){
      			lld y1, y2;
      			cin >> y1 >> y2;
      			lld t = index_y[y1];
      			index_y[y1] = index_y[y2];
      			index_y[y2] = t;
      		}
      	}
      }
      return 0;
}