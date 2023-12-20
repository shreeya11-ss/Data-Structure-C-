#include<stdio.h>
int main(){
    int arr[]={77,89,23,45,67};
    int element,found=0,position;
    printf("Enter the element to be searched:");
    scanf("%d",&element);
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        if(arr[i]==element){
            found=found+1;
            position=i;
            break;
        }
    }
    if(found==1){
        printf("Element is found at %dth position :D",position);
    }
    else{
        printf("Element is not present :`(");
    }
    return 0;
}