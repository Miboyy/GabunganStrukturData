#include <iostream>

using namespace std;

struct Dokumen
{
    string nama, tanggalPembuatan;
    int ukuran;

    Dokumen *next;
};

Dokumen *sirah, *bt, *ini, *nodeBaru, *hapuspokoke;

void ngisiLinkedlist(string nama, string tanggalPembuatan, int ukuran) {
    sirah = new Dokumen();
    sirah->nama = nama;
    sirah->tanggalPembuatan = tanggalPembuatan;
    sirah->ukuran = ukuran;
    sirah->next = NULL;
    bt = sirah;    
}

void tambahAwal(string nama, string tanggalPembuatan, int ukuran) {
    nodeBaru = new Dokumen();
    nodeBaru->nama = nama;
    nodeBaru->tanggalPembuatan = tanggalPembuatan;
    nodeBaru->ukuran = ukuran;
    nodeBaru->next = sirah;
    sirah = nodeBaru;
}

void tambahGuri(string nama, string tanggalPembuatan, int ukuran) {
    nodeBaru = new Dokumen();
    nodeBaru->nama = nama;
    nodeBaru->tanggalPembuatan = tanggalPembuatan;
    nodeBaru->ukuran = ukuran;
    nodeBaru->next = NULL;
    bt->next = nodeBaru;
    bt = nodeBaru;
}

void ubahAwal(string nama, string tanggalPembuatan, int ukuran){
    sirah->nama = nama;
    sirah->tanggalPembuatan = tanggalPembuatan;
    sirah->ukuran = ukuran;
}

void ubahLast(string nama, string tanggalPembuatan, int ukuran){
    bt->nama = nama;
    bt->tanggalPembuatan = tanggalPembuatan;
    bt->ukuran = ukuran;
}

void hapusAwal() {
    hapuspokoke = sirah;
    sirah = sirah->next;
    delete hapuspokoke;
}

void hapusLast() {
    hapuspokoke = bt;
    ini = sirah;
    while (ini->next != bt) {
        ini = ini->next;
    }
    bt = ini;
    bt->next = NULL;
    delete hapuspokoke;  
}

void cetakLinkedlist() {
    ini = sirah;
    while (ini != NULL) {
        cout << "Nama Dokumen : " << ini->nama << endl;
        cout << "Tanggal Pembuatan Dokumen : " << ini->tanggalPembuatan << endl;
        cout << "Ukuran Dokumen (KB) : " << ini->ukuran << endl;
        cout << endl;
        ini = ini->next;
    }
}

int main() {
    ngisiLinkedlist("Dokumen1", "2024-05-01", 150);
    tambahAwal("Dokumen2", "2024-04-20", 200);
    tambahGuri("Dokumen3", "2023-12-11", 175);
    // hapusAwal();
    // hapusLast();

    ubahAwal("DokumenAwal", "2024-05-28", 100);
    ubahLast("Dokumenzaenun", "2020-05-27", 50);
    cetakLinkedlist();

    return 0;
}
