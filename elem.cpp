// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t() {
  key = -1;  // cannot be 0 because 0 is a valid key
  name = "";
}

// initializing constructor to create an el_t object 
el_t::el_t(int akey, string aname, string adate, string astars, string adirs)
{
  key = akey;
  name = aname;
  date = adate;
  stars = astars;
  dirs = adirs;
}
  
// overload == for search based on the name part only
bool el_t::operator==(el_t OtherOne)  {
    return (name == OtherOne.name);
}

// overload != for search based on the name part only
bool el_t::operator!=(el_t OtherOne) {
  return (name != OtherOne.name);
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)
{
    // key is produced from the name, so we don't read/write ley from file
    //os << E.key << "+";
    os << E.name << "+" << E.date << "+" << E.stars << "+" << E.dirs;

    return os;  
}
