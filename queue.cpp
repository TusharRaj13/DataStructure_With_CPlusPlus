#include<iostream>
using namespace std;
#define MAX 10
class QueueArray
{
    int arr[MAX];
    int rear, front;
    public:
    QueueArray()
    {
        front = rear = -1;
        for(int i=0; i<MAX; i++)
            arr[i]=0;
    }
    void Enqueue(int value)//insertion, push
    {
        if(rear == MAX - 1)
            cout << "Overflow" << endl;
        else
        {
            rear++;
            arr[rear] = value;
            if(front == -1)
                front = 0;
        }        
    }
    void Dequeue()//deletion, pop
    {
        if(front == -1)
            cout << "Underflow" << endl;
        else
        {
            cout << "Deleted " << arr[front] << endl;
            arr[front] = 0;
            if(front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front++;
            }            
        }        
    }
    void Display()
    {
        if(front == -1)
            cout << "Underflow" << endl;
        else
        {
            for(int i=front; i<=rear; i++)
                cout << arr[i] << endl;
        }        
    }
};
int main()
{
    QueueArray q;
    q.Enqueue(4);
    q.Enqueue(3);
    q.Enqueue(5);
    q.Display();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    return 1;
}