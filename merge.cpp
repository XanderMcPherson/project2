// merge.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
        if (numeric) {
                l.head = msort(l.head, true);
        }
        else {
                l.head = msort(l.head, false);
        }
}

Node *msort(Node *head, bool numeric) {
        if (head == NULL || head->next == NULL) {
                return head;                                    // checks if list is empty or if there is only one number/string.
        }
        Node *left = NULL, *right = NULL;
        split(head, left, right);       // list split
        left = msort(left, numeric); // recursive sort
        right = msort(right, numeric);
        return merge(left, right, numeric);
}

void split(Node *head, Node *&left, Node *&right) {
         if (head == NULL || head->next == NULL) {
                left = head;
                right = NULL;
        }
        else {

        Node *slow = head, *fast = head->next;
        while (fast != NULL) {
                fast = fast->next;                      // split code into sub "arrays"
                if (fast != NULL) {                     // takes in a node pointer, and two node pointer references
                        slow = slow->next;              // Uses these two pointers to traverse the list and split it in half
                        fast = fast->next;              // also has a case for if the list is NULL or has 1 node.
                }
          }
        left = head;
        right = slow->next;
        slow->next = NULL;
        }
}

Node *merge(Node *left, Node *right, bool numeric) {
    if (left == NULL) {                                                 // takes in two node pointers and bool value
        return right;                                                   // returns a sorted merged list
    }                                                                   // uses our compare functions in list.cpp
    if (right == NULL) {
        return left;
    }
    if (numeric) {                                                      // numeric merge cases
        if (node_number_compare(left, right)) {
            left->next = merge(left->next, right, numeric);
            return left;
        }
        else {
            right->next = merge(left, right->next, numeric);
            return right;
        }
    }
    else {
        if (node_string_compare(right, left) == false) {                // string merge cases
            left->next = merge(left->next, right, numeric);
            return left;
        }
        else {
            right->next = merge(left, right->next, numeric);
            return right;
        }
    }
}
