// CS311 Yoshii - Hash Table header DO NOT CHANGE!!! 
// ------------------------------------------------

#include "slist.h"

const int TSIZE = 29;  // 29 slots ; a prime number.
// It is the smallest prime not less than the number of letters (26).

class htable {
 private:
 slist table[TSIZE]; // each node of slist is el_t as defined in elem.h
 int hash(int);  // private hash function

 public:
  htable();
  ~htable();

  int getKey(string name); // converts name to an integer to and passes it to hash()
  int add(el_t);  // adds an element to the table and returns slot#
  el_t find(string name); // finds an element based on name and returns it
  el_t del(string name); // finds an element based on name, deletes and returns it
  void displayTable(ostream& os, bool isScreen); // displays the table with slots
  void loadTable(string fileName); // loads data from a text file
};
