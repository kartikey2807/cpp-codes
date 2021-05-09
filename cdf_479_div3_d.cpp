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
      cin >> n;
      lld A[n];
      stack <lld> stk;
      queue <lld> que;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      lld min = MAX;
      set <lld> vis;
     	map <lld, lld> count;
      for(lld i = 0; i < n; i += 1){
      	if (A[i] < min)
      		min=A[i];
      	vis.insert(A[i]);
      	count[A[i]] += 1;
      }
      stk.push(min);
      count[min]-=1;
      if (count[min] == 0){
      	vis.erase(min);
      }
      while(true){
      	lld pos = stk.top();
      	if (vis.count(pos*3)){
      		stk.push(pos*3);
      		count[pos*3]-=1;
      		if (count[pos*3] == 0){
      			vis.erase(pos*3);
      		}
      	}
      	else{
      		if (pos%2 == 0 && vis.count(pos/2)){
      			stk.push(pos/2);
      			count[pos/2]-=1;
      			if (count[pos/2] == 0){
      				vis.erase(pos/2);
      			}
      		}
      		else{
      			break;
      		}
      	}
      }
      lld p = min;
      while(!vis.empty()){
      	if (p%3 == 0 && vis.count(p/3)){
      		que.push(p/3);
      		count[p/3]-=1;
      		p  = p/3;
      		if (count[p/3] == 0){
      			vis.erase(p/3);
      		}
      	}
      	else{
      		if (vis.count(p*2)){
      			que.push(p*2);
      			count[p*2]-=1;
      			p = p*2;
      			if (count[p*2] == 0){
      				vis.erase(p*2);
      			}
      		}
      		else{
      			break;
      		}
      	}
      }
      vector <lld> v;
      while(!stk.empty()){
      	v.push_back(stk.top());
      	stk.pop();
      }
      while(!que.empty()){
      	v.push_back(que.front());
      	que.pop();
      }
      for(lld i = 0; i < v.size(); i += 1){
      	cout << v[i] << " ";
      }
      return 0;
}