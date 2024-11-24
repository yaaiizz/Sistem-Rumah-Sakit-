#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Struct untuk menyimpan informasi Pasien
struct Pasien {
    int id;
    string nama;
    string alamat;
    string penyakit;
    string status;
};

// Struct untuk menyimpan informasi Dokter
struct Dokter {
    int id;
    string nama;
    string spesialisasi;
    string jadwal;
    string jam;
};

// Struct untuk menyimpan informasi Pembayaran
struct Pembayaran {
    int pasien_id, total_biaya;
    bool sudah_dibayar; // kalo udah bayar true
};

// Struct untuk menyimpan informasi Jadwal
struct Jadwal {
    int dokter_id;
    string waktu_hari;
    string waktu_jam;
    string pasien_nama;
};

// Fungsi untuk menampilkan menu utama
void tampilkanMenu() {
    cout << "============================================" << endl;
    cout << "    *** Sistem Rumah Sakit AMBATRON ***     " << endl;
    cout << "============================================" << endl;
    cout << "| 1. Manajemen Pasien                      |" << endl;
    cout << "| 2. Manajemen Dokter                      |" << endl;
    cout << "| 3. Pembayaran & Keuangan                 |" << endl;
    cout << "| 4. Jadwal Pemeriksaan                    |" << endl;
    cout << "| 5. Keluar                                |" << endl;
    cout << "============================================" << endl;
    cout << "Silakan pilih menu (1-5): ";
}

// Fungsi untuk menampilkan submenu Manajemen Pasien
void submenuPasien() {
    cout << "============================================" << endl;
    cout << "          *** Manajemen Pasien ***          " << endl;
    cout << "============================================" << endl;
    cout << "| 1. Tambah Pasien Baru                    |" << endl;
    cout << "| 2. Lihat Daftar Pasien                   |" << endl;
    cout << "| 3. Hapus Pasien                          |" << endl;
    cout << "| 4. Kembali ke Menu Utama                 |" << endl;
    cout << "============================================" << endl;
    cout << "Silakan pilih menu (1-4): ";
}

