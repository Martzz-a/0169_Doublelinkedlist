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

    void addNode()
    {
        string addNamaMenu;
        cout << "\nMasukkan nama menu: ";
        cin >> addNamaMenu;

        // Step 1: Mengalokasi memori untuk new node
        Node *newNode = new Node();

        // Step 2: Mengisi data di data fields
        newNode->namaMenu = addNamaMenu;

        // Step 3: Menyisipkan diawal jika list kosong atau abjad lebih awal dari start
        if (START == NULL || addNamaMenu <= START->namaMenu)
        {
            if (START != NULL && addNamaMenu == START->namaMenu)
            {
                cout << "\nTidak boleh ada duplikasi nama menu" << endl;
                return;
            }

            newNode->next = NULL;
            newNode->prev = NULL;
            START = newNode;
            return;
        }

        // Memasukkan di tengah node
        // Step 8: Mengalokasikan posisi untuk node
        Node *current = START;
        while (current->next != NULL && current->next->namaMenu < addNamaMenu)
        {
            current = current->next;
        }

        if (current->next != NULL && addNamaMenu == current->next->namaMenu)
        {
            cout << "\nTidak boleh ada duplikasi nama menu" << endl;
            return;
        }

        // Step 9: Menyisipkan di antara current and current->next
        newNode->next = current->next; // Step 9a: newNode.next = current.next
        newNode->prev = current;       // Step 9b: newNode.prev = current

        // Menyisipkan last node
        if (current->next != NULL)
            current->next->prev = newNode; // Step 9c: current.next.prev = newNode

        current->next = newNode; // Step 9d: current.next = newNode
    }

    void delNode()
    {
        if (START == NULL)
        {
            cout << "\nList kosong" << endl;
            return;
        }

        cout << "\nMasukkan nama menu yang ingin dihapus: ";
        string delNamaMenu;
        cin >> delNamaMenu;
    }
};
