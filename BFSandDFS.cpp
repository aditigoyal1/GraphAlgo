#include<bits/stdc++.h>
using namespace std;
void printDFS(int ** edges,int n,int start,bool* visited)
{
	cout<<start<<endl;
	visited[start]=true;
	for(int i=0;i<n;i++)
	{
		if(i==start)
		continue;
		if(edges[start][i]==1)
		{
			if(visited[i])
			continue;
			printDFS(edges,n,i,visited);
		}
	}
}


void printBFS(int **edges,int n,int start,bool* visited)
{
	queue<int>q;
	
	q.push(start);
	visited[start]=true;
	while(!q.empty())
	{
		int cv=q.front();
		q.pop();
		cout<<cv<<endl;
		for(int i=0;i<n;i++)
		{
			if(edges[cv][i]==1 && !visited[i])
			{
				q.push(i);
				visited[i]=true;
			}
		}
	}
	
	
}

void BFS(int ** edges,int n){
    bool * visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			printBFS(edges,n,i,visited);
		}
	}
	
	delete [] visited;
}

void DFS(int ** edges,int n){
    bool * visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			printBFS(edges,n,i,visited);
		}
	}
	
	delete [] visited;
}
int main()
{
	int n;
	int e;
	cin>>n>>e;
	int ** edges=new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	
	
	//Dfs
	DFS(edges,n);
	
	//bfs
	BFS(edges,n);
	
	
	
	for(int i=0;i<n;i++)
	{
		delete [] edges[i];
	}
	delete [] edges;
	
}
