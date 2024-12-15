#include <iostream>

using namespace std;

typedef struct Akun InfotypeAkun;
typedef struct ElmAkun *AdrAkun;

struct Akun
{
  string username;
  string password;
  string role;
};

struct ElmAkun
{
  InfotypeAkun info;
  AdrAkun next;
};

struct ListAkun
{
  AdrAkun first;
};

void createListAkun(ListAkun &L);
void createElmAkun(AdrAkun &P, InfotypeAkun info);
void insertElmAkun(ListAkun &L, AdrAkun P);
AdrAkun findElmAkun(ListAkun L, string namaAkun);
