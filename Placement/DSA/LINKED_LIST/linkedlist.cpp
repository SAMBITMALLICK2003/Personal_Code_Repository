#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class ll
{
    node *head;

public:
    ll()
    {
        head = NULL;
    }

    void ins(int index, int d)
    {
        node *newnode = new node();
        newnode->data = d;

        if (index == 0)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        node *prev = head;
        for (int i = 0; i < index - 1 && prev->next != nullptr; i++)
        {
            prev = prev->next;
        }

        newnode->next = prev->next;
        prev->next = newnode;
    }
    void del(int del)
    {
        node *temp=head;
        if(head==NULL)
        {
            cout<<"List Empty"<<endl;
            return;
        }
        if(del==0)
        {
            head=head->next;
            temp->next = NULL;
            return;
        }
        node* prev = head;
        for(int i=0;i<del-1 && prev->next!=nullptr;i++)
        {
            prev=prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
        temp->next =NULL;
    }
    void rev()
    {
        node* current = head;
        node* prev=NULL;
        node* next=NULL;
        while(current!=NULL)
        {
            next = current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }
    void disp()
    {
        cout << "\n\n";
        node *nk = head;
        while (nk != NULL)
        {
            cout << nk->data << " ";
            nk = nk->next;
        }
        cout << "\n" << endl;
    }
    void search(int k)
    {
        int c=0;
        node* temp = head;
        if(head == NULL)
        {
            cout<<"List Empty"<<endl;
            return;
        }
        while(temp!=NULL)
        {
            if(temp->data==k)
                cout<<k<<" found at "<<c<<" index"<<endl;
            temp=temp->next;
            ++c;
        }
    }
    void count()
    {
        node* temp = head;
        if(head==NULL)
        {
            return;
        }
        int c=1;
        while(temp->next!=NULL)
        {
            temp = temp->next;
            ++c;
        }
        cout<<"No of nodes = "<<c<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter no of lists to create: "<<endl;
    cin>>n;
    ll *object = new ll[n];
    int choice1=0;
    while(choice1!=1)
    {
        int listno;
        cout<<"Enter list no to use ( enter -1 to go to prev menu ): "<<endl;
        cin>>listno;
        if(listno==-1)
        {
            choice1=-1;
            break;
        }
        int choice2=0;
        while(choice2!=-1)
        {
            int opno;
            cout<<"Choose operation to perform: 1-insert, 2-delete, 3-search, 4-reverse, 5-display, 6-show_count, -1 -prev_menu: "<<endl;
            cin>>opno;
            int i,d;
            switch(opno)
            {
                case 1:
                    cout<<"Enter Index to insert: "<<endl;
                    cin>>i;
                    cout<<"Enter data: "<<endl;
                    cin>>d;
                    object[listno].ins(i,d);
                    break;
                case 2:
                    cout<<"Enter Index to delete: "<<endl;
                    cin>>i;
                    object[listno].del(i);
                    break;
                case 3:
                    cout<<"Enter data to search: "<<endl;
                    cin>>d;
                    object[listno].search(d);
                    break;
                case 4:
                    object[listno].rev();
                    break;
                case 5:
                    object[listno].disp();
                    break;
                case 6:
                    object[listno].count();
                    break;
                case -1:
                    choice2=-1;
                    break;
            }
        }
    }
    return 0;
}
