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
    	lld n, m;
    	cin >> n >> m;
    	lld A[n],B[n],C[m];
    	for(lld i = 0; i < n; i += 1)
    		cin >> A[i];
    	for(lld i = 0; i < n; i += 1)
    		cin >> B[i];
    	for(lld i = 0; i < m; i += 1)
    		cin >> C[i];
    	queue<lld>target[n+1];
    	map <lld, lld> foccur;
    	for(lld i = 0; i < n; i += 1)
    	{
    		if (A[i] != B[i])
    			target[B[i]].push(i);
    		foccur[B[i]] = i;
    	}
    	vector <lld> who(m);
    	queue <lld> container;
    	for(lld i = 0; i < m; i += 1)
    	{
    		if (foccur.count(C[i]))
    		{
    			if (!target[C[i]].empty())
    			{
    				lld x = target[C[i]].front();
    				A[x] = B[x];
    				who[i] = x;
    				target[C[i]].pop();
    			}
    			else
    			{
    				A[foccur[C[i]]] = B[foccur[C[i]]];
    				who[i] = foccur[C[i]];
    			}
    		}
    		else
    			container.push(i);
    	}
    	if (foccur.count(C[m-1]))
    	{
    		while(!container.empty())
    		{
    			lld x = container.front();
    			who[x] = who[m-1];
    			container.pop();
    		}
    		lld f = 1;
    		for(lld i = 0; i < n; i += 1)
    		{
    			if (A[i] != B[i])
    				f = 0;
    		}
    		if (f == 0)
    			cout <<  "NO\n";
    		else
    		{
    			cout << "YES\n";
    			for(lld i = 0; i < m; i += 1)
    				cout << who[i]+1 << " ";
    			cout <<"\n";
    		}
    	}
    	else
    	{
    		cout <<  "NO\n";
    	}
    }
    return 0;
}