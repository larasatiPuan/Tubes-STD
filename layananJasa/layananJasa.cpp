#include <iostream>
#include "layananJasa.h"

void createListLayanan(ListLayanan &L)
{
    L.first = nullptr;
}

void createListPekerja(ListPekerja &L)
{
    L.first = nullptr;
    L.last = nullptr;
}

void createElmLayanan(AdrLayanan &P, InfotypeLayanan info)
{
    P = new ElmLayanan;
    P->info = info;
    P->child = nullptr;
    P->next = nullptr;
}

void createElmPekerja(AdrPekerja &P, InfotypePekerja info)
{
    P = new ElmPekerja;
    P->info = info;
    P->next = nullptr;
    P->prev = nullptr;
}

void createElmRelation(AdrRelation &P, AdrPekerja childPekerja)
{
    P = new ElmRelation;
    P->childPekerja = childPekerja;
    P->nextChild = nullptr;
}

void insertElmLayanan(ListLayanan &L, AdrLayanan P)
{
    if (L.first == nullptr)
    {
        L.first = P;
    }
    else
    {
        AdrLayanan cur = L.first;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = P;
    }
}

void insertElmPekerja(ListPekerja &L, AdrPekerja P)
{
    if (L.first == nullptr)
    {
        L.first = P;
        L.last = P;
    }
    else
    {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertElmRelation(AdrLayanan &P, AdrRelation Q)
{
    if (P->child == nullptr)
    {
        P->child = Q;
    }
    else
    {
        AdrRelation cur = P->child;
        while (cur->nextChild != nullptr)
        {
            cur = cur->nextChild;
        }
        cur->nextChild = Q;
    }
    P->info.jumlahPekerja++;
    Q->childPekerja->info.jumlahLayanan++;
}

AdrLayanan findElmLayanan(ListLayanan L, string namaLayanan)
{
    AdrLayanan cur = L.first;
    while (cur != nullptr)
    {
        if (cur->info.jenis == namaLayanan)
        {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

AdrPekerja findElmPekerja(ListPekerja L, string namaPekerja)
{
    AdrPekerja cur = L.first;
    while (cur != nullptr)
    {
        if (cur->info.nama == namaPekerja)
        {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

AdrRelation findRelationByNamaPekerja(AdrLayanan P, string namaPekerja)
{
    AdrRelation cur = P->child;
    while (cur != nullptr)
    {
        if (cur->childPekerja->info.nama == namaPekerja)
        {
            return cur;
        }
        cur = cur->nextChild;
    }
    return nullptr;
}

AdrRelation findRelationByNamaLayanan(ListLayanan L, AdrPekerja P, string namaLayanan)
{
    AdrLayanan layanan = findElmLayanan(L, namaLayanan);
    if (layanan == nullptr)
    {
        return nullptr;
    }
    AdrRelation cur = layanan->child;
    while (cur != nullptr)
    {
        if (cur->childPekerja == P)
        {
            return cur;
        }
        cur = cur->nextChild;
    }
    return nullptr;
}

void deleteElmLayanan(ListLayanan &L, string namaLayanan, AdrLayanan &P)
{
    P = findElmLayanan(L, namaLayanan);
    if (P == nullptr)
    {
        return;
    }

    AdrRelation curRelation = P->child;
    while (curRelation != nullptr)
    {
        AdrRelation tempRelation = curRelation;
        curRelation = curRelation->nextChild;
        tempRelation->childPekerja->info.jumlahLayanan--;
        delete tempRelation;
    }

    if (L.first == P)
    {
        L.first = P->next;
    }
    else
    {
        AdrLayanan prev = L.first;
        while (prev->next != P)
        {
            prev = prev->next;
        }
        prev->next = P->next;
    }

    delete P;
}

void deleteElmPekerja(ListLayanan &LLayanan, ListPekerja &LPekerja, string namaPekerja, AdrPekerja &P)
{
    P = findElmPekerja(LPekerja, namaPekerja);
    if (P == nullptr)
    {
        return;
    }

    AdrLayanan layanan = LLayanan.first;
    while (layanan != nullptr)
    {
        AdrRelation prevRel = nullptr;
        AdrRelation currRel = layanan->child;
        while (currRel != nullptr)
        {
            if (currRel->childPekerja == P)
            {
                if (prevRel == nullptr)
                {
                    layanan->child = currRel->nextChild;
                }
                else
                {
                    prevRel->nextChild = currRel->nextChild;
                }
                layanan->info.jumlahPekerja--;
                AdrRelation tempRel = currRel;
                currRel = nullptr;
                delete tempRel;
            }
            else
            {
                prevRel = currRel;
                currRel = currRel->nextChild;
            }
        }
        layanan = layanan->next;
    }

    if (LPekerja.first == LPekerja.last)
    {
        LPekerja.first = nullptr;
        LPekerja.last = nullptr;
    }
    else if (P == LPekerja.first)
    {
        LPekerja.first = P->next;
        LPekerja.first->prev = nullptr;
    }
    else if (P == LPekerja.last)
    {
        LPekerja.last = P->prev;
        LPekerja.last->next = nullptr;
    }
    else
    {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }

    delete P;
}

void deleteElmRelation(ListLayanan &LLayanan, ListPekerja &LPekerja, string namaLayanan, string namaPekerja, AdrRelation &P)
{
    AdrLayanan layanan = findElmLayanan(LLayanan, namaLayanan);
    AdrPekerja pekerja = findElmPekerja(LPekerja, namaPekerja);
    if (layanan == nullptr || pekerja == nullptr)
    {
        P = nullptr;
        return;
    }
    AdrRelation prev = nullptr;
    AdrRelation cur = layanan->child;
    while (cur != nullptr)
    {
        if (cur->childPekerja == pekerja)
        {
            if (prev == nullptr)
            {
                layanan->child = cur->nextChild;
            }
            else
            {
                prev->nextChild = cur->nextChild;
            }
            cur->nextChild = nullptr;
            layanan->info.jumlahPekerja--;
            pekerja->info.jumlahLayanan--;
            P = cur;
            delete P;
            return;
        }
        prev = cur;
        cur = cur->nextChild;
    }
}

void showAllListLayanan(ListLayanan L)
{
    AdrLayanan cur = L.first;
    while (cur != nullptr)
    {
        cout << "Layanan: " << cur->info.jenis << endl;
        cout << "Jam: " << cur->info.jam << endl;
        cout << "Jumlah Pekerja: " << cur->info.jumlahPekerja << endl;
        cout << "Diskon Layanan: " << cur->info.diskonLayanan << endl;
        cout << endl;
        cur = cur->next;
    }
}

void showAllListPekerja(ListPekerja L)
{
    AdrPekerja cur = L.first;
    while (cur != nullptr)
    {
        cout << "Nama: " << cur->info.nama << endl;
        cout << "Gender: " << cur->info.gender << endl;
        cout << "Jumlah Layanan: " << cur->info.jumlahLayanan << endl;
        cout << "Rating: " << cur->info.rating << endl;
        cout << endl;
        cur = cur->next;
    }
}
