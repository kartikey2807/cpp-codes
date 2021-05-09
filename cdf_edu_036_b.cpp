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
      lld n, pos, l, r;
      cin >> n >> pos >> l >> r;
      if (pos >= l && pos <= r){
      	if (l > 1 && r < n){
      		lld x = (pos-l)+(r-l)+2;
      		lld y = (r-pos)+(r-l)+2;
      		cout << (x < y ? x : y);
      	}
      	else{
      		if (l > 1){
      			cout << (pos-l)+1;
      		}
      		else{
      			if (r < n){
      				cout << (r-pos)+1;
      			}
      			else{
      				cout << "0";
      			}
      		}
      	}
      }
      else{
      	if (pos < l){
      		lld x = (l-pos)+1;
      		if (r < n){
      			x+= (r-l)+1;
      		}
      		cout << x;
      	}
      	if (pos > r){
      		lld x = (pos-r)+1;
      		if (l > 1){
      			x+= (r-l)+1;
      		}
      		cout << x;
      	}
      }
      return 0;
}