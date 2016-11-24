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

const int Digit = 10;

template <class T>
struct LinkedList
{
    T value;
    LinkedList* next;
    LinkedList(T v)
    {
        value = v; next = NULL:
    }
};

template <class T>
class AddTwoNumbers
{
public:
    LinkedList* addTwoLinkedList(LinkedList* a, LinkedList* b)
    {
        LinkedList* head = new LinkedList(a->value + b->value);
        LinkedList* merged = head;
        
        LinkedList* x = a->next, y = b->next;
        while( x != NULL && y != NULL)
        {
            LinkedList* list = new LinkedList((T)0);
            list->value = x->value + y->value;
            if (list->value >= 10)
            {
                list->value = list->value - digit;
            }
            merged->next = list;
        }
        return head;
    }
}