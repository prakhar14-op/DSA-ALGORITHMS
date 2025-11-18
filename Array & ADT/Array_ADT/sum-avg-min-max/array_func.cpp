#include<iostream>
using namespace std;

int display( int A[],int n ){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}


int insert( int A[],int index,int element, int length ){
    for(int i=length;i>index;i--){
        A[i]=A[i-1];
    }
    A[index]=element;
    display(A,length);
}

int del(int A[],int index, int length){
    for(int i=index;i<length;i++){
        A[i]=A[i+1];
    }
    length--;
    display(A,length);
}

int max(int A[],int length){
    int max= A[0];
    for(int i =0; i<length;i++){
        if (A[i]>max){
            max=A[i];
        }
    }
    cout<<"maximum element is :"<<max;
}


int main(){
    int B[6]={1,2,4,5};
    display(B,4);
    cout<<endl;
    cout<<"inserting an elemnet "<<endl;
    insert(B,2,100,6);
    cout<<endl;
    cout<<"deleting an elemnet "<<endl;
    del(B,1,6);
    cout<<endl;
    max(B,6);
}