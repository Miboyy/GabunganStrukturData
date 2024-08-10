#include <iostream>
using namespace std;

// deklarasi struct baru untuk Daftar Dokumen dalam Folder
struct DataDokumen {
    string namaDokumen;
    string tanggalPembuatan;
    string ukuranDokumen; // diubah menjadi string
    DataDokumen *prev;
    DataDokumen *next;
};

DataDokumen *kepala, *ekor, *cur, *newNode, *del, *afterNode;

// Create Double Linked List
void buatdoublelinklist(string data[3]) {
    kepala = new DataDokumen();
    kepala->namaDokumen = data[0];
    kepala->tanggalPembuatan = data[1];
    kepala->ukuranDokumen = data[2];
    kepala->prev = NULL;
    kepala->next = NULL;
    ekor = kepala;
}

// Hitung Double Linked List
int hitungDoubleLinkedList() {
    if(kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
        return 0;
    } else {
        cur = kepala;
        int jumlah = 0;
        while(cur != NULL) {
            jumlah++;
            cur = cur->next;
        }
        return jumlah;
    }
}

// Add First
void tambahawal(string data[3]) {
    if(kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
    } else {
        newNode = new DataDokumen();
        newNode->namaDokumen = data[0];
        newNode->tanggalPembuatan = data[1];
        newNode->ukuranDokumen = data[2];
        newNode->prev = NULL;
        newNode->next = kepala;
        kepala->prev = newNode;
        kepala = newNode;
    }
}

// Add Last
void tambahakhir(string data[3]) {
    if(kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
    } else {
        newNode = new DataDokumen();
        newNode->namaDokumen = data[0];
        newNode->tanggalPembuatan = data[1];
        newNode->ukuranDokumen = data[2];
        newNode->prev = ekor;
        newNode->next = NULL;
        ekor->next = newNode;
        ekor = newNode;
    }
}

// Add Middle
void tambahtengah(string data[3], int posisi) {
    if(kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
    } else {
        if(posisi == 1) {
            cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
        } else if(posisi < 1 || posisi > hitungDoubleLinkedList()) {
            cout << "Posisi diluar jangkauan!" << endl;
        } else {
            newNode = new DataDokumen();
            newNode->namaDokumen = data[0];
            newNode->tanggalPembuatan = data[1];
            newNode->ukuranDokumen = data[2];

            // Traversing
            cur = kepala;
            int nomor = 1;
            while(nomor < posisi - 1) {
                cur = cur->next;
                nomor++;
            }

            afterNode = cur->next;
            newNode->prev = cur;
            newNode->next = afterNode;
            cur->next = newNode;
            afterNode->prev = newNode;
        }
    }
}

// Remove First
void hapusawal() {
    if(kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
    } else {
        del = kepala;
        kepala = kepala->next;
        if(kepala != NULL) {
            kepala->prev = NULL;
        } else {
            ekor = NULL;
        }
        delete del;
    }
}

// Remove Last
void hapusakhir() {
    if(kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
    } else {
        del = ekor;
        ekor = ekor->prev;
        if(ekor != NULL) {
            ekor->next = NULL;
        } else {
            kepala = NULL;
        }
        delete del;
    }
}

// Remove Middle
void hapustengah(int posisi) {
    if(kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
    } else {
        if(posisi == 1 || posisi == hitungDoubleLinkedList()) {
            cout << "Posisi bukan posisi tengah!!" << endl;
        } else if(posisi < 1 || posisi > hitungDoubleLinkedList()) {
            cout << "Posisi diluar jangkauan!!" << endl;
        } else {
            int nomor = 1;
            cur = kepala;
            while(nomor < posisi - 1) {
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

// Remove by Value
void hapusNodeDenganNilai(string namaDokumen) {
    if(kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
    } else {
        cur = kepala;
        int posisi = 1;
        bool ditemukan = false;

        // Traverse untuk mencari node dengan nilai yang diberikan
        while(cur != NULL) {
            if(cur->namaDokumen == namaDokumen) {
                ditemukan = true;
                break;
            }
            cur = cur->next;
            posisi++;
        }

        if(!ditemukan) {
            cout << "Dokumen dengan nama " << namaDokumen << " tidak ditemukan!!!" << endl;
            return;
        }

        // Hapus node sesuai posisi
        if(posisi == 1) {
            hapusawal();
        } else if(posisi == hitungDoubleLinkedList()) {
            hapusakhir();
        } else {
            hapustengah(posisi);
        }
    }
}

// Cetak Double Linked List
void cetakDoubleLinkedList() {
    if(kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
    } else {
        cout << "Jumlah Data : " << hitungDoubleLinkedList() << endl;
        cout << "Isi Data : " << endl;
        cur = kepala;
        while(cur != NULL) {
            // Cetak
            cout << "Nama Dokumen : " << cur->namaDokumen << endl;
            cout << "Tanggal Pembuatan : " << cur->tanggalPembuatan << endl;
            cout << "Ukuran Dokumen : " << cur->ukuranDokumen << " KB" << endl;
            cout << endl;
            cur = cur->next;
        }   
    }
}

int main() {
    string newData[3] = {"Dokumen1", "2024-05-28", "1024"};
    buatdoublelinklist(newData);
    // cetakDoubleLinkedList();

    string data2[3] = {"Dokumen2", "2024-05-29", "2048"};
    tambahawal(data2);
    // cetakDoubleLinkedList();

    string data3[3] = {"Dokumen3", "2024-05-30", "3072"};
    tambahakhir(data3);
    // cetakDoubleLinkedList();

    string data4[3] = {"Dokumen4", "2024-05-31", "4096"};
    tambahtengah(data4, 3);
    // cetakDoubleLinkedList();

    hapusNodeDenganNilai("Dokumen2");
    // cetakDoubleLinkedList();

    hapusNodeDenganNilai("Dokumen4");
    // cetakDoubleLinkedList();

    hapusNodeDenganNilai("Dokumen1");
    cetakDoubleLinkedList();

    return 0;
}
