//Given: {11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
//3
//looking for x

int f(int index,int max_index,int n)
{
    if(index < n-(max_index+1))
        return index + max_index +1;
    else
        return index - (n-max_index-1);     
}

int bin_search(int a[],int n,int max_index,int x,int beg,int mid,int end)
{   
    if(mid == beg && a[f(mid)]!= x)
        return -1;
   
        
    if(a[f(mid,max_index,n)]==x)
        return f(mid,max_index,n);
    
    if(a[f(mid,max_index,n)]>x)
    {
        end = mid-1;
        mid = (beg+end)/2;
        return bin_search(a,max_index,x,beg,mid,end);
    }
    
    beg = mid+1;
    mid = (beg+end)/2;
    return bin_search(a,max_index,x,beg,mid,end);
}   

int find_max_index(int a[],int beg,int mid,int end,int n)
{
    if(a[n-1]>a[0])
        return n-1;
        
    if(a[mid]>a[mid+1])
        return mid;
    
    if(a[mid] > a[beg] && a[mid] > a[end])
          return find_max_index(a,mid+1,(mid+1+end)/2,end,n)
    
    return find_max_index(a,beg,(beg+mid-1)/2,mid-1,n);          
}
        
