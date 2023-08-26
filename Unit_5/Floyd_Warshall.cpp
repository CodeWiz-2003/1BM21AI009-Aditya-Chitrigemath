#include <bits/stdc++.h>
using namespace std;
#define V 4
#define INF 99999

class Floyd_Warshall{
public:
	void floydWarshall(int **dist)
	{
		int i, j, k;
		for (k = 0; k < V; k++) {
			for (i = 0; i < V; i++) {
				for (j = 0; j < V; j++) {
					if (dist[i][j] > (dist[i][k] + dist[k][j])
						&& (dist[k][j] != INF
							&& dist[i][k] != INF))
						dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
		printSolution(dist);
	}

	void printSolution(int **dist)
	{
		cout << "The following matrix shows the shortest "
				"distances"
				" between every pair of vertices \n";
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (dist[i][j] == INF)
					cout << "INF"
						<< " ";
				else
					cout << dist[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	int **graph;
	graph = (int**)calloc(V, sizeof(int*));
	for(int i=0; i<V; i++)
		*(graph+i) = (int*)calloc(V, sizeof(int));
	int g[V][V] = { { 0, 5, INF, 10 },
						{ INF, 0, 3, INF },
						{ INF, INF, 0, 1 },
						{ INF, INF, INF, 0 } };

	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++)
			graph[i][j] = g[i][j];
	}
	Floyd_Warshall fw;
	fw.floydWarshall(graph);
	return 0;
}