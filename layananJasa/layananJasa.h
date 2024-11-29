#include <iostream>

using namespace std;

struct layanan
{
    string jenis, jam;
    int jumlahPekerja;
    float diskonLayanan;
};

struct pekerja
{
    string nama, gender;
    int jumlahLayanan;
    float rating;
};

typedef layanan infotypeLayanan;
typedef pekerja infotypePekerja;
typedef struct elmLayanan *adrLayanan;
typedef struct elmPekerja *adrPekerja;
typedef struct elmRelation *adrRelation;

struct listLayanan
{
    adrLayanan first;
};

struct listPekerja
{
    adrPekerja first, last;
};

struct listRelation
{
    adrRelation first;
};

struct elmLayanan
{
    infotypeLayanan info;
    listRelation child;
    adrLayanan next;
};

struct elmPekerja
{
    infotypePekerja info;
    adrPekerja prev, next;
};

struct elmRelation
{
    adrPekerja infoChild;
    adrRelation nextChild;
};

void createListLayanan(listLayanan &l);
void createListPekerja(listPekerja &l);
void createListRelation(listRelation &l);
void createElmLayanan(adrLayanan &p, infotypeLayanan data);
void createElmPekerja(adrPekerja &p, infotypePekerja data);
void createElmRelation(adrRelation &p, adrPekerja dataPekerja);
void insertElmPekerja(listPekerja &l, adrPekerja p);
void deleteElmPekerja(listPekerja &l, string namaPekerja); // KURANG
adrPekerja findElmPekerja(listPekerja l, string namaPekerja);
void showAllListPekerja(listPekerja l);

void insertElmLayanan(listLayanan &l, adrLayanan p);
void deleteElmLayanan(listLayanan &l, string namaLayanan); // KURANG
adrLayanan findElmLayanan(listLayanan l, string namaLayanan);
void showAllElmLayanan(listLayanan l);

void insertElmRelation(listLayanan &lLayanan, listPekerja lPekerja, string namaLayanan, string namaPekerja);
void deleteElmRelation(listLayanan &lLayanan, listPekerja lPekerja, string namaLayanan, string namaPekerja); // Ini Procedure Delete Relation
void showChildOfParent(listLayanan lLayanan, string namaLayanan);                          // INI PROCEDURE
adrRelation findRelationFromPekerja(listLayanan lLayanan, string namaPekerja, string namaLayanan);
