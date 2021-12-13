// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Andro Yono
// File type: client hw8client.cpp (tester)
//===========================================

#include <fstream>
#include <sstream>

#include "htable.h"

// the main menu of the program
// Returns the number of selected menu item.
int menu()
{
    cout << endl;
    cout << "1. Load the list of movies from the data file" << endl;
    cout << "2. Search for movie using the title / name" << endl;
    cout << "3. See all the data on the screen" << endl;
    cout << "4. Add a new movie" << endl;
    cout << "5. Delete a movie" << endl;
    cout << "6. Save the data to a file" << endl;
    cout << "7. Exit" << endl << endl;

    cout << "Enter your choice (1..7): ";
    int input = 0;
    cin >> input;
    return input;
}

int main() { 
  string newName,newDate,newStars,newDirs;
  string fileName;
  int newInt;
  htable newTable;
  int userInput = 0;
  char userInput2 = 'Y';

  while (userInput != 7) // i.e. exit
  {
      userInput = menu(); // ask what to do in a loop

      if (userInput == 1) // load from file
      {
          cout << "Enter the file name with extension: ";
          cin >> fileName;

          newTable.loadTable(fileName);
      }
      else if (userInput == 2) // search by name
      {
          cout << "Input a movie name/title: ";
          cin >> newName;
          el_t found = newTable.find(newName);
          el_t notFound;

          if (found == notFound)
              cout << newName << " not found.\n";
          else
              cout << "Found " << found << endl;
      }
      else if (userInput == 3) // display table on screen
          newTable.displayTable(cout,true);
      else if (userInput == 4) // add a new movie entered by a user
      {
          // getline is used to read lines with spaces
          getline(cin, newName);
          cout << "Input name: ";
          getline(cin,newName);
          cout << "Input release date: ";
          getline(cin,newDate);
          cout << "Input stars: ";
          getline(cin,newStars);
          cout << "Input directors: ";
          getline(cin,newDirs);
          newInt = newName[0];

          // create a new element and add it to table
          el_t newPerson(newInt, newName, newDate, newStars, newDirs);
          newTable.add(newPerson);
      }
      else if (userInput == 5) // delete an element given its name
      {
          cout << "Input a movie name/title: ";
          cin >> newName;
          el_t found = newTable.del(newName);
          el_t notFound;

          if (found == notFound)
              cout << newName << " not found.\n";
          else
              cout << "Deleted " << found << endl;
      }
      else if (userInput == 6) // save to file
      {
          cout << "Enter the file name with extension: ";
          cin >> fileName;

          ofstream ofs(fileName.c_str());
          newTable.displayTable(ofs,false);
      }
  }
}
