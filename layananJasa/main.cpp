#include "layananJasa.h"

int main()
{
    listPekerja lPekerja;
    infotypePekerja data;
    adrPekerja pPekerja;
    string tempNama, tempNama2;
    int nData;

    listLayanan lLayanan;
    infotypeLayanan dataLayanan;
    adrLayanan pLayanan;
    string namaLayanan;

    createListPekerja(lPekerja);
    createListLayanan(lLayanan);

    cout << "Jumlah n = ";
    cin >> nData;

    for (int i = 0; i < nData; i++) {
        cout << "Nama : ";
        cin >> data.nama;
        cout << "Jumlah layanan : ";
        cin >> data.jumlahLayanan;
        cout << "Rating : ";
        cin >> data.rating;
        cout << "Gender : ";
        cin >> data.gender;
        createElmPekerja(pPekerja, data);
        insertElmPekerja(lPekerja, pPekerja);
    }
    showAllListPekerja(lPekerja);

    pPekerja = findElmPekerja(lPekerja, "Winter");
    cout << pPekerja->info.nama << " " << pPekerja->info.gender << " " << pPekerja->info.rating << endl;

   /* for (int i = 0; i < 10; i++){
        cout << "Masukan nama data yang akan anda hapus :";
        cin >> tempNama;
        deleteElmPekerja(lPekerja, tempNama);
        cout << endl;
        showAllListPekerja(lPekerja);
        cout << endl;
    } */

    for (int i = 0; i < 3; i++) {
        cout << "Jenis : ";
        cin >> dataLayanan.jenis;
        cout << "Jam : ";
        cin >> dataLayanan.jam;
        cout << "Jumlah pekerja : ";
        cin >> dataLayanan.jumlahPekerja;
        cout << "Diskon : ";
        cin >> dataLayanan.diskonLayanan;
        createElmLayanan(pLayanan, dataLayanan);
        insertElmLayanan(lLayanan, pLayanan);
    }
    cout << endl;
    showAllElmLayanan(lLayanan);

    /* for (int i = 0; i < 10; i++){
        cout << "Masukan nama data yang akan anda hapus :";
        cin >> tempNama;
        deleteElmLayanan(lLayanan, tempNama);
        showAllElmLayanan(lLayanan);
        cout << endl << endl;
    } */

    cout << endl << endl << "PROSES RELATION" << endl << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Masukan nama layanan : ";
        cin >> tempNama;
        cout << "Masukan nama pekerja : ";
        cin >> tempNama2;
        insertElmRelation(lLayanan, lPekerja, tempNama, tempNama2);
    }

    cout << "Masukan nama child dari layanan yang akan di tampilkan : ";
    cin >> tempNama2;
    showChildOfParent(lLayanan, tempNama2);


    cout << findRelationFromPekerja(lLayanan, "Pembersihan_Rumah", "Winter")->infoChild->info.nama << endl;

    cout << endl << endl << "PROSES HAPUS RELATION" << endl << endl;
    for (int i = 0; i < 2; i++){
        cout << "Masukan nama layanan : ";
        cin >> tempNama;
        cout << "Masukan nama pekerja : ";
        cin >> tempNama2;
        deleteElmRelation(lLayanan, lPekerja, tempNama, tempNama2);
        showChildOfParent(lLayanan, tempNama);
    }
}
