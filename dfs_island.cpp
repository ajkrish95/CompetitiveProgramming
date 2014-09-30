#include<stdio.h>
#include<iostream>

using namespace std;
 
int n,m,a[10][10];

int dfs(int i,int j)
{
    int ans = 1;
 
        if(i-1>=0&&i<n&&j>=0&&j<m&&a[i-1][j]==1)
        {
            a[i-1][j]=2;
            ans = ans + dfs(i-1,j);
        }
        
        if(i>=0&&i<n&&j-1>=0&&j-1<m&&a[i][j-1]==1)
        {
            a[i][j-1]=2;
            ans = ans + dfs(i,j-1);
        }
        
        if(i-1>=0&&i-1<n&&j-1>=0&&j-1<m&&a[i-1][j-1]==1)
        {
            a[i-1][j-1]=2;
            ans = ans + dfs(i-1,j-1);
        }
        
        if(i+1>=0&&i+1<n&&j+1>=0&&j+1<m&&a[i+1][j+1]==1)
        {
            a[i+1][j+1]=2;
            ans = ans + dfs(i+1,j+1);
        }

 
        if(i+1>=0&&i+1<n&&j>=0&&j<m&&a[i+1][j]==1)
        {
            a[i+1][j]=2;
            ans = ans + dfs(i+1,j);
        }
        
        if(i>=0&&i<n&&j+1>=0&&j+1<m&&a[i][j+1]==1)
        {
            a[i][j+1]=2;
            ans = ans + dfs(i,j+1);
        }
        
        if(i-1>=0&&i-1<n&&j+1>=0&&j+1<m&&a[i-1][j+1]==1)
        {
            a[i-1][j+1]=2;
            ans = ans + dfs(i-1,j+1);
        }
        
        if(i+1>=0&&i+1<n&&j-1>=0&&j-1<m&&a[i+1][j-1]==1)
        {
            a[i+1][j-1]=2;
            ans = ans + dfs(i+1,j-1);
        }
    
    return ans;
}

int find_largest_island()
{
    int i,j,max=0,size,count = 0;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i>=0&&i<n&&j>=0&&j<m&&a[i][j]==1)
            {
                a[i][j]=2;
                size = dfs(i,j);
                count++;
            }
\
            if(size>max)
            {
                max = size;
            }
         }
    }
    cout<<count<<endl;
    return max;
}

int main()
{
    int i,j,ans;
    
    cin>>n>>m;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    
    ans = find_largest_island();
    
    cout<<ans<<endl;
 }
