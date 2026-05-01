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
    }
};