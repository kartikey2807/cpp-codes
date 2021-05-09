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
      lld n;
      cin >> n;
      lld L[n+1];
      set <lld> v[n+1];
      for(lld i = 1; i <= n; i += 1){
      	cin >> L[i];
      	for(lld j = 0; j < L[i]; j += 1){
      		lld r;
      		cin >> r;
      		v[i].insert(r);
      	}
      }
      for(lld i = 1; i <= n; i += 1){
      	set <lld> x = v[i];
      	lld LL[n+1];
      	for(lld j = 1; j  <=  n; j += 1){
      		LL[j] = 0;
      	}
      	lld count = 0;
      	for(set <lld> :: iterator itr = x.begin(); itr!=x.end(); itr++){
      		lld k, p = (*itr);
      		for(k = 1; k <= n; k += 1){
      			if (v[k].count(p)){
      				LL[k]++;
      			}
      		}
      		for(k = 1; k <= n; k += 1){
      			if (LL[k] == L[k]){
      				count++;
      			}
      		}
      	}
      	if (count == 1){
      		cout << "YES\n";
      	}
      	else{
      		cout <<  "NO\n";
      	}
      }
      return 0;
}