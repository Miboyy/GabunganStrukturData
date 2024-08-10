#include <iostream>

using namespace std;

// Struktur linked list yang baru
struct dataDokumen {
    string namaDokumen;
    string tanggalPembuatan;
    int ukuranDokumen;

    // pointer
    dataDokumen *prev;
    dataDokumen *next;
};

dataDokumen *head, *tail, *cur, *del, *newNode, *afterNode;

// fungsi membuat circular double Linked list
void createDataDokumen(string namaDokumen, string tanggalPembuatan, int ukuranDokumen) {
    head = new dataDokumen();
    head->namaDokumen = namaDokumen;
    head->tanggalPembuatan = tanggalPembuatan;
    head->ukuranDokumen = ukuranDokumen;
    head->prev = head;
    head->next = head;
    tail = head;
}

// add First
void addFirst(string namaDokumen, string tanggalPembuatan, int ukuranDokumen) {
    if (head == NULL) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else {
        newNode = new dataDokumen();
        newNode->namaDokumen = namaDokumen;
        newNode->tanggalPembuatan = tanggalPembuatan;
        newNode->ukuranDokumen = ukuranDokumen;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

// add Last
void addLast(string namaDokumen, string tanggalPembuatan, int ukuranDokumen) {
    if (head == NULL) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else {
        newNode = new dataDokumen();
        newNode->namaDokumen = namaDokumen;
        newNode->tanggalPembuatan = tanggalPembuatan;
        newNode->ukuranDokumen = ukuranDokumen;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }
}

// add Middle
void addMiddle(string namaDokumen, string tanggalPembuatan, int ukuranDokumen, int posisi) {
    if (head == NULL) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else {
        if (posisi == 1) {
            cout << "Posisi 1 bukan posisi tengah" << endl;
        } else if (posisi < 1) {
            cout << "Posisi diluar jangkauan" << endl;
        } else {
            newNode = new dataDokumen();
            newNode->namaDokumen = namaDokumen;
            newNode->tanggalPembuatan = tanggalPembuatan;
            newNode->ukuranDokumen = ukuranDokumen;

            // traversing
            cur = head;
            int nomor = 1;
            while (nomor < posisi - 1) {
                cur = cur->next;
                nomor++;
            }
            afterNode = cur->next;
            cur->next = newNode;
            afterNode->prev = newNode;
            newNode->prev = cur;
            newNode->next = afterNode;
        }
    }
}

// remove First
void removeFirst() {
    if (head == NULL) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else {
        del = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete del;
    }
}

// remove Last
void removeLast() {
    if (head == NULL) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else {
        del = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete del;
    }
}

// remove Middle
void removeMiddle(int posisi) {
    if (head == NULL) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else {
        if (posisi == 1) {
            cout << "Posisi 1 bukan posisi tengah" << endl;
        } else if (posisi < 1) {
            cout << "Posisi diluar jangkauan" << endl;
        } else {
            // traversing
            cur = head;
            int nomor = 1;
            while (nomor < posisi - 1) {
                cur = cur->next;
                nomor++;
            }
            del = cur->next;
            afterNode = del->next;
            cur->next = afterNode;
            afterNode->prev = cur;
            delete del;
        }
    }
}

// fungsi print
void printDataDokumen() {
    if (head == NULL) {
        cout << "Buat Linked List dahulu!!" << endl;
    } else {
        cout << "Data Dokumen : " << endl;
        cur = head;
        while (cur->next != head) {
            // print
            cout << "Nama Dokumen : " << cur->namaDokumen << endl;
            cout << "Tanggal Pembuatan : " << cur->tanggalPembuatan << endl;
            cout << "Ukuran Dokumen : " << cur->ukuranDokumen << " KB" << endl;
            cout << endl;

            // step
            cur = cur->next;
        }
        // print last node
        cout << "Nama Dokumen : " << cur->namaDokumen << endl;
        cout << "Tanggal Pembuatan : " << cur->tanggalPembuatan << endl;
        cout << "Ukuran Dokumen : " << cur->ukuranDokumen << " KB" << endl;
        cout << endl;
    }
}

int main() {
    createDataDokumen("Document1", "01-01-2024", 500);
    printDataDokumen();

    addFirst("Document2", "02-01-2024", 300);
    printDataDokumen();

    addLast("Document3", "03-01-2024", 700);
    printDataDokumen();

    addMiddle("Document4", "04-01-2024", 450, 2);
    printDataDokumen();

    removeMiddle(2);
    printDataDokumen();

    return 0;
}
