#include <iostream>
using namespace std;

//deklarasi class mahasiswa
class Mahasiswa {
    //membuat member class private
    private:
        const int id;
        string nama;
        float nilai;

    //membuat member class public
    public:
        //membuat member initialization list dari class mahasiswa
        Mahasiswa(int pId, string pNama, float pNilai) : nama(pNama), nilai(pNilai), id(pId) {

        };
        //membuat destructor dari class mahasiswa
        ~Mahasiswa() {
            cout << "ID : " << id << endl;
            cout << "Nama : " << nama << endl;
            cout << "Nilai : " << nilai << endl;
        }
};

int main()
{
    //deklarasi dan pemberian nilai untuk objek mhs
    Mahasiswa mhs(12, "Asroni", 90.5);

    return 0;
}