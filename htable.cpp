// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Andro Yono
// File Type: implementation htable.cpp
// =============================================

#include <iostream>
#include <fstream>
#include <sstream>

#include "htable.h"

using namespace std;

htable::htable() {
  //empty
}

htable::~htable() {
  //empty
}

int htable::getKey(string name)
{
  // use upper version of the first letter of name
  int key = toupper(name[0]) - 65; // code of 'A'
  key = hash(key);
  return key;
}

int htable::hash(int key) { // hash function
 int position = (key % TSIZE);    //using % TSIZE
 return position; 
}

int htable::add(el_t element ) {
  int slot = hash(element.key);  // hash with the key part
  table[slot].addRear(element); //add element to table
  return slot; //adding the element to a slist in the slot
}

el_t htable::find(string name) {   //find element using name
 int slot = getKey(name);         // hash with name
 el_t selement;                 // this is the element to look for in slist
 selement.name = name;	          // initialize selement with just the name
 return table[slot].search2(selement);  //call slist's search2 with selement which returns the found element  
}

el_t htable::del(string name)
{
    int slot = getKey(name);         // hash with name
    el_t selement;                 // this is the element to look for in slist
    selement.name = name;	          // initialize selement with just the name
    return table[slot].del(selement);  //call slist's search2 with selement which returns the found element  
}

//displays the entire table with slots (isScreen == true)
// or to a file (isScreen == false) without slots
void htable::displayTable(ostream& os, bool isScreen)
{
  for (int i = 0; i < TSIZE; i++)
  {
      if(isScreen)
          os << i << ":" ;

      table[i].displayAll(os,isScreen);  // call slist's displayAll
  }
}

// loads contents of fileName file to this table
// file format is one line to one movie, fields separated by "+"
// Space is not suitable as a separator because many fields may contain spaces.
void htable::loadTable(string fileName)
{
  int key;
  string line, keyS, name, date, stars, dirs;

  ifstream ifs(fileName.c_str()); // open file
  while (getline(ifs, line)) // read it line by line
  {
    istringstream f(line); // to split the line
    getline(f, name, '+');
    getline(f, date, '+');
    getline(f, stars, '+');
    getline(f, dirs, '+');
    key = getKey(name);

    // create a new element and add it to table
    el_t newPerson(key, name, date, stars, dirs);
    add(newPerson);
  }
}
