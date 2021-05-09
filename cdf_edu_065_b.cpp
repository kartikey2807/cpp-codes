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
int A[] = {4,8,15,16,23,42};
set <int> vis;
void create ()
{
	for(int i = 0; i < 6; i += 1){
		vis.insert(A[i]);
	}
}
int get_ (int l, int r)
{
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      create();
      int a = get_(1,2);
      int b = get_(2,3);
      int c = get_(3,4);
      int d = get_(4,5);
      for(int i = 0; i < 6; i += 1){
      	for(int j = 0; j < 6; j += 1){
      		vector <int> v(6);
      		if ((a*A[j]) == (b*A[i]) && A[i] != A[j]){
      			set <int> temp = vis;
      			v[0] = A[i];
      			temp.erase(v[0]);
      			if (temp.count(A[j])){
      				v[2]= A[j];
      				temp.erase(v[2]);
      			}
      			if ((a%v[0] == 0) && temp.count(a/v[0])){
      				v[1] = a/v[0];
      				temp.erase(v[1]);
      			}
      			else{
      				continue;
      			}
      			if ((c%v[2] == 0) && temp.count(c/v[2])){
      				v[3] = c/v[2];
      				temp.erase(v[3]);
      			}
      			else{
      				continue;
      			}
      			if ((d%v[3] == 0) && temp.count(d/v[3])){
      				v[4] = d/v[3];
      				temp.erase(v[4]);
      			}
      			set <int> :: iterator itr = temp.begin();
      			v[5] = (*itr);
      			cout << "! ";
      			for(int k = 0; k < 6; k += 1){
      				cout << v[k] << " ";
      			}
      			cout << "\n";
      			fflush(stdout);
      			return 0;
      		}
      	}
      }
      return 0;
}