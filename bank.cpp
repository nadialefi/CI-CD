#include <iostream>
using namespace std;

string nama_pemilik[100] = {"Yusuf", "Messi"};
string profesi[100] = {"Mahasiswa", "Atlet Catur"};
int saldo[100] = {50000, 1000000};
int jumlah_akun = 2;

int pilih_menu(), cariAkun(string nama);
void tambah_akun(), lihat_rek(), nabung(), ambil_uang(), sortAkun();

int main (){
    cout << "Aplikasi Bank Sederhana" << endl;
    cout << "=======================" << endl;

    int lanjut = 1;
    do{
        int menu = pilih_menu();

        if (menu == 1){
            tambah_akun();
            lihat_rek();
        } else if (menu == 2){
            ambil_uang();
        } else if (menu == 3){
            nabung();
            nabung();
        } else if (menu == 4){
            lihat_rek();
        } else if (menu == 5){
            lanjut = 0;
        } else {
            cout << "Menu Inputan Salah !!! Coba Lagi..." << endl;
        }
    } while (lanjut == 1);
}

int pilih_menu(){
    int menu;
    cout << "Menu Aplikasi : " << endl;
    cout << "1. Buat Akun Baru" << endl;
    cout << "2. Ambil Uang" << endl;
    cout << "3. Nabung" << endl;
    cout << "4. Lihat Daftar Rekening" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih Menu [1/2/3/4/5] : ";
    cin >> menu;

    return menu;

}

void tambah_akun({
    cout << "Masukkan Nama : ";
    cin >> nama_pemilik[jumlah_akun];
    cout << "Masukkan Profesi : ";
    cin >> profesi[jumlah_akun];
    cout << "Saldo Awal : ";
    cin >> saldo[jumlah_akun];

    cout << "Sukses Menambah Akun" << endl;
    jumlah_akun++;

    sortAkun();
}

void lihat_rek(){
    for (int i = 0; i < jumlah_akun; i++){
        // Yusuf {Mahasiswa}, Saldo : 50000
        cout << (i+1) << ". " << nama_pemilik[i] << " (" << profesi[i] << "), Saldo : " << saldo[i] << endl;
    }
}

void ambil_uang(){
    int jumlah, urutan_akun = -1;
    string nama;

    lihat_rek();
    do{
        cout << "Masukkan Nama Pemilik Akun : ";
        cin >> nama;

        urutan_akun - cariAkun(nama);

        if(urutan_akun == -1){
            cout << "Akun tidak ditemukan!!! Coba Lagi..." << endl;
        } else {
            cout << "Masukkan jumlah yang diambil : ";
            cin >> jumlah;
            //=> saldo[urutan_akun] = saldo[urutan_akun] - jumlah
            saldo[urutan_akun] -= jumlah;
            cout << "Sukses mengambil uang, Saldo " << nama_pemilik[urutan_akun] << " saat ini : " << saldo[urutan_akun] << endl;
        }

    } while (urutan_akun == -1);

}

void nabung(){
    int jumlah, urutan_akun;

    lihat_rek();
    cout << "Pilih Urutan Rekening : ";
    cin >> urutan_akun;

    cout << "Maukkan jumlah yang ditabung : ";
    cin >> jumlah;

    saldo[(urutan_akun-1)] += jumlah;
    cout << "Sukses menabung, Saldo " << nama_pemilik[(urutan_akun-1)] << " saat ini : " << saldo[(urutan_akun-1)] << endl;
}

void sortAkun(){
    int i, j, lokasi_min, temp;
    string temp_s;

    for(i = 0; i < jumlah_akun; i++){
        lokasi_min =i;

        for(j = i+1; j < jumlah_akun; j++){
            if(nama_pemilik[j] < nama_pemilik[lokasi_min]){
                lokasi_min = j;
            }
        }

        temp_s = nama_pemilik[i];
        nama_pemilik[i] = nama_pemilik[lokasi_min];
        nama_pemilik[lokasi_min] = temp_s;

        temp_s = profesi[i];
        profesi[i] = profesi[lokasi_min];
        profesi[lokasi_min] = temp_s;

        temp_s = saldo[i];
        saldo[i] = saldo[lokasi_min];
        saldo[lokasi_min] = temp;
    }
}

int cariAkun(string nama){
    int lo = 0, hi = jumlah_akun - 1;
    int mid;

    while ( hi - lo > 1 ){
        mid = (hi + lo) / 2;
        if (nama_pemilik[mid] < nama){
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    if (nama_pemilik[lo] == nama){
        return lo;
    } else if (nama_pemilik[hi] == nama){
        return hi;
    } else {
        return -1;
    }
}