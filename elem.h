// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//-----------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// class represents a movie
class el_t {
private:
  int key;      // key
  string name;  // movie title
  string date;  // release date
  string stars; // main actors
  string dirs;  // directors

public:

  el_t();  // to create a blank el_t object

  // to create an initialized el_t object
  el_t(int key, string aname, string adate, string astars, string adirs);

  bool operator==(el_t);  // overload == for search
  bool operator!=(el_t);  // overload != for search
  // In search == is used to compare node elements
  // but what does it mean for this client to compare
  // node elements? -- This mean compare my names.

  // this overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  // os may be cout or an output file (ofstream).
  friend ostream& operator<<(ostream&, const el_t&);
  
  friend class htable;  // client of this class is htable which needs access to the key part of el_t 
};
