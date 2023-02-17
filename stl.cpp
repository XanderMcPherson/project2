// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void stl_sort(List &l, bool numeric) {
    Node *node = l.head;
    if (numeric) {
        vector<Node *> vec;
        while (node != NULL) {
            vec.push_back(node);
            node = node->next;
        }
        //I made a vector of nodes then pushbacked everynode through my list
        sort(vec.begin(), vec.end(), node_number_compare);
        l.head = vec[0];
        node = l.head;
        for (size_t i = 1; i < vec.size(); i++) {
            node->next = vec[i];
            node = node->next;
        }
        node->next = NULL;
        //I then ran sort on it then built my new list. Setting the last node to NULL so the list doesnt point somewhere random at the end
    }
    else {
        vector<Node *> vec;
        while (node != NULL) {
            vec.push_back(node);
            node = node->next;
        }
        sort(vec.begin(), vec.end(), node_string_compare);
        // Same exact thing here but string compare is called
        l.head = vec[0];
        node = l.head;
        for (size_t i = 1; i < vec.size(); i++) {
            node->next = vec[i];
            node = node->next;
        }
        node->next = NULL;

    }

}
