#include <iostream>
#include <vector>
using namespace std;


class dokter;

class pasien {
public:

    string nama;
    vector<dokter*> daftar_dokter;


    pasien(string pNama) :nama(pNama) {
        cout << "Pasien \"" << nama << "\" ada\n";
    };

    ~pasien() {
        cout << "Pasien \"" << nama << "\" tidak ada\n";
    };

    //deklarasi prosedur tambahDokter() dan cetakDokter()
    void tambahDokter(dokter*);
    void cetakDokter();
};
//pembuatan class dokter
class dokter {
public:
    //deklarasi member variabel dari class dokter
    string nama;
    vector<pasien*> daftar_pasien;

    //pembuatan constructor dan destructor dari class dokter
    dokter(string pNama) :nama(pNama) {
        cout << "Dokter \"" << nama << "\" ada\n";
    }

    ~dokter() {
        cout << "Dokter \"" << nama << "\" tidak ada\n";
    }

    //deklarasi prosedur tambahPasien() dan cetakPasien()
    void tambahPasien(pasien*);
    void cetakPasien();
};
    }
}