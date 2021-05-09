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
lld count (string s1[], string s2[], string s3[], string s4[], lld n)
{
	lld dda[2*n][2*n];
	for(lld i = 0; i < n; i += 1){
		for(lld j = 0; j < n; j += 1){
			dda[i][j] = (lld)s1[i][j]-48;
		}
	}
	for(lld i = 0; i < n; i += 1){
		for(lld j = n; j < (2*n); j += 1){
			dda[i][j] = (lld)s2[i][j-n]-48;
		}
	}
	for(lld i = n; i < (2*n); i += 1){
		for(lld j = 0; j < n; j += 1){
			dda[i][j] = (lld)s3[i-n][j]-48;
		}
	}
	for(lld i = n; i < (2*n); i += 1){
		for(lld j = n; j < (2*n); j += 1){
			dda[i][j] = (lld)s4[i-n][j-n]-48;
		}
	}
	lld dda1[2*n][2*n];
	for(lld i = 0; i < (2*n); i += 1){
		if (i%2 == 0){
			for(lld j = 0; j < (2*n); j += 1){
				if (j%2 == 0)
					dda1[i][j] = 1;
				else
					dda1[i][j] = 0;
			}
		}
		else{
			for(lld j = 0; j < (2*n); j += 1){
				if (j%2 == 0)
					dda1[i][j] = 0;
				else
					dda1[i][j] = 1;
			}
		}
	}
	lld dda2[2*n][2*n];
	for(lld i = 0; i < (2*n); i += 1){
		if (i%2 != 0){
			for(lld j = 0; j < (2*n); j += 1){
				if (j%2 == 0)
					dda2[i][j] = 1;
				else
					dda2[i][j] = 0;
			}
		}
		else{
			for(lld j = 0; j < (2*n); j += 1){
				if (j%2 == 0)
					dda2[i][j] = 0;
				else
					dda2[i][j] = 1;
			}
		}
	}
	lld count1 = 0;
	lld count2 = 0;
	for(lld i = 0; i < 2*n; i += 1){
		for(lld j = 0; j < 2*n; j += 1){
			if (dda[i][j] != dda1[i][j])
				count1++;
		}
	}
	for(lld i = 0; i < 2*n; i += 1){
		for(lld j = 0; j < 2*n; j += 1){
			if (dda[i][j] != dda2[i][j])
				count2++;
		}
	}
	return min(count1, count2);
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
      string s[4][n];
      for(lld i = 0; i < n; i += 1){
      	cin >> s[0][i];
      }
      for(lld i = 0; i < n; i += 1){
      	cin >> s[1][i];
      }
      for(lld i = 0; i < n; i += 1){
      	cin >> s[2][i];
      }
      for(lld i = 0; i < n; i += 1){
      	cin >> s[3][i];
      }
      vector <lld> a;
      a.push_back(count(s[0], s[1], s[2], s[3], n));
      a.push_back(count(s[0], s[1], s[3], s[2], n));
      a.push_back(count(s[0], s[2], s[1], s[3], n));
      a.push_back(count(s[0], s[2], s[3], s[1], n));
      a.push_back(count(s[0], s[3], s[1], s[2], n));
      a.push_back(count(s[0], s[3], s[2], s[1], n));
      a.push_back(count(s[1], s[0], s[2], s[3], n));
      a.push_back(count(s[1], s[0], s[3], s[2], n));
      a.push_back(count(s[1], s[2], s[0], s[3], n));
      a.push_back(count(s[1], s[2], s[3], s[0], n));
      a.push_back(count(s[1], s[3], s[0], s[2], n));
      a.push_back(count(s[1], s[3], s[2], s[0], n));
      a.push_back(count(s[2], s[1], s[0], s[3], n));
      a.push_back(count(s[2], s[1], s[3], s[0], n));
      a.push_back(count(s[2], s[0], s[1], s[3], n));
      a.push_back(count(s[2], s[0], s[3], s[1], n));
      a.push_back(count(s[2], s[3], s[1], s[0], n));
      a.push_back(count(s[2], s[3], s[0], s[1], n));
      a.push_back(count(s[3], s[1], s[2], s[0], n));
      a.push_back(count(s[3], s[1], s[0], s[2], n));
      a.push_back(count(s[3], s[2], s[1], s[0], n));
      a.push_back(count(s[3], s[2], s[0], s[1], n));
      a.push_back(count(s[3], s[0], s[1], s[2], n));
      a.push_back(count(s[3], s[0], s[2], s[1], n));
      lld min = MAX;
      for(lld i = 0; i < 24; i += 1){
      	if (a[i] < min)
      		min = a[i];
      }
      cout << min;
      return 0;
}