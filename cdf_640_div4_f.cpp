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
      	lld n1, n2, n3;
      	cin >> n1 >> n2 >> n3;
      	vector <lld> v;
      	lld f = 0;
      	if (n1 != 0){
      		f++;
      		for(lld i = 0; i < n1+1; i += 1)
      			v.push_back(0);
      	}
      	if (n3 != 0){
      		f++;
      		for(lld i = 0; i < n3+1; i += 1)
      			v.push_back(1);
      	}
      	if (f == 2){
      		n2-=1;
      		lld count = 0;
      		while(count < n2){
      			v.push_back(count%2);
      			count += 1;
      		}
      	}
      	else{
      		if (v.empty()){
      			v.push_back(1);
      		}
      		lld len = v.size();
      		if (v[len-1] == 0){
      			lld count = 0;
      			while(count < n2){
      				v.push_back((count+1)%2);
      				count += 1;
      			}
      		}
      		else{
      			lld count = 0;
      			while(count < n2){
      				v.push_back((count+0)%2);
      				count += 1;
      			}
      		}
      	}
      	foi(i,v.size()) cout << v[i];
      	cout << "\n";
      }
      return 0;
}