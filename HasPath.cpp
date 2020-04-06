#include <iostream>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    int n,e;
	cin>>n>>e;
    bool flag=0;
  	int** edges=new int*[n];
	int i ,j,k,sv;
	for(i=0;i<n;i++)
    {
        edges[i]=new int[n];
        memset(edges[i],0,n*sizeof(int));
        //for(j=0;j<n;j++)
        //cout<<edges[i][j];
        //cout<<" ";
    }
    int st,en;
    cin>>st>>en;
    for(i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
        //cout<<f<<s;
    }
    int* visited=new int[n];
    memset(visited,0,n*sizeof(int));
  	queue<int> sta;
  	sta.push(st);
  	visited[st]=1;
  	while(!sta.empty())
    {
      sv=sta.front();
      //cout<<sv<<" ";
      sta.pop();
      for(i=0;i<n;i++)
      {
        if(edges[sv][i]==1 && visited[i]==0)
        {
          sta.push(i);
          visited[i]=1;
          if(i==en)
          flag=1;
        }
      }
    }
    if(st==en)
    flag=1;
    if(flag)
    cout<<"true";
    else 
    cout<<"false";
  return 0;
}
