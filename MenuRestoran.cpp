#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string namaMenu;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }
};