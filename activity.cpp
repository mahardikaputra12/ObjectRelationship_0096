#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class Induk
class User {
public: // <-- Diubah jadi public biar Admin bisa akses variabel nama milik Member
    // member variable static
    static int globalId;
    
    // member variable ini otomatis dimiliki juga oleh Admin dan Member
    int id;
    string nama;
    string email;

    // member function untuk generateId
    int generateId() {
        globalId++;
        return globalId;
    }

    // constructor
    User(string pNama, string pEmail) : nama(pNama), email(pEmail) {
        id = generateId();
    }
};

// Inisialisasi static variable globalId di luar class
int User::globalId = 0;

// Class Turunan 1: Member
class Member : public User {
public:
    // id, nama, dan email SUDAH diwariskan dari User, jadi nggak perlu ditulis ulang di sini.
    // Tinggal nambahin member variable status khusus untuk Member.
    bool status; 

    // constructor
    Member(string pNama, string pEmail) : User(pNama, pEmail) {
        status = true; // Default aktif saat dibuat
    }

    // member function
    void showProfile() {
        cout << "ID Member : " << id << endl;
        cout << "Nama      : " << nama << endl;
        cout << "Email     : " << email << endl;
        cout << "Status    : " << (status ? "Aktif" : "Non-Aktif") << endl << endl;
    }
};

// Class Turunan 2: Admin
class Admin : public User {
public:
    // constructor
    Admin(string pNama, string pEmail) : User(pNama, pEmail) {}

    // member function menampilkan semua member
    void showAllMember(vector<Member*> daftarMember) {
        cout << "=== DAFTAR SEMUA MEMBER ===" << endl;
        for (auto& m : daftarMember) {
            m->showProfile();
        }
    }

    // member function mengubah status aktif/non-aktif member
    void toggleActivationMember(Member* pMember) {
        pMember->status = !pMember->status; // Balik nilai status
        cout << ">> Info: Status member '" << pMember->nama << "' berhasil diubah!" << endl << endl;
    }
};

int main() {
    // 1. Buat beberapa objek Member
    Member* mhs1 = new Member("Dipong", "dipong@umy.ac.id");
    Member* mhs2 = new Member("Budi", "budi@umy.ac.id");

    // 2. Masukkan ke dalam vector untuk dikelola Admin
    vector<Member*> listMember;
    listMember.push_back(mhs1);
    listMember.push_back(mhs2);

    // 3. Buat objek Admin
    Admin* adminIT = new Admin("Super Admin", "admin@domain.com");

    // 4. Admin melihat semua member (kondisi awal)
    adminIT->showAllMember(listMember);

    // 5. Admin menonaktifkan akun Budi
    adminIT->toggleActivationMember(mhs2);

    // 6. Admin melihat perubahan
    adminIT->showAllMember(listMember);

    // Hapus memori
    delete mhs1;
    delete mhs2;
    delete adminIT;

    return 0;
}