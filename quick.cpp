// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes
using namespace std;

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    l.head = qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric) {
    Node *left = NULL;
    Node *right = NULL;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    partition(head, head, left, right, numeric);

    left = qsort(left, numeric);
    right = qsort(right, numeric);
    //the left and right are called recursivley to sort each list from the new pivot each time.

    head->next = NULL;
    head = concatenate(left, head);
    head = concatenate(head, right);

    return head;

}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    Node *leftTail = NULL;
    Node *rightTail = NULL;
    Node *start = pivot->next;
    while (start != NULL) {
        if (numeric) {
            if (node_number_compare(start, pivot)) {
                if (left == NULL) {
                    left = start;
                    leftTail = start;
                }
                else {
                    leftTail->next = start;
                    leftTail = leftTail->next;
                }
                start = start->next;
            }
            else {
                if (right == NULL) {
                    right = start;
                    rightTail = start;
                }
                else {
                    rightTail->next = start;
                    rightTail = rightTail->next;
                }
                start = start->next;
            }
        }
/* In the partition the main goal is to make two functioning lists. One with everything greater than the pivot and one with everything less.
I created two tails to keep up where the last node in the list is at so i can set it to NULL. the start node always starts at the node right
after the pivot. Then the if statement and node compare handles if it is greater than or less than the pivot then starts building the list */
        else {
            if (node_string_compare(start, pivot)) {
                if (left == NULL) {
                    left = start;
                    leftTail = start;
                }
                else {
                    leftTail->next = start;
                    leftTail = leftTail->next;
                }
                start = start->next;

            }
            else {
                if (right == NULL) {
                    right = start;
                    rightTail = start;
                }
                else {
                    rightTail->next = start;
                    rightTail = rightTail->next;
                }
                start = start->next;
            }
        }
      // same exact concept as above but calling string compare instead

    }
    if (leftTail != NULL) {
        leftTail->next = NULL;
    }
    if (rightTail != NULL) {
        rightTail->next = NULL;
    }

}

Node *concatenate(Node *left, Node *right) {
    if (left == NULL) {
        return right;
    }
    else {
        Node *head = left;
        while (left->next != NULL) {
            left = left->next;
        }
        left->next = right;
        return head;
    }
    /*this function passes throught the left and right node and connects them by finding
     the end of the left list and setting its next equal to the right head */

}
