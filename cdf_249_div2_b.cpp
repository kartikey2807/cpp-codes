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
      lld n, k;
      cin >> n >> k;
      vector <lld> index;
      while(n){
      	index.push_back(n%10);
      	n/=10;
      }
      reverse(index.begin(),index.end());
      for(lld i = 0; i < index.size(); i += 1){
      	if (k == 0) break;
      	if (index[i] == 9)
      		continue;
      	lld pos = -1;
      	lld max = MIN;
      	for(lld j = i+1; j < index.size(); j += 1){
      		if (index[j] > index[i] && (j-i)<=k){
      			if (index[j] > max){
      				max=index[j];
      				pos=j;
      			}
      		}
      	}
      	if (pos != -1){
      		for(lld j = pos; j > i; j -= 1){
      			swap(index[j],index[j-1]);
      			k--;
      		}
      	}
      }
      for(lld i = 0; i < index.size(); i += 1){
      	cout << index[i];
      }
      return 0;
}