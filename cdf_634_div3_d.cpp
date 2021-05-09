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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
            lld A[9][9];
            for(lld i = 0; i < 9; i++){
                  string s;
                  cin >> s;
                  for(lld j = 0; j < 9; j++){
                        A[i][j]=(lld)s[j]-48;
                  }
            }
            A[2][2] = A[0][0];
            A[5][5] = A[3][3];
            A[8][8] = A[6][6];
            A[0][3] = A[1][3];
            A[1][7] = A[2][7];
            A[4][6] = A[5][6];
            A[3][0] = A[4][0];
            A[7][1] = A[8][1];
            A[6][4] = A[7][4];
            for(lld i = 0; i < 9; i++){
                  for(lld j = 0; j < 9; j++){
                        cout << A[i][j];
                  }
                  cout << "\n";
            }
      }
      return 0;
}