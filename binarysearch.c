#include<stdio.h>
#include<stdlib.h>
int binarysearch(int *arr,int n,int key){
    int low=0,high=n-1,mid;
    while(low<=high){
         mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            low=mid+1;
        }
        else 
        high=mid-1;
    }
    return -1;
}
int main(){
    int n,key;
    printf("Enter the Size of Array : ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    if(!arr){
        printf("Memory Allocation Failed\n");
        return 1;
    }
    printf("Enter the Elements of Array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the Element to be Searched : ");
    scanf("%d",&key);
    int index=binarysearch(arr,n,key);
    if(index==-1){
        printf("Element Not Found\n");
    }
    else{
        printf("Element Found at Index : %d\n",index);
    }
    free(arr);
    return 0;
}