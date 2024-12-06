#include <iostream>
#include "layananJasa.h"

using namespace std;

int main()
{
    ListLayanan LLayanan;
    ListPekerja LPekerja;
    createListLayanan(LLayanan);
    createListPekerja(LPekerja);

    for (size_t i = 0; i < 3; i++)
    {
        InfotypeLayanan ILayanan;
        AdrLayanan ALayanan;
        cout << "Masukkan data Layanan" << i + 1 << endl;
        cout << "Jenis Layanan: ";
        cin >> ILayanan.jenis;
        cout << "Jam Layanan: ";
        cin >> ILayanan.jam;
        cout << "Diskon Layanan: ";
        cin >> ILayanan.diskonLayanan;
        ILayanan.jumlahPekerja = 0;

        createElmLayanan(ALayanan, ILayanan);
        insertElmLayanan(LLayanan, ALayanan);
    }

    for (size_t i = 0; i < 4; i++)
    {
        InfotypePekerja IPekerja;
        AdrPekerja APekerja;

        cout << "Masukkan data Pekerja" << endl;
        cout << "Nama Pekerja: ";
        cin >> IPekerja.nama;
        cout << "Gender Pekerja: ";
        cin >> IPekerja.gender;
        cout << "Rating Pekerja: ";
        cin >> IPekerja.rating;
        IPekerja.jumlahLayanan = 0;

        createElmPekerja(APekerja, IPekerja);
        insertElmPekerja(LPekerja, APekerja);
    }
    AdrRelation ARelation;
    AdrLayanan ALayanan;

    AdrPekerja pekerjaYanto = findElmPekerja(LPekerja, "Yanto");

    createElmRelation(ARelation, pekerjaYanto);
    ALayanan = findElmLayanan(LLayanan, "Perbaikan_Rumah");
    insertElmRelation(ALayanan, ARelation);

    AdrPekerja pekerjaWinter = findElmPekerja(LPekerja, "Winter");

    createElmRelation(ARelation, pekerjaWinter);
    ALayanan = findElmLayanan(LLayanan, "Pembersihan_Rumah");
    insertElmRelation(ALayanan, ARelation);

    AdrPekerja pekerjaBrian = findElmPekerja(LPekerja, "Brian");

    createElmRelation(ARelation, pekerjaBrian);
    ALayanan = findElmLayanan(LLayanan, "Home_Automation");
    insertElmRelation(ALayanan, ARelation);

    AdrPekerja pekerjaKarina = findElmPekerja(LPekerja, "Karina");

    createElmRelation(ARelation, pekerjaKarina);
    ALayanan = findElmLayanan(LLayanan, "Pembersihan_Rumah");
    insertElmRelation(ALayanan, ARelation);

    InfotypePekerja tempPekerja = pekerjaYanto->info;
    tempPekerja.nama = "Budi";
    editElmPekerja(pekerjaYanto, tempPekerja);

    AdrLayanan perbaikanRumah = findElmLayanan(LLayanan, "Perbaikan_Rumah");
    AdrRelation budiPerbaikanRumah = findRelationByNamaPekerja(perbaikanRumah, "Budi");
    if (budiPerbaikanRumah != nullptr)
    {
        cout << "Budi bekerja di Perbaikan Rumah" << endl;
    }

    deleteElmPekerja(LLayanan, LPekerja, "Brian", pekerjaBrian);

    int jumlahLayanan = countAllLayanan(LLayanan);
    cout << "Jumlah Layanan: " << jumlahLayanan << endl;

    int jumlahPekerja = countAllPekerja(LPekerja);
    cout << "Jumlah Pekerja: " << jumlahPekerja << endl;

    int jumlahRelation = countAllRelation(LLayanan);
    cout << "Jumlah Relation: " << jumlahRelation << endl;

    int jumlahPekerjaPembersihanRumah = countAllRelationByNamaLayanan(LLayanan, "Pembersihan_Rumah");
    cout << "Jumlah Pekerja Pembersihan Rumah: " << jumlahPekerjaPembersihanRumah << endl;

    showAllListLayanan(LLayanan);
    showAllListPekerja(LPekerja);

    showAllRelationByNamaLayanan(LLayanan, "Pembersihan_Rumah");

    // Perbaikan rumah yanto
    // Pembersihan rumah winter
    // Home automation Brian
    // Pembersihan rumah Karina

    return 0;
}
