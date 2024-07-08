#include <iostream>
#include <iomanip>
using namespace std;

class MasukUniversitas {
protected: // Contoh Enkapsulasi 
    float uangPendaftaran;
    float uangSemesterPertama;
    float uangBangunan;
    float totalBiaya;

public:
    MasukUniversitas() {
        uangPendaftaran = 0.0;
        uangSemesterPertama = 0.0;
        uangBangunan = 0.0;
        totalBiaya = 0.0;
    }

    virtual void namaJalurMasuk() {
        cout << "~ Jalur Masuk Universitas ~" << endl;
    }

    virtual void input() = 0; // Contoh Polymorphism (virtual)
    virtual void hitungTotalBiaya() = 0; 
    virtual void tampilkanTotalBiaya() = 0;

    void setUangPendaftaran(float nilai) {
        uangPendaftaran = nilai;
    }
    float getUangPendaftaran() {
        return uangPendaftaran;
    }

    void setUangSemesterPertama(float nilai) {
        uangSemesterPertama = nilai;
    }
    float getUangSemesterPertama() {
        return uangSemesterPertama;
    }

    void setUangBangunan(float nilai) {
        uangBangunan = nilai;
    }
    float getUangBangunan() {
        return uangBangunan; 
    }

    float getTotalBiaya() {
        return totalBiaya;
    }
};

class SNBT : public MasukUniversitas { // Contoh INHERITANCE
public:
    void namaJalurMasuk() override {
        cout << "~ Jalur Masuk SNBT ~" << endl;
    }

    void input() override {
        cout << "Masukkan Uang Pendaftaran: ";
        cin >> uangPendaftaran;
        cout << "Masukkan Uang Semester Pertama: ";
        cin >> uangSemesterPertama;
        cout << "Masukkan Uang Bangunan: ";
        cin >> uangBangunan; 
    }

    void hitungTotalBiaya() override {
        totalBiaya = uangPendaftaran + uangSemesterPertama + uangBangunan;
    }

    void tampilkanTotalBiaya() override {
        cout << "Total Biaya: Rp. " << fixed << setprecision(2) << totalBiaya << endl;
        if (totalBiaya < 20000000) {
            cout << "Kategori Biaya: Murah" << endl;
            cout << "Rekomendasi: Sangat Direkomendasikan" << endl;
        } else if (totalBiaya >= 20000000 && totalBiaya < 30000000) {
            cout << "Kategori Biaya: Sedang" << endl;
            cout << "Rekomendasi: Dipertimbangkan" << endl;
        } else {
            cout << "Kategori Biaya: Mahal" << endl;
            cout << "Rekomendasi: Tidak Direkomendasikan" << endl;
        }
    }
};

class SNBP : public MasukUniversitas {
public:
    void namaJalurMasuk() override {
        cout << "~ Jalur Masuk SNBP ~" << endl;
    }

    void input() override {
        cout << "Masukkan Uang Pendaftaran: ";
        cin >> uangPendaftaran;
        cout << "Masukkan Uang Semester Pertama: ";
        cin >> uangSemesterPertama;
    }

    void hitungTotalBiaya() override {
        totalBiaya = uangPendaftaran + uangSemesterPertama;
    }

    void tampilkanTotalBiaya() override {
        cout << "Total Biaya: Rp. " << fixed << setprecision(2) << totalBiaya << endl;
        if (totalBiaya < 15000000) {
            cout << "Kategori Biaya: Murah" << endl;
            cout << "Rekomendasi: Sangat Direkomendasikan" << endl;
        } else if (totalBiaya >= 15000000 && totalBiaya < 25000000) {
            cout << "Kategori Biaya: Sedang" << endl;
            cout << "Rekomendasi: Dipertimbangkan" << endl;
        } else {
            cout << "Kategori Biaya: Mahal" << endl;
            cout << "Rekomendasi: Tidak Direkomendasikan" << endl;
        }
    }
};

int main() {
    int pilihan;
    MasukUniversitas* jalur;

    do {
        cout << "Pilihan Jalur Masuk Universitas:" << endl;
        cout << "1. SNBT" << endl;
        cout << "2. SNBP" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            jalur = new SNBT();
            jalur->input();
            jalur->hitungTotalBiaya();
            jalur->tampilkanTotalBiaya(); 
            delete jalur;
            break;
        case 2:
            jalur = new SNBP();
            jalur->input();
            jalur->hitungTotalBiaya();
            jalur->tampilkanTotalBiaya();
            delete jalur;
            break;
        case 3:
            cout << "~ Terima kasih sudah memakai program ini ~" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }

        cout << endl; 
    } while (pilihan != 3);

    return 0;
}