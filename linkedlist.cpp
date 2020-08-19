#include<iostream>
using namespace std;
class LinkedList
{
    struct Node{
        int data;
        Node *next;        
    } *head;

    public:
    LinkedList()
    {
        head = NULL;
    }
    /*Node* createNode(int value)
    {
        Node *t;
        t = new Node;
        t->data = value;
        t->next = NULL;
        return t;
    }*/
    Node* NewNode()
    {
        Node *t;
        t = new Node;
        cout << "Enter a value-";
        cin >> t->data;
        t->next = NULL;
        return t;
    }
    void createList(int n)
    {
        Node *temp, *last;
        for(int i=0;i<n;i++)
        {
            temp = NewNode();
            if(head == NULL)
                head = temp;
            else
            {
                last = head;
                while(last->next != NULL)
                {
                    last = last->next;
                }
                last->next = temp;
            }
        }
    }
    void Traverse()
    {
        Node *last;
        if(head == NULL)
            cout << "List is empty" << endl;
        else
        {
            last = head;
            while(last != NULL)
            {
                cout << last->data << endl;
                last = last->next;
            }
        }        
    }
    void InsertAtBegin()
    {
        Node *temp;
        temp=NewNode();
        if(head == NULL)
            head = temp;
        else
        {
            temp->next = head;
            head = temp;
        }        
    }
    void InsertAtEnd()
    {
        Node *temp;
        temp = NewNode();
        if(head == NULL)
            head = temp;
        else
        {
            Node *i;
            i = head;
            while(i->next != NULL)
            {
                i = i->next;
            }
            i->next = temp;
        }
        
    }
    void InsertAtPost(int pos)
    {
        Node *last, *temp;
        if(head == NULL)
            cout << "List empty";
        else
        {
            last = head;
            for(int i=1; i<pos; i++)
                last = last->next;
            temp = NewNode();
            temp->next = last->next;
            last->next = temp;            
        }        
    }
    void DeletionAtBegin()
    {
        if(head == NULL)
            cout << "List is empty" << endl;
        else
        {
            Node *t = head;
            head = t->next;
            cout << "Deleted node with value " << t->data << endl;
            delete t;
        }
    }
    void DeletionAtLast()
    {
        Node *t, *last;
        if(head == NULL)
            cout << "List is empty" << endl;
        else
        {
            t = head;
            while(t->next != NULL)
            {
                last = t;
                t = t->next;
            }
            last->next = NULL;
            cout << "Deleted node with value " << t->data << endl;
            delete t;
        }
    }
    void DeletionAtPostion(int pos)
    {
        Node *t, *last;
        if(head == NULL)
            cout << "List is empty" << endl;
        else if(false) // count check(count < pos)
        {
            cout << "Deletion not possible" << endl;
        }
        else
        {
            t = head;
            for(int i=1;i<pos;i++)
            {
                last = t;
                t = t->next;
            }
            last->next = t->next;
            cout << "Deleted item with value " << t->data << endl;
            delete t;
        }        
    }
    void search(int value)
    {
        Node *t;
        int flag = 0;
        if(head == NULL)
            cout << "List empty" << endl;
        else
        {
            t=head;
            while(t!=NULL)
            {
                if(t->data == value)
                {
                    cout << "Data found" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    t = t->next;
                }                
            }
            if(!flag)
                cout<<"Data not found"<<endl;
        }        
    }
    void reverse()
    {
        Node *t, *r, *q;
        t=head;
        r=NULL;
        while(t!=NULL)
        {
            q=r;
            r=t;
            t=t->next;
            r->next=q;
        }
        head = r;
    }
};
int main()
{
    LinkedList l;
    l.createList(4);
    l.Traverse();
    //l.InsertAtPost(2);
    //l.Traverse();
    l.reverse();
    l.Traverse();
    return 1;
}