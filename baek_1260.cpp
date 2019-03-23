#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

// 인접리스트 사용이 시간복잡도 효율이 훨씬 좋다.
vector<int> al[1001];
int v[1001] = { 0 };
queue<int> aq;

void dfs(int s, int nodes)
{
	v[s] = 1;
	cout << s;
	for (int next : al[s])
	{
		if (!v[next])
		{
			cout << " ";
			dfs(next, nodes);
		}
	}
}

void bfs(int s, int nodes)
{
	aq.push(s);
	v[s] = 1;

	while (!aq.empty())
	{
		int cur = aq.front();
		cout << cur;
		aq.pop();

		for (int next : al[cur]) 
        {
			if (!v[next])
			{
				v[next] = 1;
				aq.push(next);
			}
		}
		if (aq.empty())
			break;
		cout << " ";
	}
}


int main()
{
	int nodes, edges, init;
	scanf("%d %d %d", &nodes, &edges, &init);
	for (int i = 1; i <= edges; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		al[n1].push_back(n2);
		al[n2].push_back(n1);
	}

	for (int i = 1; i <= nodes; i++)
	{
		sort(al[i].begin(), al[i].end());
	}
	
	dfs(init, nodes);
	cout << endl;
	memset(v, 0, sizeof(v));
	bfs(init, nodes);

	return 0;
}