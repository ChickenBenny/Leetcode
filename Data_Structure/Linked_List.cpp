#include <iostream>

using namespace std;

class LinkedList;

class ListNode{
public:
    ListNode():data(0), next(nullptr){};
    ListNode(int a):data(a), next(nullptr){};
    friend class LinkedList;
private:
    int data;
    ListNode *next;
};

class LinkedList{
public:
    LinkedList():first(nullptr){};
    void PrintList();
    void Push_front(int x);
    void Push_back(int x);
    void Delete(int x);
private:
    ListNode *first;
};

void LinkedList::PrintList(){
    if(first == nullptr){
        cout << "List is empty." << endl;
        return;
    }

    ListNode *current = first;
    while(current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::Push_front(int x){
    ListNode *newNode = new ListNode(x);
    newNode->next = first;
    first = newNode;
}

void LinkedList::Push_back(int x){
    ListNode *newNode = new ListNode(x);

    if(first == nullptr){
        first = newNode;
        return;
    }

    ListNode *current = first;
    while(current->next != nullptr)
        current = current->next;
    current->next = newNode;
}

void LinkedList::Delete(int x){
    ListNode *current = first,
             *previous = nullptr;
    while(current != nullptr && current->data != x){
        previous = current;
        current = current->next;
    }
    if(current == nullptr)
        cout << x << "is not in the list" << endl;
    else if(current == first){
        first = current->next;
        delete current;
        current = nullptr;
    }
    else{
        previous->next = current->next;
        delete current;
        current = nullptr;
    }
}

int main() {

    LinkedList list;     // 建立LinkedList的object
    list.PrintList();    // 目前list是空的
    list.Delete(4);      // list是空的, 沒有4
    list.Push_back(5);   // list: 5
    list.Push_back(3);   // list: 5 3
    list.Push_front(9);  // list: 9 5 3
    list.PrintList();    // 印出:  9 5 3
    list.Push_back(4);   // list: 9 5 3 4
    list.Delete(9);      // list: 5 3 4
    list.PrintList();    // 印出:  5 3 4
    list.Push_front(8);  // list: 8 5 3 4
    list.PrintList();    // 印出:  8 5 3 4
    list.PrintList();    // 印出:  4 3 5 8
    list.PrintList();    // 印出: List is empty.

    return 0;
}
