#include <iostream>
#include <queue>
#include <string>
#include <iomanip>

// Struct untuk merepresentasikan order tiket
struct PesananTiket {
    int urutan;
    bool diproses;
    std::string kodeTiket;
    std::string pengguna;
    int kursiDipesan;

    PesananTiket(int urt, bool prc, std::string kode, std::string png, int kursi)
        : urutan(urt), diproses(prc), kodeTiket(kode), pengguna(png), kursiDipesan(kursi) {}
};

// Fungsi untuk menambahkan order tiket ke dalam antrian
void tambahPesanan(std::queue<PesananTiket>& pesanan, int urutan, std::string kode, std::string pengguna, int kursi) {
    PesananTiket pesananBaru(urutan, false, kode, pengguna, kursi);
    pesanan.push(pesananBaru);
    std::cout << "Pesanan ditambahkan: " << kode << " oleh " << pengguna << " untuk kursi " << kursi << "\n";
}

// Fungsi untuk memproses order tiket dari antrian
void prosesPesanan(std::queue<PesananTiket>& pesanan) {
    if (pesanan.empty()) {
        std::cout << "Tidak ada pesanan untuk diproses.\n";
        return;
    }

    PesananTiket pesananDariQueue = pesanan.front();
    pesanan.pop();
    pesananDariQueue.diproses = true;
    std::cout << "Memproses Pesanan:\n";
    std::cout << "Urutan: " << pesananDariQueue.urutan << "\n";
    std::cout << "Kode Tiket: " << pesananDariQueue.kodeTiket << "\n";
    std::cout << "Pengguna: " << pesananDariQueue.pengguna << "\n";
    std::cout << "Kursi Dipesan: " << pesananDariQueue.kursiDipesan << "\n";
    std::cout << "Status: Diproses\n";
}

int main() {
    std::queue<PesananTiket> antrianPesananTiket;

    int pilihan;
    do {
        std::cout << "\n1. Tambah Pesanan\n2. Proses Pesanan\n3. Keluar\nPilih opsi: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int urutan;
                std::string kodeTiket;
                std::string pengguna;
                int kursiDipesan;

                std::cout << "Masukkan nomor urutan: ";
                std::cin >> urutan;
                std::cout << "Masukkan kode tiket: ";
                std::cin >> kodeTiket;
                std::cout << "Masukkan nama pengguna: ";
                std::cin >> pengguna;
                std::cout << "Masukkan kursi yang dipesan: ";
                std::cin >> kursiDipesan;

                tambahPesanan(antrianPesananTiket, urutan, kodeTiket, pengguna, kursiDipesan);
                break;
            }
            case 2:
                prosesPesanan(antrianPesananTiket);
                break;
            case 3:
                std::cout << "Keluar...\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 3);

    return 0;
}
