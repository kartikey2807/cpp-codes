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
      lld n, k;
      cin >> n >> k;
      string s;
      cin >> s;
      lld count = 0;
      for(lld i = 0; i < n; i += 1){
      	lld x = (lld)s[i];
      	count+= max(x-97,122-x);
      }
      if (k > count){
      	cout << "-1\n";
      }
      else{
      	string r = "";
      	lld i;
      	for(i = 0; i < n; i += 1){
      		if (k == 0){
      			break;
      		}
      		lld x = (lld)s[i];
      		char c;
      		lld y;
      		if ((x-97) > (122-x)){
      			if ((x-97) > k){
      				y = x-k;
      				k = 0;
      			}
      			else{
      				k-= x-97;
      				x-= x-97;
      				y = x;
      			}
      		}
      		else{
      			if ((122-x)> k){
      				y = x+k;
      				k = 0;
      			}
      			else{
      				k-= 122-x;
      				x+= 122-x;
      				y = x;
      			}
      		}
      		c = (char)y;
      		r += y;
      	}
      	for(lld j = i; j<n; j += 1){
      		r += s[j];
      	}
      	cout << r;
      }
      return 0;
}