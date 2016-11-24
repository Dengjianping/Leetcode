/*
Link: https://leetcode.com/problems/add-two-numbers/

You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template <class T>
struct LinkedList
{
    T value;
    LinkedList* next;
    LinkedList(T v)
    {
        value = v; next = NULL;
    }
};

template <class T>
class AddTwoNumbers
{
public:
    LinkedList<T>* addTwoLinkedList(LinkedList<T>* a, LinkedList<T>* b)
    {
        LinkedList<T>* head = new LinkedList<T>(a->value + b->value);
        LinkedList<T>* merged = head;
        
        LinkedList<T>* x = a->next; LinkedList<T>* y = b->next;
        while( x != NULL && y != NULL)
        {
            LinkedList<T>* list = new LinkedList<T>(x->value + y->value);
            //cout << merged->value << endl;
            merged->next = list;
            merged = list;
            x = x->next; y = y->next;
        }
        
        x = head;
        while (x != NULL)
        {
            if (x->value >= (T)10)
            {
                T t = x->value / (T)10;
                x->value = x->value % (T)10;
                x->next->value = x->next->value + t;
            }
            x = x->next;
        }
        
        return head;
    }
};

template <class T>
T randNumber(T range)
{
    return rand() % range;
}

template <class T>
void visitLinkedList(LinkedList<T>* x)
{
    if (x == NULL)return;
    cout << x->value << endl;
    visitLinkedList(x->next);
}

template <class T>
LinkedList<T>* createLinkedList(int count, T range)
{
    LinkedList<T>* head = new LinkedList<T>(randNumber(range));
    LinkedList<T>* x = head;
    for (size_t i = 0; i < count; i++)
    {
        LinkedList<T>* t = new LinkedList<T>(randNumber(range));
        x->next = t;
        x = t;
    }
    return head;
}

int main()
{
    const int N = 4;
    int range = 10;
    LinkedList<int>* head1 = createLinkedList(N, range);
    cout << "Linked list 1: " << endl;
    visitLinkedList(head1);
    
    LinkedList<int>* head2 = createLinkedList(N, range);
    cout << "Linked list 2: " << endl;
    visitLinkedList(head2);
    
    AddTwoNumbers<int> add;
    LinkedList<int>* result = add.addTwoLinkedList(head1, head2);
    cout << endl << "result: " << endl;
    visitLinkedList(result);
    
    return 0;
}
