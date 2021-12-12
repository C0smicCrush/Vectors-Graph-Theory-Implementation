/* 
 * File: data.h
 * Author: Aatmodhee Goswami
 * Purpose: Defines the  Node and Data data structures which are to be used in the LinkedList
 */

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id;
    int distance;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

#endif /* DATA_H */

