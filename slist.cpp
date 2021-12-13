// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Andro Yono
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

#include<iostream>
#include"slist.h" 


using namespace std;

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist() { 
//     cout << "slist constructor: " << endl;
}

// positions always start at 1

int slist::search(el_t key) {
     if (Front == NULL) {
          return 0;
     }

     int count = 0;
     Node* P = Front;

     while (P != NULL) {
          count++;
	  if (P -> Elem == key) {
	       return count;
	  }
          P = P -> Next;
     }
     return 0;
}

el_t slist::search2(el_t key) {
  Node* P = Front;
  int count = 1;
  
  while (P != NULL)
  {
    if (key == P -> Elem)
    {
      return P -> Elem;
    }
    else
    {
      count++;
      P = P -> Next;
    }
  }

  el_t emptyEl_t;
  return emptyEl_t;
}

el_t slist::del(el_t key)
{
    Node* P = Front;
    int count = 1;

    while (P != NULL)
    {
        if (key == P->Elem)
        {
            // found, remove it
            el_t deleted = P->Elem;
            deleteIth(count,P->Elem);
            return deleted;
        }
        else
        {
            count++;
            P = P->Next;
        }
    }

    el_t emptyEl_t;
    return emptyEl_t;
}

void slist::replace(el_t element, int pos) {
     if (pos > Count || pos < 0) {
          throw OutOfRange(); //throw OutOfRange for bad pos
     }

     Node* P = Front;

     for (int i = 1; i < pos; i++) {
          P = P -> Next;
     }
     P -> Elem = element;
}

bool slist::operator==(const slist& OtherOne) {
     if (this -> Count != OtherOne.Count) {
          return false;
     }

    Node* P = Front;
    Node* Q = OtherOne.Front;

    while (P != NULL && Q != NULL) {
         if (P -> Elem != Q -> Elem) {
              return false;
         } else {
              P = P -> Next;
	      Q = Q -> Next;
         }
    }
    return true; 
}

