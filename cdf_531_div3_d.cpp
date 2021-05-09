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
      lld n;
      string s;
      cin >> n >> s;
      lld len[3];
      lld pen[3];
      lld arr[n];
      vector <lld> index[3];
      memset(len,0,sizeof(len));
      memset(pen,0,sizeof(pen));
      for(lld i = 0; i < n; i += 1){
      	index[(lld)s[i]-48].push_back(i);
      	arr[i] = (lld)s[i]-48;
      	len[(lld)s[i]-48]++;
      }
      if (len[0] < (n/3)){
      	while(len[2]-pen[2] > (n/3) && len[0] < (n/3)){
      		arr[index[2][pen[2]]] = 0;
      		pen[2]++;
      		len[0]++;
      	}
      	while(len[1]-pen[1] > (n/3) && len[0] < (n/3)){
      		arr[index[1][pen[1]]] = 0;
      		pen[1]++;
      		len[0]++;
      	}
      }
      if (len[2] < (n/3)){
      	while(len[1] > (n/3) && len[2] < (n/3)){
      		arr[index[1][len[1]-1]] = 2;
      		len[1]--;
      		len[2]++;
      	}
      	while(len[0] > (n/3) && len[2] < (n/3)){
      		arr[index[0][len[0]-1]] = 2;
      		len[0]--;
      		len[2]++;
      	}
      }
      if (len[1] < (n/3)){
      	while(len[0] > (n/3) && len[1] < (n/3)){
      		arr[index[0][len[0]-1]] = 1;
      		len[1]++;
      		len[0]--;
      	}
      	while(len[2]-pen[2] > (n/3) && len[1] < (n/3)){
      		arr[index[2][pen[2]]] = 1;
      		pen[2]++;
      		len[1]++;
      	}
      }
      foi(i,n) cout << arr[i];
      return 0;
}