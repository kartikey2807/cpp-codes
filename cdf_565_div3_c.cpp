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
      lld n;
      cin >> n;
      vector <lld> index[100];
      lld arr[] = {4,8,15,16,23,42};
      for(lld i = 0; i < n; i += 1){
            lld r;
            cin >> r;
            index[r].push_back(i+1);
      }
      lld idx[100];
      for(lld i = 0; i<100; i += 1){
            idx[i] = 0;
      }
      lld len[100];
      for(lld i = 0; i < 6; i += 1){
            len[arr[i]] = index[arr[i]].size();
      }
      lld count = 0;
      lld flag  = 1;
      for(lld i = 0; i < index[arr[0]].size(); i += 1){
            lld prev  =  index[arr[0]][i];
            for(lld k = 1; k < 6; k += 1){
                  lld f = 0;
                  lld j;
                  for(j = idx[arr[k]]; j < len[arr[k]]; j += 1){
                        if (index[arr[k]][j] > prev){
                              prev=index[arr[k]][j];
                              f = 1;
                              break;
                        }
                  }
                  idx[arr[k]] = j+1;
                  if (f == 0){
                        flag = 0;
                        break;
                  }
            }
            if (flag == 0){
                  break;
            }
            count++;
      }
      cout <<(n-(6*count));
      return 0;
}