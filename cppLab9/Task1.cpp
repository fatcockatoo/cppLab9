#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int x;
    Node* Next;
};
class List
{
    Node* Head, * Tail; 
public:
    List() :Head(NULL), Tail(NULL) {}; 
    ~List(); 
    void Push(int x); 
    void Peek();
    void Pop();
    friend ostream& operator << (ostream& stream, const List& a); 
};
List::~List() 
{
    Node* temp = Head; 
    while (temp != 0) 
    {
        temp = Head->Next; 
        delete Head;  
        Head = temp; 
    }
}
void List::Push(int x)
{
    Node* temp = new Node;
    temp->x = x;
    temp->Next = NULL; 

    if (Head != NULL)
    {
        Tail->Next = temp; 
        Tail = temp;
    }
    else Head = Tail = temp; 
}
ostream& operator << (ostream& stream, const List& a)
{
    Node* temp = a.Head;
    while (temp != NULL) 
    {
        stream << temp->x << "";
        temp = temp->Next; 
    }
    return stream << endl;
}
void List::Peek()
{
    cout << Head->x;
}
void List::Pop()
{
    Head = Head->Next;
}
void main()
{
    List lst;
    int size, count;
    cout << "Size = ";
    cin >> size;
    for (int i = 1; i <= size; i++)
    {
        cout << "Count " << i << "/" << size << " = ";
        cin >> count;
        lst.Push(count);
    }
    cout << lst;
    lst.Peek();
    lst.Pop();
    cout << endl;
    cout << lst;
}

