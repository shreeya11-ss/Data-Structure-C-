#include<stdio.h>
void main(){
    int high,low,mid,element,res=-1;
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Enter the element to be searched:");
    scanf("%d",&element);
    low=0;
    high=size-1;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==element){
            res=mid;
            break;
        }
        else if(element<arr[mid]){
            high=mid-1;
        }
        else if(element>arr[mid]){
            low=mid+1;
        }
    }
    if(res!=-1){
        printf("element found at %dth index",res);
    }
    else{
        printf("Element not found in the array");
    }
}