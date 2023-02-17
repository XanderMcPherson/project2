#include "volsort.h"
#include <iostream>

using namespace std;

//compares int field of each node
bool node_number_compare( const Node *a, const Node *b ){

    if(a->number <= b->number){
        return(true);
    }else{
        return(false);
    }
}

//compares the string field of each node
bool node_string_compare( const Node *a, const Node *b ){

    int test = a->string.compare(b->string);

    if( test <= 0){
        return(true);
    }else{
        return(false);
    }
}


List::List() {
    head = NULL;
    size = 0;
}

List::~List() {
    Node *p = head;

    while (p != NULL) {
        Node *next = p->next;
        delete p;
        p = next;
    }

}

void List::push_front(const string &s) {
    Node *node = new Node();
    node->next = NULL;
    node->string = s;
    node->number = stoi(node->string);
    if (head == NULL) {
        head = node;
        size++;
    }
    else {
        Node *temp;
        temp = head;
        head = node;
        node->next = temp;
        size++;
    }

}