// Fungsi untuk menambahkan pasien baru
void tambahPasien(vector<Pasien>& pasienList) {
    Pasien pasienBaru;
    cout << "Masukkan ID Pasien (Masukan Angka) : ";
    cin >> pasienBaru.id;
    cin.ignore();
    cout << "Masukkan Nama Pasien: ";
    getline(cin, pasienBaru.nama);
    cout << "Masukkan Alamat Pasien: ";
    getline(cin, pasienBaru.alamat);
    cout << "Masukkan Penyakit Pasien: ";
    getline(cin, pasienBaru.penyakit);
    cout << "Status Rawat (Rawat Jalan / Rawat Inap): ";
    getline(cin, pasienBaru.status);

    pasienList.push_back(pasienBaru);
    cout << "Pasien berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan daftar pasien
void lihatDaftarPasien(const vector<Pasien>& pasienList) {
    cout << "======================================" << endl;
    cout << "          Daftar Pasien              " << endl;
    cout << "======================================" << endl;
    if (pasienList.empty()) {
        cout << "Tidak ada pasien yang terdaftar." << endl;
    } else {
        for (int i = 0; i < pasienList.size(); i++) {
            cout << "Data Pasien ke-" << i + 1 << endl;
            cout << "ID            : " << pasienList[i].id << endl;
            cout << "Nama          : " << pasienList[i].nama << endl;
            cout << "Penyakit      : " << pasienList[i].penyakit << endl;
            cout << "Status        : " << pasienList[i].status << endl;
            cout << endl;
        }
    }


    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();

    system("cls");
}

// Fungsi untuk menghapus pasien berdasarkan urutan data
void hapusPasien(vector<Pasien>& pasienList) {
    int h;
    char t;

    // Menampilkan daftar pasien
    for (int i = 0; i < pasienList.size(); i++) {
        cout << "Data Pasien ke-" << i + 1 << endl;
        cout << "ID            : " << pasienList[i].id << endl;
        cout << "Nama          : " << pasienList[i].nama << endl;
        cout << "Penyakit      : " << pasienList[i].penyakit << endl;
        cout << "Status        : " << pasienList[i].status << endl;
        cout << endl;
    }

    cout << "\nData Pasien Ke Berapa Yang Ingin Dihapus? (Masukkan Angka): ";
    cin >> h;

    if (h > 0 && h <= pasienList.size()) {
        pasienList.erase(pasienList.begin() + h - 1); // Menghapus data pasien
        cout << "\nData Pasien ke-" << h << " Telah Dihapus." << endl;
    } else {
        cout << "\nData tidak ditemukan!" << endl;
    }

    cout << "\nKembali ke menu utama? (y/n): ";
    cin >> t;

    if (t == 'n' || t == 'N') {
        return;
    }

    system("cls");
}

// Fungsi untuk menampilkan submenu Manajemen Dokter
void submenuDokter() {
    cout << "============================================" << endl;
    cout << "          *** Manajemen Dokter ***          " << endl;
    cout << "============================================" << endl;
    cout << "| 1. Tambah Dokter Baru                    |" << endl;
    cout << "| 2. Lihat Dokter                          |" << endl;
    cout << "| 3. Hapus Dokter                          |" << endl;
    cout << "| 4. Kembali ke Menu Utama                 |" << endl;
    cout << "============================================" << endl;
    cout << "Silakan pilih menu (1-4): ";
}

// Fungsi untuk menambahkan dokter baru
void tambahDokter(vector<Dokter>& dokterList) {
    Dokter dokterBaru;
    cout << "Masukkan ID Dokter (Masukan Angka): ";
    cin >> dokterBaru.id;
    cin.ignore();
    cout << "Masukkan Nama Dokter: ";
    getline(cin, dokterBaru.nama);
    cout << "Masukkan Spesialisasi: ";
    getline(cin, dokterBaru.spesialisasi);
    cout << "Masukkan Jadwal (Senin-Minggu): ";
    getline(cin, dokterBaru.jadwal);
    cout << "Masukkan Jam (Misal 08:00):";
    getline(cin, dokterBaru.jam);

    dokterList.push_back(dokterBaru);
    cout << "Dokter berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan daftar dokter
void lihatDaftarDokter(const vector<Dokter>& dokterList) {
    cout << "======================================" << endl;
    cout << "          Daftar Dokter              " << endl;
    cout << "======================================" << endl;
    if (dokterList.empty()) {
        cout << "Tidak ada dokter yang terdaftar." << endl;
    } else {
        for (int i = 0; i < dokterList.size(); i++) {
            cout << "Dokter ke-" << i + 1 << endl;
            cout << "ID            : " << dokterList[i].id << endl;
            cout << "Nama          : " << dokterList[i].nama << endl;
            cout << "Spesialisasi  : " << dokterList[i].spesialisasi << endl;
            cout << "Jadwal        : " << "Hari " << dokterList[i].jadwal << ", jam " << dokterList[i].jam << endl;
            cout << endl;
        }
    }

    // Tunggu input pengguna sebelum kembali ke menu
    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();

    system("cls");
}

void hapusDokter(vector<Dokter>& dokterList) {
    int h;
    char t;

    // Menampilkan daftar dokter
    for (int i = 0; i < dokterList.size(); i++) {
        cout << "Dokter ke-" << i + 1 << endl;
        cout << "ID            : " << dokterList[i].id << endl;
        cout << "Nama          : " << dokterList[i].nama << endl;
        cout << "Spesialisasi  : " << dokterList[i].spesialisasi << endl;
        cout << "Jadwal        : " << "Hari " << dokterList[i].jadwal << ", jam " << dokterList[i].jam << endl;
        cout << endl;
    }

    cout << "\nData Dokter Ke Berapa Yang Ingin Dihapus? (Masukkan Angka): ";
    cin >> h;

    if (h > 0 && h <= dokterList.size()) {
        dokterList.erase(dokterList.begin() + h - 1); // Menghapus data dokter
        cout << "\nData Dokter ke-" << h << " Telah Dihapus." << endl;
    } else {
        cout << "\nData tidak ditemukan!" << endl;
    }

    cout << "\nKembali ke menu utama? (y/n): ";
    cin >> t;

    if (t == 'n' || t == 'N') {
        return;
    }

    system("cls");
}

// Fungsi untuk menampilkan submenu Pembayaran & Keuangan
void submenuPembayaran() {
    cout << "============================================" << endl;
    cout << "       *** Pembayaran & Keuangan ***        " << endl;
    cout << "============================================" << endl;
    cout << "| 1. Tambah Pembayaran                     |" << endl;
    cout << "| 2. Lihat Pembayaran                      |" << endl;
    cout << "| 3. Hapus Pembayaran                      |" << endl;
    cout << "| 4. Proses Pembayaran                     |" << endl;
    cout << "| 5. Kembali ke Menu Utama                 |" << endl;
    cout << "============================================" << endl;
    cout << "Silakan pilih menu (1-5): ";
}

// Fungsi untuk menambahkan pembayaran baru
void tambahPembayaran(vector<Pembayaran>& pembayaranList) {
    Pembayaran pembayaranBaru;
    cout << "Masukkan ID Pasien: ";
    cin >> pembayaranBaru.pasien_id;
    cout << "Masukkan Total Biaya: ";
    cin >> pembayaranBaru.total_biaya;
    pembayaranBaru.sudah_dibayar = false;

    pembayaranList.push_back(pembayaranBaru);
    cout << "Pembayaran berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan pembayaran
void lihatPembayaran(const vector<Pembayaran>& pembayaranList) {
    cout << "======================================" << endl;
    cout << "          Daftar Pembayaran          " << endl;
    cout << "======================================" << endl;
    if (pembayaranList.empty()) {
        cout << "Tidak ada data pembayaran." << endl;
    } else {
        for (int i = 0; i < pembayaranList.size(); i++) {
            cout << "ID Pasien      : " << pembayaranList[i].pasien_id << endl;
            cout << "Total Biaya    : " << pembayaranList[i].total_biaya << endl;
            cout << "Status Pembayaran: " << (pembayaranList[i].sudah_dibayar ? "Sudah Dibayar" : "Belum Dibayar") << endl;
            cout << endl;
        }
    }

    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();

    system("cls");
}

void hapusPembayaran(vector<Pembayaran>& pembayaranList){
    int h;
    char t;

    // Menampilkan daftar pembayaran
    for (int i = 0; i < pembayaranList.size(); i++) {
        cout << "Data Pembayaran Pasien ke-" << i + 1 << endl;
        cout << "ID                 : " << pembayaranList[i].pasien_id << endl;
        cout << "Total Biaya        : " << pembayaranList[i].total_biaya << endl;
        cout << "Status Pembayaran  : " << (pembayaranList[i].sudah_dibayar ? "Sudah Dibayar" : "Belum Dibayar") << endl;
        cout << endl;
    }

    cout << "\nData Pembayaran Ke Berapa Yang Ingin Dihapus? (Masukkan Angka): ";
    cin >> h;

    if (h > 0 && h <= pembayaranList.size()) {
        pembayaranList.erase(pembayaranList.begin() + h - 1); // Menghapus data pembayaran
        cout << "\nData pembayaran ke-" << h << " Telah Dihapus." << endl;
    } else {
        cout << "\nData tidak ditemukan!" << endl;
    }

    cout << "\nKembali ke menu utama? (y/n): ";
    cin >> t;

    if (t == 'n' || t == 'N') {
        return;
    }

    system("cls");
}

void prosesPembayaran(vector<Pembayaran>& pembayaranList) {
    int idPasien;
    bool statusPembayaran = false;

    // Menampilkan daftar pembayaran
    cout << "=========================================" << endl;
    cout << "          Daftar Pembayaran Pasien       " << endl;
    cout << "=========================================" << endl;
    for (int i = 0; i < pembayaranList.size(); i++) {
        cout << "Pembayaran Pasien ke-" << i + 1 << endl;
        cout << "ID Pasien        : " << pembayaranList[i].pasien_id << endl;
        cout << "Total Biaya      : " << pembayaranList[i].total_biaya << endl;
        cout << "Status Pembayaran: " << (pembayaranList[i].sudah_dibayar ? "Sudah Dibayar" : "Belum Dibayar") << endl;
        cout << "-----------------------------------------" << endl;
    }

    cout << "Masukkan ID Pasien yang akan diproses pembayaran: ";
    cin >> idPasien;

    // Mencari dan memproses pembayaran berdasarkan ID Pasien
    for (int i = 0; i < pembayaranList.size(); i++) {
        if (pembayaranList[i].pasien_id == idPasien) {
            if (pembayaranList[i].sudah_dibayar) {
                cout << "Pembayaran Pasien ID " << idPasien << " sudah dibayar sebelumnya." << endl;
            } else {
                pembayaranList[i].sudah_dibayar = true; // Mengubah status pembayaran
                cout << "Pembayaran untuk Pasien ID " << idPasien << " telah berhasil diproses!" << endl;
            }
            statusPembayaran = true;
            break;
        }
    }

    if (!statusPembayaran) {
        cout << "Pembayaran " << idPasien << " tidak ditemukan dalam daftar pasien!" << endl;
    }

    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();

    system("cls");
}

// Fungsi untuk menampilkan submenu Jadwal Pemeriksaan
void submenuJadwal() {
    cout << "============================================" << endl;
    cout << "          *** Jadwal Pemeriksaan ***        " << endl;
    cout << "============================================" << endl;
    cout << "| 1. Tambah Jadwal                         |" << endl;
    cout << "| 2. Lihat Jadwal                          |" << endl;
    cout << "| 3. Hapus Jadwal                          |" << endl;
    cout << "| 4. Kembali ke Menu Utama                 |" << endl;
    cout << "============================================" << endl;
    cout << "Silakan pilih menu (1-4): ";
}

// Fungsi untuk menambahkan jadwal pemeriksaan
void tambahJadwal(vector<Jadwal>& jadwalList) {
    Jadwal jadwalBaru;
    cout << "Masukkan ID Dokter: ";
    cin >> jadwalBaru.dokter_id;
    cin.ignore();
    cout << "Masukkan Hari Pemeriksaan (Senin-Minggu): ";
    getline(cin, jadwalBaru.waktu_hari);
    cout << "Masukkan Jam Pemeriksaan (08:00): ";
    getline(cin, jadwalBaru.waktu_jam);
    cout << "Masukkan Nama Pasien: ";
    getline(cin, jadwalBaru.pasien_nama);

    jadwalList.push_back(jadwalBaru);
    cout << "Jadwal berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan daftar jadwal pemeriksaan
void lihatJadwal(const vector<Jadwal>& jadwalList) {
    cout << "======================================" << endl;
    cout << "          Daftar Jadwal              " << endl;
    cout << "======================================" << endl;
    if (jadwalList.empty()) {
        cout << "Tidak ada jadwal pemeriksaan." << endl;
    } else {
        for (int i = 0; i < jadwalList.size(); i++) {
            cout << "ID Dokter    : " << jadwalList[i].dokter_id << endl;
            cout << "Waktu        : " << "hari " << jadwalList[i].waktu_hari <<", jam " <<jadwalList[i].waktu_jam <<endl;
            cout << "Pasien       : " << jadwalList[i].pasien_nama << endl;
            cout << endl;
        }
    }

    // Tunggu input pengguna sebelum kembali ke menu
    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();

    system("cls");
}

void hapusJadwal(vector<Jadwal>& jadwalList){
    int h;
    char t;

    // Menampilkan daftar jadwal
    for (int i = 0; i < jadwalList.size(); i++) {
        cout << "Jadwal dokter ke-" << i + 1 << endl;
        cout << "ID Dokter      : " << jadwalList[i].dokter_id << endl;
        cout << "Waktu          : " << "hari " << jadwalList[i].waktu_hari <<", jam " <<jadwalList[i].waktu_jam <<endl;
        cout << "Pasien         : " << jadwalList[i].pasien_nama << endl;
        cout << endl;
    }

    cout << "\nJadwal Ke Berapa Yang Ingin Dihapus? (Masukkan Angka): ";
    cin >> h;

    if (h > 0 && h <= jadwalList.size()) {
        jadwalList.erase(jadwalList.begin() + h - 1);
        cout << "\nJadwal dokter ke-" << h << " Telah Dihapus." << endl;
    } else {
        cout << "\nJadwal tidak ditemukan!" << endl;
    }

    cout << "\nKembali ke menu utama? (y/n): ";
    cin >> t;

    if (t == 'n' || t == 'N') {
        return;
    }

    system("cls");
}

int main() {
    vector<Pasien> pasienList;
    vector<Dokter> dokterList;
    vector<Pembayaran> pembayaranList;
    vector<Jadwal> jadwalList;

    int pilihanMenu;

    while (true) {
        tampilkanMenu();
        cin >> pilihanMenu;
        cin.ignore();

        system("cls");

        switch (pilihanMenu) {
            case 1: {
                int pilihanPasien;
                do {
                    submenuPasien();
                    cin >> pilihanPasien;
                    cin.ignore();

                    system("cls");

                    switch (pilihanPasien) {
                        case 1:
                            tambahPasien(pasienList);
                            break;
                        case 2:
                            lihatDaftarPasien(pasienList);
                            break;
                        case 3:
                            hapusPasien(pasienList);
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                            break;
                    }
                } while (pilihanPasien != 4);
                break;
            }
            case 2: {
                int pilihanDokter;
                do {
                    submenuDokter();
                    cin >> pilihanDokter;
                    cin.ignore();

                    system("cls");

                    switch (pilihanDokter) {
                        case 1:
                            tambahDokter(dokterList);
                            break;
                        case 2:
                            lihatDaftarDokter(dokterList);
                            break;
                        case 3:
                            hapusDokter(dokterList);
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                            break;
                    }
                } while (pilihanDokter != 4);
                break;
            }
            case 3: {
                int pilihanPembayaran;
                do {
                    submenuPembayaran();
                    cin >> pilihanPembayaran;
                    cin.ignore();

                    system("cls");

                    switch (pilihanPembayaran) {
                        case 1:
                            tambahPembayaran(pembayaranList);
                            break;
                        case 2:
                            lihatPembayaran(pembayaranList);
                            break;
                        case 3:
                            hapusPembayaran(pembayaranList);
                            break;
                        case 4:
                            prosesPembayaran(pembayaranList);
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                            break;
                    }
                } while (pilihanPembayaran != 5);
                break;
            }
            case 4: {
                int pilihanJadwal;
                do {
                    submenuJadwal();
                    cin >> pilihanJadwal;
                    cin.ignore();

                    system("cls");

                    switch (pilihanJadwal) {
                        case 1:
                            tambahJadwal(jadwalList);
                            break;
                        case 2:
                            lihatJadwal(jadwalList);
                            break;
                        case 3:
                            hapusJadwal (jadwalList);
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                            break;
                    }
                } while (pilihanJadwal != 4);
                break;
            }
            case 5:
                cout << "********************************************" << endl;
                cout << "*     Rumah Sakit Ambatron Mengucapkan     *" << endl;
                cout << "*   Terima kasih telah menggunakan sistem! *" << endl;
                cout << "*                  ^_^                     *" << endl;
                cout << "*       Semoga harimu menyenangkan!        *" << endl;
                cout << "*                                          *" << endl;
                cout << "********************************************" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }

    return 0;
}
