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
vector <lld> get_ (lld x)
{
	vector <lld> ans;
	while(x){
		ans.push_back(x%10);
		x /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      vector <lld> v;
      while(n){
      	v.push_back(n%10);
      	n /= 10;
      }
      reverse(v.begin(), v.end());
      lld res = (v[0]*10000) + (v[2]*1000) + (v[4]*100) + (v[3]*10) + v[1];
      lld a = pow(res, 2);
      lld b = pow(res, 3);
      vector <lld> A = get_(a);
      vector <lld> B = get_(b);
      lld L = A.size();
      lld M = B.size();
      lld c = 0;
      lld sum = 0;
      vector <lld> ans;
      for(lld i = L-1; c < 5; i -= 1){
      	lld p = 0;
      	lld z;
      	ans.clear();
      	lld count = 0;
      	for(lld j = M-1; count < 5-c; j -= 1){
      		p = (A[i]*B[j])+p;
      		z = p%10;
      		p = p/10;
      		ans.push_back(z);
      		count++;
      	}
      	lld r = 0;
      	reverse(ans.begin(), ans.end());
      	for(lld j = 0; j < ans.size(); j++){
      		r = (r*10)+ans[j];
      	}
      	sum += r*pow(10,c);
      	c++;
      }
      vector<lld>dg;
      lld count = 0;
      while(count < 5){
      	dg.push_back(sum%10);
      	sum /= 10;
      	count+= 1;
      }
      reverse(dg.begin(), dg.end());
      for(lld i = 0; i < dg.size(); i++){
      	cout << dg[i];
      }
      return 0;
}