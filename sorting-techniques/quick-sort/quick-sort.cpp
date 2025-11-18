#include<iostream>
using namespace std;
 
int partition(int A[],int l , int h ){
    int pivort= A[l];
    int i=l,j=h+1;

    do{
        do{
            i++;
        }while(A[i]<=pivort);
        do{
            j--;
        }while(A[j]>pivort);

        if(i<j){
            swap(A[i],A[j]);
        }
    }while(i<j);
    swap(A[l],A[j]);
    return j;

}

void quick_sort(int A[], int l , int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        quick_sort(A,l,j-1);
        quick_sort(A,j+1,h);
    }

}


int main(){
    int A[]={1,15,20,55,66,2,11,3};
    int n=8;
    quick_sort(A,0,7);
    for(int i =0;i<8;i++){
        cout<<A[i]<<" "; 
    }

} 