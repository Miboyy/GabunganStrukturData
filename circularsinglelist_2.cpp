#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct Dokumen {
    string namaDokumen, tanggalPembuatan;
    int ukuranDokumen;

    Dokumen *next;
};

Dokumen *head, *tail, *newNode, *cur, *del;

// create Circular Single Linked List
void createCircularSingleLinkedList(string dataBaru[3], int ukuran) {
    head = new Dokumen();
    head->namaDokumen = dataBaru[0];
    head->tanggalPembuatan = dataBaru[1];
    head->ukuranDokumen = ukuran;
    tail = head;
    tail->next = head;
}

// add first
void addFirst(string data[3], int ukuran) {
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        newNode = new Dokumen();
        newNode->namaDokumen = data[0];
        newNode->tanggalPembuatan = data[1];
        newNode->ukuranDokumen = ukuran;
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

// add Last
void addLast(string data[3], int ukuran) {
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        newNode = new Dokumen();
        newNode->namaDokumen = data[0];
        newNode->tanggalPembuatan = data[1];
        newNode->ukuranDokumen = ukuran;
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

// add Middle
void addMiddle(string data[3], int ukuran, int posisi) {
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        if (posisi == 1) {
            cout << "Posisi satu bukan posisi tengah!!!" << endl;
        } else {
            newNode = new Dokumen();
            newNode->namaDokumen = data[0];
            newNode->tanggalPembuatan = data[1];
            newNode->ukuranDokumen = ukuran;

            // transversing
            int nomor = 1;
            cur = head;
            while (nomor < posisi - 1) {
                cur = cur->next;
                nomor++;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
}

// remove First
void removeFirst() {
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        del = head;
        head = head->next;
        tail->next = head;
        delete del;
    }
}

// remove Last
void removeLast() {
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        del = tail;
        cur = head;
        while (cur->next != tail) {
            cur = cur->next;
        }
        tail = cur;
        tail->next = head;
        delete del;
    }
}

// remove Middle
void removeMiddle(int posisi) {
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
       
        int nomor = 1;
        cur = head;
        while (nomor < posisi - 1) {
            cur = cur->next;
            nomor++;
        }
        del = cur->next;
        cur->next = del->next;
        delete del;
    }
}

void printCircular() {
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        cout << "Data Dokumen" << endl;
        cout << "______________________________________________________________" << endl;
        cout << "| Nama Dokumen\t| Tanggal Pembuatan\t| Ukuran Dokumen\t|" << endl;
        cout << "______________________________________________________________" << endl;
        cur = head;
        while (cur->next != head) {
            
            cout << "| " << cur->namaDokumen << "\t| " << cur->tanggalPembuatan << "\t\t| " << cur->ukuranDokumen << "\t|" << endl;
            cur = cur->next;
        }
        cout << "| " << cur->namaDokumen << "\t| " << cur->tanggalPembuatan << "\t\t| " << cur->ukuranDokumen << "\t|" << endl;
        cout << "______________________________________________________________" << endl;
    }
}

int main() {
    string dataBaru[3] = {"Dokumen1", "2024-01-01"};
    createCircularSingleLinkedList(dataBaru, 100);

    printCircular();

    string data[3] = {"Dokumen2", "2024-02-01"};
    addFirst(data, 200);

    printCircular();

    string data2[3] = {"Dokumen3", "2024-03-01"};
    addLast(data2, 300);

    printCircular();

    string data3[3] = {"Dokumen4", "2024-04-01"};
    addMiddle(data3, 400, 2);

    printCircular();

    //Batas========================
    removeMiddle(2);

    printCircular();

    removeFirst();

    printCircular();

    removeLast();

    printCircular();

    return 0;
}
