//stack with array
#include<iostream>
using namespace std;
#define MAXSTACK 10
class StackArray
{
    int arr[MAXSTACK];
    int top;
    public:
    StackArray(){
        top = -1;
        //Zero insertion should be avoided
        //Zero shows empty cell
        for(int i=0; i<MAXSTACK; i++)
            arr[i] = 0;
    }
    void pop()
    {
        if(top==-1)
            cout << "Underflow" << endl;
        else
        {
            cout << arr[top] << " deleted " << endl;
            arr[top]=0;
            top--;
        }        
    }
    void push(int value)
    {
        if(top==MAXSTACK-1)
            cout << "Stack overflow" << endl;
        else
        {
            top++;
            arr[top] = value;
        }        
    }
    void display()
    {
        if(top==-1)
            cout << "Underflow" << endl;
        else
        {
            for(int i=0;i<=top; i++)
                cout<<arr[i]<<endl;
        }
    }
};
int main()
{
    StackArray s;
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.pop();
    s.pop();
    s.display();
    return 0;
}