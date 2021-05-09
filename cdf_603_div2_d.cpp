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
#define LEN 200005
lld vis[LEN];
void dfs (vector <lld> index[], lld pos){
	vis[pos] = 1;
	for(lld i = 0; i < index[pos].size(); i++){
		if (vis[index[pos][i]]  == -1)
			dfs(index,index[pos][i]);
	}
}
lld bin (string s, lld l, lld r, char x){
	lld mid;
	while(l <= r){
		mid = (l+r)/2;
		if (s[mid] == x)
			return 1;
		if (s[mid]  > x)
			r = mid-1;
		if (s[mid]  < x)
			l = mid+1;
	}
	return 0;
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
      lld len[n];
      string s[n],a[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> s[i];
      	a[i] = s[i];
      	len[i] = a[i].length();
      	sort(a[i].begin(),a[i].end());
      }
      vector <lld> index[n];
      for(char ch = 'a'; ch <= 'z'; ch++){
      	vector <lld> v;
      	foi(i,n){
      		if (bin(a[i],0,len[i]-1,ch) == 1)
      			v.push_back(i);
      	}
      	if (v.size() > 1){
      		for(lld i = 1; i < v.size(); i += 1){
      			index[v[i]].push_back(v[i-1]);
      			index[v[i-1]].push_back(v[i]);
      		}
      	}
      }
      lld c = 0;
      memset(vis, -1,  sizeof(vis));
      for(lld i = 0; i < n; i += 1){
      	if (vis[i]  == -1){
      		c++;
      		dfs(index,i);
      	}
      }
      cout << c << "\n";
      return 0;
}