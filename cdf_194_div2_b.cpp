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
set <lld> get_inter (map <lld, vector<lld> > index, lld x, lld y)
{
	set <lld> ans;
	for(lld i = 0; i < index[x].size(); i++){
		for(lld j = 0; j < index[y].size();j++){
			if (index[x][i]  ==  index[y][j]){
				ans.insert(index[x][i]);
			}
		}
	}
	return ans;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      set <lld> points;
      map <lld, vector<lld> > index;
      for(lld i = 0; i < 8; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	points.insert(x);
      	index[x].push_back(y);
      }
      lld len = points.size();
      lld A[len];
      lld j = 0;
      for(set <lld> :: iterator itr = points.begin(); itr != points.end(); itr++){
      	sort(index[*itr].begin(), index[*itr].end());
      	A[j] = *itr;
      	j++;
      }
      for(lld i = 0; i < len; i += 1){
      	for(lld j = i+2; j < len; j += 1){
      		set <lld> pts = get_inter(index, A[i], A[j]);
      		if (pts.size()>= 3){
      			lld count = 0;
      			for(lld k = i+1; k < j; k += 1){
      				set <lld> x;
      				for(lld start = 0; start < index[A[k]].size(); start++){
      					if (pts.count(index[A[k]][start])){
      						count++;
      						x.insert(index[A[k]][start]);
      					}
      				}
      				if (count == 2){
      					set <lld> :: iterator p1 = x.begin();
      					set <lld> :: iterator p2 = p1;
      					p2++;
      					lld val1 = *p1;
      					lld val2 = *p2;
      					for(set <lld> :: iterator itr = pts.begin(); itr != pts.end(); itr++){
      						 if ((*itr) > val1 && (*itr) < val2){
      						 	cout << "respectable";
      						 	return 0;
      						 }
      					}
      				}
      			}
      		}
      	}
      }
      cout << "ugly";
      return 0;
}