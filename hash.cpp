template typename<T> 
class Hash {
  void insert(int a, T t); // O(1)
  T get(int a); // O(1)
};


int longest(int a[],int n)
{
	int i,vis[n],max=0,count,temp;
	Hash hash;
	
	for(i=0;i<n;i++)
	{
		hash.insert(a[i],i);
	}
	
	for(i=0;i<n;i++)
	{
		vis[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			temp=a[i]+1;
			count = 1;
			
			while(hash.get(temp)!=NULL)
			{
				vis[hash.get(temp)] = 1;
				temp = temp + 1;
				count = count + 1;
			}
			
			temp = a[i] -1 ;
			
			while(hash.get(temp)!=NULL)
			{
				vis[hash.get(temp)] = 1;
				temp = temp - 1;
				count = count + 1;
			}
			
			if(count > max)
			{
				max = count;
			}
		}
	}
	
	return max;
}
