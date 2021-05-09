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
vector <lld> getfact (lld x)
{
      vector <lld> v;
	while (x%2==0){
            x/=2;
            v.push_back(2);
      }
      for(lld i = 3; i <= sqrt(x); i += 2){
            while (x%i==0){
                  x/=i;
                  v.push_back(i);
            }
      }
      if (x > 2){
            v.push_back(x);
      }
      return v;
}
lld gcd_ (lld a, lld b)
{
	lld max = a > b ? a : b;
	lld min = a < b ? a : b;
	while(min){
		lld rem = max%min;
		max = min;
		min = rem;
	}
	return max;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld a, b;
      cin >> a >> b;
      lld g = gcd_(a, b);
      a/=g;
      b/=g;
      lld f = 1;
      map <lld, lld> count1, count2;
      vector <lld> v = getfact(a);
      vector <lld> w = getfact(b);
      for(lld i = 0; i < v.size(); i+= 1){
      	if (v[i] == 2 || v[i] == 3 || v[i] == 5){
      		count1[v[i]]+=1;
      	}
      	else{
      		f = 0;
      	}
      }
      for(lld i = 0; i < w.size(); i+= 1){
      	if (w[i] == 2 || w[i] == 3 || w[i] == 5){
      		count2[w[i]]+=1;
      	}
      	else{
      		f = 0;
      	}
      }
      if (f == 0){
      	cout << "-1";
      }
      else{
      	lld count = abs(count2[2]-count1[2]) + abs(count2[3]-count1[3]) + abs(count2[5]-count1[5]);
      	cout << count;
      }
      return 0;
}