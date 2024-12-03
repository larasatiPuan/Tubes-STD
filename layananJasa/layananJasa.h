#include <iostream>

using namespace std;

typedef struct Layanan InfotypeLayanan;
typedef struct Pekerja InfotypePekerja;
typedef struct ElmLayanan *AdrLayanan;
typedef struct ElmPekerja *AdrPekerja;
typedef struct ElmRelation *AdrRelation;

struct Layanan
{
    string jenis;
    string jam;
    int jumlahPekerja;
    float diskonLayanan;
};

struct Pekerja
{
    string nama;
    string gender;
    int jumlahLayanan;
    float rating;
};

struct ElmLayanan
{
    InfotypeLayanan info;
    AdrRelation child;
    AdrLayanan next;
};

struct ElmPekerja
{
    InfotypePekerja info;
    AdrPekerja prev;
    AdrPekerja next;
};

struct ElmRelation
{
    AdrPekerja childPekerja;
    AdrRelation nextChild;
};

struct ListLayanan
{
    AdrLayanan first;
};

struct ListPekerja
{
    AdrPekerja first;
    AdrPekerja last;
};

void createListLayanan(ListLayanan &L);
void createListPekerja(ListPekerja &L);
void createElmLayanan(AdrLayanan &P, InfotypeLayanan info);
void createElmPekerja(AdrPekerja &P, InfotypePekerja info);
void createElmRelation(AdrRelation &P, AdrPekerja childPekerja);
void insertElmLayanan(ListLayanan &L, AdrLayanan P);
void insertElmPekerja(ListPekerja &L, AdrPekerja P);
void insertElmRelation(AdrLayanan &P, AdrRelation Q);
AdrLayanan findElmLayanan(ListLayanan L, string namaLayanan);
AdrPekerja findElmPekerja(ListPekerja L, string namaPekerja);
AdrRelation findRelationByNamaPekerja(AdrLayanan P, string namaPekerja);
AdrRelation findRelationByNamaLayanan(ListLayanan L, AdrPekerja P, string namaLayanan);
void deleteElmLayanan(ListLayanan &L, string namaLayanan, AdrLayanan &P);
void deleteElmPekerja(ListLayanan &LLayanan, ListPekerja &LPekerja, string namaPekerja, AdrPekerja &P);
void deleteElmRelation(ListLayanan &LLayanan, ListPekerja &LPekerja, string namaLayanan, string namaPekerja, AdrRelation &P);
void showAllListLayanan(ListLayanan L);
void showAllListPekerja(ListPekerja L);
// TODO: Implement the following functions
void showAllRelationByNamaPekerja(ListLayanan LLayanan, ListPekerja LPekerja, string namaPekerja);
void showAllRelationByNamaLayanan(ListLayanan LLayanan, ListPekerja LPekerja, string namaLayanan);
// TODO: End of implementation
