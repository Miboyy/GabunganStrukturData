#include <iostream>

using namespace std;

// Mengubah struct dari Datauser menjadi DaftarDokumen
struct DaftarDokumen {
    string namaDokumen;
    string tanggalPembuatan;
    int ukuranDokumen;
    DaftarDokumen *prev; // sebelumnya
    DaftarDokumen *next; // selanjutnya
};

DaftarDokumen *sirah = NULL, *ekor = NULL, *cur = NULL, *newnode = NULL, *del = NULL;

void doublelinkedlist(string data[2], int ukuran) {
    sirah = new DaftarDokumen();
    sirah->namaDokumen = data[0];
    sirah->tanggalPembuatan = data[1];
    sirah->ukuranDokumen = ukuran;
    sirah->prev = NULL;
    sirah->next = NULL;
    ekor = sirah;
}

// Penambah awalan
void tambahAwal(string data[2], int ukuran) {
    if(sirah == NULL) {
        cout << "double-link list belum dibuat" << endl;
    } else {
        newnode = new DaftarDokumen();
        newnode->namaDokumen = data[0];
        newnode->tanggalPembuatan = data[1];
        newnode->ukuranDokumen = ukuran;
        newnode->prev = NULL;
        newnode->next = sirah;
        sirah->prev = newnode;
        sirah = newnode;
    }
}

// Penambahan node diakhir
void tambahakhir(string data[2], int ukuran) {
    if(sirah == NULL) {
        cout << "double-link list belum dibuat" << endl;
    } else {
        newnode = new DaftarDokumen();
        newnode->namaDokumen = data[0];
        newnode->tanggalPembuatan = data[1];
        newnode->ukuranDokumen = ukuran;
        newnode->prev = ekor;
        newnode->next = NULL;
        ekor->next = newnode;
        ekor = newnode;
    }
}

// Hapus awal
void Hapusawal() {
    if(sirah == NULL) {
        cout << "double-link list belum dibuat" << endl;
    } else {
        del = sirah;
        sirah = sirah->next;
        if (sirah != NULL) {
            sirah->prev = NULL;
        }
        delete del;
    }
}

// Hapus akhir
void Hapusakhir() {
    if(sirah == NULL) {
        cout << "double-link list belum dibuat" << endl;
    } else {
        del = ekor;
        ekor = ekor->prev;
        if (ekor != NULL) {
            ekor->next = NULL;
        }
        delete del;
    }
}

// Mencetak double linked list
void cetakdouble() {
    if(sirah == NULL) {
        cout << "double-link list belum dibuat" << endl;
    } else {
        cout << "Isi data: " << endl;
        cur = sirah;
        while (cur != NULL) {
            // Print
            cout << "Nama Dokumen : " << cur->namaDokumen << endl;
            cout << "Tanggal Pembuatan : " << cur->tanggalPembuatan << endl;
            cout << "Ukuran Dokumen : " << cur->ukuranDokumen << " KB" << endl;
            cout << endl;
            cur = cur->next;
        }
    }
}

int main() {
    string newData[2] = {"Dokumen Proyek", "01-01-2022"};
    int ukuran1 = 512;
    doublelinkedlist(newData, ukuran1);
    cetakdouble();

    string data2[2] = {"Laporan Keuangan", "05-02-2022"};
    int ukuran2 = 256;
    tambahAwal(data2, ukuran2);
    cetakdouble();

    string data3[2] = {"Presentasi", "10-03-2022"};
    int ukuran3 = 1024;
    tambahakhir(data3, ukuran3);
    cetakdouble();

    Hapusawal();
    cetakdouble();

    Hapusakhir();
    cetakdouble();

    return 0;
}
