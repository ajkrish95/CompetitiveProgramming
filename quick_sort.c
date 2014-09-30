#include<stdio.h>

void quicksort(int *a,int low,int high); 
int partition(int *a,int low,int high);

int main(){
 	int a[50],i,n;
 	scanf("%d",&n);
 	for (i=0;i<n;i++)
 	scanf ("%d",&a[i]);
 	quicksort(a,0,n-1);
 	for(i=0;i<n;i++)
 	printf("%d ",a[i]);
 }
 
 void quicksort(int *a,int low,int high){
 	int pivot;
 	if (high>low){
  		pivot=partition(a,low,high);
  		quicksort(a,low,pivot-1);
  		quicksort(a,pivot+1,high);
 	}
}
 
int partition(int *a,int low,int high){
	int left, right,temp;
 	int value;
 	int pivot;
 	left = low; 
 	pivot=left;
 	value = a[low]; 
 	right = high;
 	while (left<right){
   		while(a[left]<=value) // Keep moving left when item < pivot.
 			left++;
 		while(a[right]>value)  // Keep moving right when item > pivot. 
   			right--;
  		if(left<right){
   			temp=a[left];
 			a[left]=a[right];
			a[right]=temp;  
		}
 	}

	a[low]=a[right]; 
 	a[right]=value; // right is terminal position for the pivot.
 	return right;
}
 
