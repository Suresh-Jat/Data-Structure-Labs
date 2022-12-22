#include <stdio.h>
int no_ver;
void printGraph(int adj[][no_ver])
{
	printf("**************************\n");

	for (int i = 0; i < no_ver; i++)
	{
		for (int j = 0; j < no_ver; j++)
		{
			printf(" %d  ", adj[i][j]);
		}
		printf("\n");
	}
	printf("**************************\n");
}

void bfs(int adj[][no_ver], int start)
{
	int visited[no_ver], queue[no_ver], front = -1, rear = -1;

	for (int i = 0; i < no_ver; i++)
		visited[i] = 0;

	front++;
	queue[++rear] = start;
	visited[start] = 1;

	while (front <= rear)
	{
		start = queue[front++];
		printf("%d\t", start);

		for (int i = 0; i < no_ver; i++)
		{
			if (adj[start][i] == 1 && visited[i] != 1)
			{
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}
int main()
{
	int s, d, ch, start;
	printf("\nEnter the number of vertices : ");
	scanf("%d", &no_ver);
	int adj[no_ver][no_ver], visited[no_ver];

	for (int i = 0; i < no_ver; i++)
	{
		for (int j = 0; j < no_ver; j++)
		{
			adj[i][j] = 0;
		}
	}

	while (s != -1 && d != -1)
	{
		printf("Enter an Edge fromnode(0 to %d) to node(0 to %d) : ", no_ver, no_ver);
		scanf("%d%d", &s, &d);
		adj[s][d] = 1;
		adj[d][s] = 1;
	}

	do
	{
		printf("\nEnter 1 for BFS\nEnter 2 for printing adjacency matrix\nEnter 3 to Exit : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the Vertex fron which do you wanted to start : ");
			scanf("%d", &start);
			bfs(adj, start);
			break;
		case 2:
			printGraph(adj);
			break;
		case 3:
			break;
		}

	} while (ch != 4);

	return 0;
}