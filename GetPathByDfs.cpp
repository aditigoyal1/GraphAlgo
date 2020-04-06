#include <vector>
#include<bits/stdc++.h>
bool flag=0;
using namespace std;
vector<int> vec;
void printdfs(int **edges,int n,int st,int *visited,int en)
{
    //cout<<st;
    //visited[st]=1;
    if(st==en){
    flag=1;
    }
    for(int i=0;i<n;i++)
    {
        if(edges[st][i]==1 && visited[i]==0)
        {
            visited[i]=1;
            printdfs(edges,n,i,visited,en);
        }
        if(flag==1)
        {
            //cout<<st<<" ";
            vec.push_back(st);
            return;
        }
    }
}
int main() {
	int n,e,st=1,en,i,j,f,s;
	cin>>n>>e;
	int ** edges=new int*[n];
	for(i=0;i<n;i++)
	{
	    edges[i]=new int[n];
	    for(j=0;j<n;j++)
	    edges[i][j]=0;
	}
	int *visited =new int[n];
	for(i=0;i<n;i++)
	visited[i]=0;
	for(i=0;i<e;i++)
	{
	    cin>>f>>s;
	    edges[f][s]=1;
	    edges[s][f]=1;
	    //cout<<s<<f<<" ";
	}
	cin>>st>>en;
	visited[st]=1;
	printdfs(edges,n,st,visited,en);
	for(i=0;i<vec.size();i++)
	cout<<vec[i]<<" ";
}

