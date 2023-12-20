#include<stdio.h>
int main(){
    int arr[]={45,78,90,21,67,100,84};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("sorted array is:");
    for(int k=0;k<size;k++){
        printf("%d\n",arr[k]);
    }
}