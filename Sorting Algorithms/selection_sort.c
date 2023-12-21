#include<stdio.h>
int main(){
    int arr[]={45,90,21,63,77,89};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size-1;i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    printf("printing sorted array:");
    for(int k=0;k<size;k++){
        printf("%d\n",arr[k]);
    }
}