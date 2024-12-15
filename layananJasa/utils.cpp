#include <iostream>
#include "utils.h"

void createListAkun(ListAkun &L)
{
  L.first = nullptr;
}

void createElmAkun(AdrAkun &P, InfotypeAkun info)
{
  P = new ElmAkun;
  P->info = info;
  P->next = nullptr;
}

void insertElmAkun(ListAkun &L, AdrAkun P)
{
  if (L.first == nullptr)
  {
    L.first = P;
  }
  else
  {
    AdrAkun cur = L.first;
    while (cur->next != nullptr)
    {
      cur = cur->next;
    }
    cur->next = P;
  }
}

AdrAkun findElmAkun(ListAkun L, string namaAkun)
{
  AdrAkun cur = L.first;
  while (cur != nullptr)
  {
    if (cur->info.username == namaAkun)
    {
      return cur;
    }
    cur = cur->next;
  }
  return nullptr;
}
