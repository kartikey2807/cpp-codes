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
      lld n, d;
      cin >> n >> d;
      set <lld> idx;
      map <lld, lld> index;
      map <lld, lld> precr;
      for(lld i = 0; i < n; i += 1){
      	lld r;
      	cin >> r;
      	index[r] = i;
      	idx.insert(r);
      	if (idx.count(r-d)){
      		lld pos = index[r-d];
      		precr[i]= pos;
      	}
      	else{
      		idx.insert(r-d);
      		set <lld> :: iterator itr = idx.find(r-d);
      		itr++;
      		if (itr != idx.end()){
      			lld pos = index[*itr];
      			precr[i]= pos;
      		}
      		idx.erase(r-d);
      	}
      }
      lld count = 0;
      for(map <lld, lld> :: iterator p = precr.begin(); p != precr.end(); p++){
      	lld x = p->first ;
      	lld y = p->second;
      	lld diff = x-y-1 ;
      	if (diff >= 1){
      		count += (diff*(diff+1))/2;
      	}
      }
      cout << count;
      return 0;
}