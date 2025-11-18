#include<iostream>
using namespace std;
struct stack{
    int size;
    int top;
    int *p;// since we will make stack in heap 
};

void display(struct stack st){

    cout << "Stack elements: ";
    for(int i = 0; i <= st.top; i++){
        cout << st.p[i] << " ";
    }
    cout << endl;
}

void push(struct stack *a,int x){
    if(a->top==a->size-1){
        cout<<"stack overflow";
    }
    else{
        a->top++;
        a->p[a->top]=x;
    }
}


int pop(struct stack *a){
    int x=-1;
    if(a->top==-1){
        cout<<"stack underflow";
    }
    else{
        x=a->p[a->top];
        a->top--;
    }
    return x;
}

int peek(struct stack *a,int pos){
    int x=-1;
    if(a->top-pos+1<0){
        cout<<"invalid position";
    }
    else{
        x=a->p[a->top-pos+1];
    }
    return x;
}



int main(){
    struct stack st;
    cout<<"enter the size";
    int size;
    cin>>size;
    st.p=new int[st.size];
    st.top=-1;
    push(&st,5);
    push(&st,15);
    push(&st,25);
    push(&st,35);
    push(&st,45);
    push(&st,55);
    push(&st,65);
    push(&st,75);
    push(&st,85);
    push(&st,95);

    display(st);
}