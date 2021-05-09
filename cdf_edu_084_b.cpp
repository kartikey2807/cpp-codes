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
      	lld n, i;
      	cin >> n;
      	lld j, r;
      	lld L[n];
      	vector <lld> p[n];
      	foi(i,n){
      		cin >> L[i];
      		foi(j,L[i]){
      			cin >> r;
      			p[i].push_back(r);
      		}
      	}
      	set  <lld>  taken;
      	lld F[n];
      	foi(i,n){
      		F[i] = 0;
      		foi(j,L[i]){
      			if (! taken.count(p[i][j])){
      				taken.insert(p[i][j]);
      				F[i] = 1;
      				break;
      			}
      		}
      	}
      	lld pos = -1;
      	for(i = 1; i<=n;i+=1){
      		if (!taken.count(i)){
      			pos=i;
      			break;
      		}
      	}
      	if (pos == -1){
      		cout << "OPTIMAL\n";
      	}
      	else{
      		foi(i,n){
      			if (F[i] == 0)
      				break;
      		}
      		cout << "IMPROVE\n";
      		cout << i+1 << " " << pos << "\n";
      	}
      }
      return 0;
}