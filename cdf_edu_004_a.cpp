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
      lld n, p, q;
      cin >> n >> p >> q;
      string s;
      cin >> s;
      lld a = -1, b = -1;
      for(lld i = 0; (p*i) <= n;  i += 1){
      	if ((n-(p*i))%q==0){
      		a = i;
      		b = (n-(p*i))/q;
      		break;
      	}
      }
      if (a >= 0 && b >= 0){
      	cout << a+b << "\n";
      	lld temp = a;
      	if (a > 0){
      		for(lld i = 0; i < p; i += 1){
      			cout << s[i];
      		}
      		cout <<  "\n";
      		a-=1;
      		lld pos = p;
      		while (a > 0){
      			for(lld j = pos; j < pos+p; j += 1){
      				cout << s[j];
      			}
      			cout <<  "\n";
      			pos += p;
      			a-=1;
      		}
      	}
      	if (b > 0){
      		for(lld i = (temp*p); i<q+(temp*p); i+=1){
      			cout << s[i];
      		}
      		cout <<  "\n";
      		b-=1;
      		lld pos = (temp*p)+q;
      		while (b > 0){
      			for(lld j = pos; j < pos+q; j += 1){
      				cout << s[j];
      			}
      			cout <<  "\n";
      			pos += q;
      			b-=1;
      		}
      	}
      }
      else{
      	cout << "-1";
      }
      return 0;
}