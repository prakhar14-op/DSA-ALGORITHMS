#include<iostream>
using namespace std;

struct queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct queue *q,int key){
    if(q->rear==q->size-1){
        cout<<"queue is full";
    }
    else{
        q->rear++;
        q->Q[q->rear]=key;
    }
    cout<<'\n'; 
}

void dequeue(struct queue *q){
    int x=-1;
    if(q->front==q->rear){
        cout<<"queue is empty";
    }
    else{
        q->front++;
        x=q->Q[q->front];
    }
    cout<<'\n';
}

void display(struct queue q){
    for(int i =q.front+1;i<=q.rear;i++){
        cout<<q.Q[i]<<" ";
    }
    cout<<'\n';
}

int main(){
    struct queue q;
    cout<<"enter the size of queue ";
    cin>>q.size;
    q.Q=new int[q.size];
    q.front=-1;
    q.rear=-1;

    enqueue(&q,5);
    enqueue(&q,15);
    enqueue(&q,25);
    enqueue(&q,35);
    enqueue(&q,45);
    enqueue(&q,55);
    enqueue(&q,65);
    enqueue(&q,75);

    display(q);
    cout<<"applying dequeue";
    dequeue(&q);
    display(q);
}