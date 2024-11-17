#include<iostream>

using namespace std;
int n,i;
class queue{
   int F,R;
   int q[10];
  
   public:
   queue(){
    F=-1;
    R=-1;
   }
   void enqueue();
   void dequeue();
   void check();
   void display();
void peak();


};

void queue::enqueue(){
int ele;
    cout<<"enter the element "<<endl;
    cin>>ele;
    if(R==-1){
        R=0;
        F=0;
        q[R]=ele;
    }
    else if(R==n-1)  {
        cout<<"Queue is full";

    }  
    else{
        R++;
        q[R]=ele;

    }
}
void queue::dequeue(){
if(R==-1){
    cout<<"\nQueue is Empty";

}
else if(F==R){
cout<<"\ndelete element"<<q[F];
F=-1;
R=-1;
}
else{
cout<<"\ndeleted element is "<<q[F];
F++;

}
}
void queue::check(){
   if (R == -1&&F==-1) {
        cout << "\nQueue is empty." << endl;
    } else if (R == n - 1) {
        cout << "\nQueue is full." << endl;
    } else {
        cout << "\nQueue has elements." << endl;
    }

}



void queue::display(){
    if(R==-1 && F==-1){
        cout<<"\nqueu is empty";
    }
    else if(F==R){
    cout<<"\nelements are";
    cout<<q[i];
    }
    else{
    for(i=F;i<R;i++){
    
    cout<<q[i];
}
}
}
void queue::peak(){
if(R==-1){
    cout<<"\nQueue is empty";

}
else{
    cout<<"\nfront element"<<q[F];
}
}
int main(){
    queue q;
    int n,ch;
    cout<<"\nEnter the size elements";
    cin>>n;
    do{
    cout<<"\nmenu";
    cout<<"\n 1.Enqueue \n2.Dequeue \n3.check \n4.peak \n5.display"<<endl;
    cout<<"\nenter choice"<<endl;
    cin>>ch;
    switch(ch){
    case 1:
    
    q.enqueue();
    
     
    break;
    case 2:
      q.dequeue();
     
    break;
    case 3:
    q.check();
    break;
     case 4:
    q.peak();
    break;
    
    case 5:
    
    q.display();
    break;
    }
    }while(ch!=7);
return 0;
}