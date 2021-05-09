#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld t;
    cin >> t;
    while(t--)
    {
    	lld n;
    	cin >> n;
    	lld A[n];
    	map <lld, lld> cnt;
    	for(lld i = 0; i < n; i += 1)
    	{
    		cin >> A[i];
    		cnt[A[i]]++;
    	}
    	priority_queue <pair <lld, lld>> pq;
    	for(auto itr : cnt)
    		pq.push({itr.second,itr.first});
    	lld sz = n;
    	while(pq.size() >= 2)
    	{
    		pair <lld, lld> p1 = pq.top();
    		pq.pop();
    		pair <lld, lld> p2 = pq.top();
    		pq.pop();
    		p1.first--;
    		p2.first--;
    		sz-= 2;
    		if (p1.first)
    			pq.push(p1);
    		if (p2.first)
    			pq.push(p2);
    	}
    	cout << sz << "\n";
    }
    return 0;
}