#include "layananJasa.h"

void createListLayanan(listLayanan &l){
    l.first = NULL;
}

void createListPekerja(listPekerja &l){
    l.first = NULL;
    l.last = NULL;
}

void createListRelation(listRelation &l){
    l.first = NULL;
}

void createElmLayanan(adrLayanan &p, infotypeLayanan data){
    p = new elmLayanan;

    p->info = data;
    p->next = NULL;
    createListRelation(p->child);

}

void createElmPekerja(adrPekerja &p, infotypePekerja data){
    p = new elmPekerja;

    p->info = data;
    p->next = NULL;
    p->prev = NULL;
}

void insertElmPekerja(listPekerja &l, adrPekerja p){
    if (l.first == NULL){
        l.first = p;
        l.last = p;
    } else {
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
    }
}

void deleteElmPekerja(listPekerja &l, string namaPekerja){
    adrPekerja del, beforeLoc;

    del = findElmPekerja(l, namaPekerja);


    if (l.first == NULL) {
        del = NULL; //dikarenakan tidak ada yang perlu di hapus serta ketika print data sudah di atur ketika list null akan memberikan keterangan list kosong
    } else if (del == NULL) {
        cout << "Tidak terdapat data yang tersedia pada list" << endl;
    } else if (l.first == l.last) {
        l.first = NULL;
        l.last = NULL;
    } else if (l.first == del) {
        l.first = del->next;
        del->next = NULL;
        l.first->prev = NULL;
    } else if (l.last == del) {
        l.last = del->prev;
        del->prev = NULL;
        l.last->next = NULL;
    } else {
        beforeLoc = del->prev;
        del->next->prev = beforeLoc;
        beforeLoc->next = del->next;
        del->next = NULL;
        del->prev = NULL;
    }

    if (del != NULL) {
        cout << del->info.nama << " berhasil di hapus" << endl;
        delete(del);
        del = NULL;
    }
}

adrPekerja findElmPekerja(listPekerja l, string namaPekerja){
    adrPekerja hasil, cur;

    hasil = NULL;
    cur = l.first;

    while (cur != NULL && hasil == NULL){
        if (cur->info.nama == namaPekerja) {
            hasil = cur;
        }
        cur = cur->next;
    }

    return hasil;
}

void showAllListPekerja(listPekerja l){
    adrPekerja cur;

    cur = l.first;

    if (l.first == NULL) {
        cout << "Tidak terdapat data pada list" << endl;
    } else {
        while (cur != NULL) {
            cout << cur->info.nama << ", rating " << cur->info.rating << ", gender " << cur->info.gender << ", jumlah pekerjaan " << cur->info.jumlahLayanan << endl;
            cur = cur->next;
        }
    }
}

void insertElmLayanan(listLayanan &l, adrLayanan p){
    if (l.first == NULL) {
        l.first = p;
    } else {
        adrLayanan cur;
        cur = l.first;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = p;
    }
}

void deleteElmLayanan(listLayanan &l, string namaLayanan) {
    adrLayanan del, beforeDel;
    adrRelation child;

    del = findElmLayanan(l, namaLayanan);

    if (l.first == NULL) {
        del = NULL;
    } else if (del == NULL){
        cout << "Tidak terdapat data yang tersedia pada list" << endl;
    } else if (l.first == del) {
        l.first = del->next;
        del->next = NULL;
    } else {
        beforeDel = l.first;
        while (beforeDel->next != del) {
            beforeDel = beforeDel->next;
        }
        beforeDel->next = del->next;
        del->next = NULL;
    }

    if (del != NULL) {
        cout << del->info.jenis << " berhasil dihapus" << endl;
        delete(del);
        del = NULL;
    }
}


adrLayanan findElmLayanan(listLayanan l, string namaLayanan){
    adrLayanan cur, hasil;

    cur = l.first;
    hasil = NULL;

    while (cur != NULL && hasil == NULL) {
        if (cur->info.jenis == namaLayanan) {
            hasil = cur;
        }
        cur = cur->next;
    }

    return hasil;
}

void showAllElmLayanan(listLayanan l){
    if (l.first == NULL) {
        cout << "Tidak terdapat data pada list" << endl;
    } else {
        adrLayanan cur;
        cur = l.first;
        while (cur != NULL) {
            cout << cur->info.jenis << ", diskon layanan " << cur->info.diskonLayanan << ", jam layanan " << cur->info.jam << ", jumlah pekerja " << cur->info.jumlahPekerja << endl;
            cur = cur->next;
        }
    }
}
