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
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
set <lld> grp;
lld xyz1 (lld A[], lld B[])
{
	for(lld i = 0; i < 6; i += 1){
		for(lld j = 0; j < 6; j += 1){
			grp.insert((A[i]*10)+B[j]);
			grp.insert((B[j]*10)+A[i]);
		}
	}
}
lld xyz2 (lld A[], lld B[], lld C[]){
	for(lld i = 0; i < 6; i += 1){
		for(lld j = 0; j < 6; j += 1){
			for(lld k = 0; k < 6; k += 1){
				grp.insert((A[i]*100)+(B[j]*10)+C[k]);
				grp.insert((A[i]*100)+(C[k]*10)+B[j]);
				grp.insert((B[j]*100)+(A[i]*10)+C[k]);
				grp.insert((B[j]*100)+(C[k]*10)+A[i]);
				grp.insert((C[k]*100)+(A[i]*10)+B[j]);
				grp.insert((C[k]*100)+(B[j]*10)+A[i]);
			}
		}
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      if (n == 1){
      	lld A[6];
      	for(lld i = 0; i < 6; i += 1){
      		cin >> A[i];
      		grp.insert(A[i]);
      	}
      	lld x = 1;
      	for(set <lld> :: iterator itr = grp.begin(); itr != grp.end(); itr++){
      		lld c = *itr;
      		if (c == 0){
      			continue;
      		}
      		if (c != x){
      			break;
      		}
      		x++;
      	}
      	cout << x-1;
      }
      if (n == 2){
      	lld A[6];
      	lld B[6];
      	for(lld i = 0; i < 6; i += 1){
      		cin >> A[i];
      		grp.insert(A[i]);
      	}
      	for(lld i = 0; i < 6; i += 1){
      		cin >> B[i];
      		grp.insert(B[i]);
      	}
      	xyz1(A, B);
      	lld x = 1;
      	for(set <lld> :: iterator itr = grp.begin(); itr != grp.end(); itr++){
      		lld c = *itr;
      		if (c == 0){
      			continue;
      		}
      		if (c != x){
      			break;
      		}
      		x++;
      	}
      	cout << x-1;
      }
      if (n == 3){
      	lld A[6], B[6], C[6];
      	for(lld i = 0; i < 6; i += 1){
      		cin >> A[i];
      		grp.insert(A[i]);
      	}
      	for(lld i = 0; i < 6; i += 1){
      		cin >> B[i];
      		grp.insert(B[i]);
      	}
      	for(lld i = 0; i < 6; i += 1){
      		cin >> C[i];
      		grp.insert(C[i]);
      	}
      	xyz1(A,B);
      	xyz1(B,C);
      	xyz1(A,C);
      	xyz2(A,B,C);
      	lld x = 1;
      	for(set <lld> :: iterator itr = grp.begin(); itr != grp.end(); itr++){
      		lld c = *itr;
      		if (c == 0){
      			continue;
      		}
      		if (c != x){
      			break;
      		}
      		x++;
      	}
      	cout << x-1;
      }
      return 0;
}