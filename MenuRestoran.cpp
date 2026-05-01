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

        Node *current = START;

        // Step 1: Menelusuri list untuk menemukan node tersebut
        while (current != NULL && current->namaMenu != delNamaMenu)
            current = current->next;

        if (current == NULL)
        {
            cout << "Menu tidak ditemukan" << endl;
            return;
        }
        else
        {
            cout << "Menu ditemukan" << endl;
            cout << "Nama menu: " << current->namaMenu << endl;
        }

        // Step 2: Jika node berada di awal
        if (current == START)
        {
            START = current->next; // Step 2a: START = START.next
            if (START != NULL)
                START->prev = NULL; // Step 2b: START.prev = NULL
        }
        else
        {
            // Step 3: Link previous node to next of current
            current->prev->next = current->next;

            // Step 4: Jika current bukan node terakhir
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
        }

        // Step 5: Menghapus node
        delete current;
        cout << "Nama menu " << delNamaMenu << " sudah terhapus" << endl;
    }

    void traverseNode()
    {
        if (START == NULL)
        {
            cout << "\nList kosong" << endl;
            return;
        }

        Node *currentNode = START;
        cout << "\nDaftar nama menu dari abjad terkecil:\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->namaMenu << " " << endl;
            currentNode = currentNode->next;
            i++;
        }
    }
};
