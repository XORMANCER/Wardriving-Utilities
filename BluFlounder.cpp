#include <stdio.h>
//#include <io.h> //#include <unistd.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

const int WAIT_TIME = 7;

void clearScreen() {
    //cout << "\033[2J\033[1;1H";
    system("clear");
}

void clearLine() {
    printf("\033[2K");

}

void red() {
  printf("\033[1;31m");
}

void blue() {
  printf("\033[1;36m");
}

void green() {
  printf("\033[0;32m");
}

void reset() {
  printf("\033[0m");
}

void banner2() {
        clearScreen();
	blue();
        std::cout << R"(         ^
       //                        ___   ___
     (*)     "O"                /  _   _  \
    (*)                           / \ / \
   (*)    "O"                    |   |   |    |\
  //                             |O  |O  |___/  \     ++
 //                               \_/ \_/    \   | ++
//                              _/      __    \  \
/     /|   /\                  (________/ __   |_/
     / |  |  |                   (___      /   |    |\
    / /  /   |                     \     \|    |___/  |
   |  | |   /                       \_________      _/   ++++
  /   | |  |                      ++           \    |
 |   / /   |                              ++   |   /  +++
/   /  |   |                               ++ /__/
~~~ ~~~~   ~~~~~~~~~~~~  ~~~~~~~~~~~~~  ~~~~        ~~+++~~~~ ~)" << "\n" << endl;
	reset();
}

void banner() {
        clearScreen();
	blue();
        std::cout << R"(
                                   ____
                               /\|    ~~\
                             /'  |   ,-. `\
                            |       | X |  |
                           _|________`-'   |X
                         /'          ~~~~~~~~~,
                       /'             ,_____,/_
                    ,/'        ___,'~~         ;
~~~~~~~~|~~~~~~~|---          /  X,~~~~~~~~~~~~,
        |       |            |  XX'____________'
        |       |           /' XXX|            ;
        |       |        --x|  XXX,~~~~~~~~~~~~,
        |       |          X|     '____________'
        |   o   |---~~~~\__XX\             |XX
        |       |          XXX`\          /XXXX
~~~~~~~~'~~~~~~~'               `\xXXXXx/' \XXX
                                 /XXXXXX\
                               /XXXXXXXXXX\
                             /XXXXXX/^\XDCAU\)" << "\n" << endl;
	reset();
}

bool FileExist(string filename) {
    /* try to open file to read */
   ifstream ifile;
   ifile.open(filename);
   if(ifile) {
       ifile.close();
       return true;
   } else {
       return false;
   }
}

bool SearchFind(string filename, string search) {
    fstream fdata(filename, fstream::in );
    string sdata;
    getline( fdata, sdata, '\0');
    //cout << sdata << endl;
    fdata.close();
    /* Determine if our search term exists */
    if (sdata.find(search) != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

void ProgressBar(int WaitTime, string FILENAME) {
    int count = 0;
    cout << "Scanning " << FILENAME << " every " << WaitTime << " Second(s)";
    for(count;count < WaitTime; ++count){
        cout << ". " ;
        fflush(stdout);
        std::chrono::seconds timespan(1); // or whatever
        std::this_thread::sleep_for(timespan);
    }
    reset();
    cout << "Not Found";
    std::chrono::seconds timespan(1); // or whatever
    std::this_thread::sleep_for(timespan);
    cout << "\r";
    clearLine();
    fflush(stdout);
}


int main( int argc, char *argv[] ){
    try {
        banner2();
        //If correct number of args
        if ( argc == 3 ) {
            if (FileExist(argv[1]) == true) {
                for (; true; )  { //Infinite loop until found
                    bool findsearch = SearchFind(argv[1], argv[2]);
                    if (findsearch != true) {
                        //Continue
                    } else {
                        clearScreen();
		        banner();
                        green();
                        printf("[~] Found string '");
                        reset();
                        cout << argv[2] << "'\n" << endl;
                        fflush(stdout);
                        break;
                    }
                ProgressBar(WAIT_TIME, argv[1]);
                }
            } else {
                red();
                cout << "[!] File Paramenter '";
		reset();
		cout << argv[1]; 
		red();
		cout << "' does not exist\n" << endl;
                reset();
            }
        } else if ( argc > 3 ) {
            red();
            printf("[!] Too many arguments supplied\n\n");
            reset();
        } else {
            red();
            printf("[!] Two arguments expected ");
            reset();
            printf("./BluFloundr [File] [String]\n\n");
        }
    }
    catch (...) {
        red();
        cout << "\tCaught Ctrl-c or exception!" << endl;
        reset();
    }
}
