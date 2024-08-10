#include <iostream>
#include <list>
#include <vector>

class Graf {
    int jumlahSimpul;
    std::vector<std::list<int>> daftarAdj;

public:
    // Konstruktor
    Graf(int simpul);

    // Fungsi untuk menambahkan sisi ke dalam graf
    void tambahSisi(int sumber, int tujuan);

    // Fungsi untuk mencetak graf
    void cetakGraf();
};

// Konstruktor: inisialisasi graf dengan jumlah simpul yang diberikan
Graf::Graf(int simpul) {
    jumlahSimpul = simpul;
    daftarAdj.resize(simpul);
}

// Fungsi untuk menambahkan sisi ke dalam graf
void Graf::tambahSisi(int sumber, int tujuan) {
    daftarAdj[sumber].push_back(tujuan);
    daftarAdj[tujuan].push_back(sumber);  // Uncomment baris ini jika graf tidak berarah
}

// Fungsi untuk mencetak graf
void Graf::cetakGraf() {
    for (int i = 0; i < jumlahSimpul; ++i) {
        std::cout << "Simpul " << i << ":";
        for (int simpulTetangga : daftarAdj[i]) {
            std::cout << " -> " << simpulTetangga;
        }
        std::cout << std::endl;
    }
}

int main() {
    // Membuat graf dengan 5 simpul
    Graf graf(5);

    // Menambahkan sisi ke dalam graf
    graf.tambahSisi(0, 1);
    graf.tambahSisi(0, 4);
    graf.tambahSisi(1, 2);
    graf.tambahSisi(1, 3);
    graf.tambahSisi(1, 4);
    graf.tambahSisi(2, 3);
    graf.tambahSisi(3, 4);

    // Mencetak representasi daftar adjacency dari graf
    graf.cetakGraf();

    return 0;
}