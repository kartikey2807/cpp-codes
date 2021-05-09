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
lld xyz_ (lld x, lld y)
{
	switch(x){
		case 1 :
		case 3 : 
		case 5 :
		case 7 :
		case 8 :
		case 10:
		case 12: return 31;
		case 4 :
		case 6 :
		case 9 :
		case 11: return 30;
		case 2 : {
			if ((y%4 == 0 && y%100 != 0) || y%400 == 0){
				return 29;
			}
			else{
				return 28;
			}
		}
	}
}
lld count1 (lld start_year, lld start_month, lld start_day, lld end_year, lld end_month, lld end_day)
{
	lld sum = 0;
	for(lld i = start_year; i <= end_year; i++){
		if (i == start_year){
			for(lld j = start_month; j <= 12; j++){
				if (j == start_month){
					lld l = xyz_(j, i);
					for(lld k = start_day; k <= l; k++){
						sum+= 1;
					}
				}
				else{
					sum+= xyz_(j,i);
				}
			}
		}
		else{
			if (i == end_year){
				for(lld j = 1; j <= end_month; j++){
					if (j == end_month){
						for(lld k = 1; k <= end_day; k++){
							sum+= 1;
						}
					}
					else{
						sum+= xyz_(j,i);
					}
				}
			}
			else{
				for(lld j = 1; j <= 12; j++){
					sum+= xyz_(j, i);
				}
			}
		}
	}
	return sum;
}
lld count2 (lld start_year, lld start_month, lld start_day, lld end_year, lld end_month, lld end_day)
{
	lld sum = 0;
	for(lld i = start_month; i <= end_month; i++){
		if (i == start_month){
			lld l = xyz_(i, start_year);
			for(lld j = start_day; j<=l; j++){
				sum+= 1;
			}
		}
		else{
			if (i == end_month){
				for(lld j = 1; j <= end_day; j++){
					sum+= 1;
				}
			}
			else{
				sum+= xyz_(i, start_year);
			}
		}
	}
	return sum;
}
lld count3 (lld start_day, lld end_day)
{
	lld sum = 0;
	for(lld i = start_day; i <= end_day; i++){
		sum+= 1;
	}
	return  sum;
}
lld get_year (string s)
{
	lld r = 0;
	for(lld i = 0; i <= 3; i++){
		lld x = (lld)s[i]-48;
		r = (r*10)+x;
	}
	return r;
}
lld get_month (string s)
{
	lld r = 0;
	for(lld i = 5; i <= 6; i++){
		lld x = (lld)s[i]-48;
		r = (r*10)+x;
	}
	return r;
}
lld get_day (string s)
{
	lld r = 0;
	for(lld i = 8; i <= 9; i++){
		lld x = (lld)s[i]-48;
		r = (r*10)+x;
	}
	return r;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      string a, b;
      cin >> a >> b;
      lld year1 = get_year(a);
      lld year2 = get_year(b);
      lld month1 = get_month(a);
      lld month2 = get_month(b);
      lld day1 = get_day(a);
      lld day2 = get_day(b);
      lld ans;
      if (year1 < year2){
      	ans = count1(year1, month1, day1, year2, month2, day2);
      }
      else{
      	if (year1 > year2){
      		ans = count1(year2, month2, day2, year1, month1, day1);
      	}
      	else{
      		if (month1 < month2){
      			ans = count2(year1, month1, day1, year2, month2, day2);
      		}
      		else{
      			if (month1 > month2){
      				ans = count2(year2, month2, day2, year1, month1, day1);
      			}
      			else{
      				if (day1 < day2){
      					ans = count3(day1, day2);
      				}
      				else{
      					ans = count3(day2, day1);
      				}
      			}
      		}
      	}
      }
      cout << ans-1;
      return 0;
}