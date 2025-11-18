#include<iostream>
using namespace std;

struct myarray{
    int *p;
    int size;
};
// struct array *arr1;
// struct array *arr2;




void display(int *a, int size){
    for(int i =0;i<size;i++){
        cout<<a[i]<<" ";
    }
}
struct myarray *arr2 =new myarray;

void insert(struct myarray *a,int index,int key){
    //checking the index is valid or not 
    if(index<0 || index>a->size){
        cout<<"index is invalid";
        return;
    }
    arr2->size = a->size + 1;
    arr2->p = new int[arr2->size];
    
    for (int i = 0; i < index; i++){
        arr2 -> p[i] = a -> p[i];
    }
    arr2 -> p[index] = key;
    for (int i = index + 1; i< arr2 -> size; i++){
        arr2 -> p[i] = a -> p[i-1];
    }
    display(arr2->p,arr2->size);
    
} 


int main(){
    struct myarray *ptr=new myarray;
    cout<<"enter the size of the array ";
    cin>>ptr->size;

    // making a pointer in heap which will point to our array
    ptr->p=new int[ptr->size];

    // taking inputs
    for(int i=0;i<ptr->size;i++){
        cin>>ptr->p[i];
    }
    int key;
    cout<<"enter the value you want to insert";
    cin>>key;
    insert(ptr,2,key);

    // display(ptr->p,ptr->size);

}