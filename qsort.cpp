/*Xander McPherson, Nicholas St. Germain, Andrew Eblen, Peter Hoffman
 * project 2 qsort.cpp
 * This program uses the built in qsort method to sort a list of numbers numerically and by strings*/

#include "volsort.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//compare function for numeric
int compareint(const void *x_point, const void *y_point) {
    Node* x = *(Node **)x_point;
    Node* y = *(Node **)y_point;
    return (x->number - y->number);
}

//compare function for non numeric
int comparestr(const void *x_point, const void *y_point) {
    Node *x = *(Node **)x_point;
    Node *y = *(Node **)y_point;
    return strcmp(x->string.c_str(), y->string.c_str());
}

void qsort_sort(List &l, bool numeric) {
    vector<Node *> vec;
    Node* node;

    //stores list values into vector
    for(Node* node = l.head; node != NULL; node = node->next) {
        vec.push_back(node);
    }

    //if its numeric sort it rund qsort for numbers, if not it runs it for strings
    if(numeric) {
        qsort(vec.data(), vec.size(), sizeof(Node*), compareint);
    }
    else {
        qsort(vec.data(), vec.size(), sizeof(Node*), comparestr);
    }

    //sets all the array values back into the list
    l.head = vec[0];
    for(size_t i = 0; i < vec.size(); i++) {
        node = vec[i];
        node->next = vec[i+1];
    }
    //sets the last node's next pointer to null so it isn't pointed at something it doesnt need to
    node->next = NULL;
}
