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
      lld n, k;
      cin >> n >> k;
      if (k == 1){
      	if (n ==1){
      		cout << "a";
      	}
      	else{
      		cout <<"-1";
      	}
      }
      else{
      	if (n < k){
      		cout <<"-1";
      	}
      	else{
      		k-=2;
      		n-=k;
      		string r = "";
      		for(lld i = 0; i < n; i += 1){
      			if (i % 2 == 0)
      				r += 'a';
      			else
      				r += 'b';
      		}
      		char c = 'c';
      		for(lld i = 0; i < k; i += 1){
      			r += c;
      			c += 1;
      		}
      		cout << r;
      	}
      }
      return 0;
}