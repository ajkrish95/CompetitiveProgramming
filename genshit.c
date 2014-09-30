#include<stdio.h>
long int c[2502][2502];
int main()
{
   long int t,i,j,k,n,source,target,d;
   scanf("%ld",&t);
   while(t--)
   {
             scanf("%ld",&n);
             n+=2;
             long int a[n],b[n],visited[n],dist[n],min;
             for(i=0;i<n;i++)
             {
             dist[i]=10000000;
             visited[i]=0;
             }
             dist[n-2]=0;
             for(i=0;i<n;i++)
             scanf("%ld%ld",&a[i],&b[i]);
             for(i=0;i<n;i++)
             for(j=0;j<n;j++)
             c[i][j]=(a[j]-a[i])*(a[j]-a[i])+(b[j]-b[i])*(b[j]-b[i]);
             source=n-2;
             visited[source]=1;
             target=n-1;
             while(visited[target]!=1)
             {
                min=10000000;k=0;
                for(i=0;i<n;i++)
                {
                                d=dist[source]+c[source][i];
                                if(d<dist[i]&&visited[i]==0)
                                dist[i]=d;
                                if(min>dist[i]&&visited[i]==0)
                                {
                                min=dist[i];
                                k=i;
                                }
                }
                visited[k]=1;source=k;
             }
             printf("%ld\n",dist[target]);
   }
   return 0;
} 
                                
