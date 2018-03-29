#include <iostream>
#include <cstdlib>

class Node{
    public:
        Node* next;
        int data;
};

using namespace std;

class LinkedList{
    public:
        int length;
        Node* head;
        Node* tail;
        LinkedList();
        void add(int data);
        void print();
};

LinkedList::LinkedList(){
    this->length = 0;
    Node* tail = new Node();
    this->tail = tail;
    this->head = NULL;
}

void LinkedList::add(int data){
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    this->tail->next = node;
    this->tail = node;
    if(!this->head){
        this->head = node;
    }
    this->length++;
}

void LinkedList::print(){
    Node* current = this->head;
    int i = 1;
    while(current){
        std::cout << i << ": " << current->data <<std::endl;
        current = current->next;
        i++;
    }
}

int main(int argc, char const *argv[]){
    LinkedList* list = new LinkedList();
    int i = 0;
    while(i < 101){
        list->add(i);
        i++;
    }
    list->print();
    delete list;
    return 0;
}

