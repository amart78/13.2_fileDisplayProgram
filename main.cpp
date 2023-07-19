/***************************************************************************************
13.2 FILE DISPLAY PROGRAM

This program displays the contents of a file as the user requests. 
Larger files are displayed 24 lines at a time with the user typing a key
to display the next 24 lines.
****************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

void displayBookMenu();
void pause();

int main(){
    const int SIZE = 24;    // Defines the number of lines to be output at a time
    string bookFile, line;
    
    displayBookMenu();

    // Gets book (i.e. file name) from user.
    cout << "\nPlease enter a book title: ";
    getline(cin, bookFile);

    // Converts user input to `.txt` file format & opens corresponding file.
    bookFile =  bookFile + ".txt";      
    ifstream file(bookFile);

    // Loops through file contents until the end is reached, 
    // pausing every `SIZE` lines.
    while (!file.fail() ){
        for (int i = 1; !file.eof(); i++){
            getline(file, line);
            cout << i << " " << line << endl;

            if (i % SIZE == 0){
                pause();
            }
        }
    }

    file.close();

    return 0;
};

// displayBookMenu ------------------------------------------------------------
// This function outputs file names the user can choose
void displayBookMenu(){
    cout << "\nBooks available:\n\n"
         << "A Tale of Two Cities\n"
         << "Adventures of Sherlock Holmes\n"
         << "Count of Monte Cristo\n"
         << "Moby Dick\n"
         << "The Time Machine\n";
}

// pause ----------------------------------------------------------------------
// This function "pauses" the program until the user presses 'enter'
void pause(){
    cout << "Press enter to continue...";
    cin.clear();
    cin.sync();
    cin.get();
}