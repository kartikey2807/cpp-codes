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
vector <lld> x;
void xyz (vector <lld> num, lld p, lld res)
{
	dbl r = sqrt(res);
	if (floor(r)== r && res != 0){
		x.push_back(res);
	}
	for(lld i = p+1; i < num.size(); i += 1){
		lld x = (res*10)+num[i];
		xyz(num, i, x);
	}
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
      lld temp = n;
      vector <lld> num;
      while(temp != 0){
      	num.push_back(temp%10);
      	temp /= 10;
      }
      reverse(num.begin(),num.end());
      xyz(num,-1, 0);
      if (x.empty()){
      	cout << "-1\n";
      }
      else{
      	lld max = MIN;
      	for(lld i = 0; i < x.size(); i += 1){
      		lld temp = x[i];
      		lld count = 0;
      		while(temp!=0){
      			temp/=10;
      			count++;
      		}
      		if (x[i] != 0){
      			if (count > max)
      				max = count;
      		}
      	}
      	lld n = num.size();
      	cout << n-max;
      }
      return 0;
}