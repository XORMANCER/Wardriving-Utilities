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
                             /XXXXXX/^\XDCAU\
                                )";
	red();
        printf("\n\t\t\t      . DragonHorse 0.1 .\n\n");
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

void ProgressBar(int WaitTime) {
    int count = 0;
    cout << "Waiting for " << WaitTime << " Second(s)";
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
        banner();
        //If correct number of args
        if ( argc == 3 ) {
            if (FileExist(argv[1]) == true) {
                for (; true; )  { //Infinite loop until found
                    bool findsearch = SearchFind(argv[1], argv[2]);
                    if (findsearch != true) {
                        //Continue
                    } else {
                        clearLine();
                        green();
                        printf("\t\t\t   [~] Found string '");
                        reset();
                        cout << argv[2] << "'" << endl;
                        fflush(stdout);
                        break;
                    }
                ProgressBar(WAIT_TIME);
                }
            } else {
                red();
                cout << "\t       [!] File Paramenter '" << argv[1] << "' does not exist\n" << endl;
                reset();
            }
        } else if ( argc > 3 ) {
            red();
            printf("\t\t      [!] Too many arguments supplied\n\n");
            reset();
        } else {
            red();
            printf("\t     [!] Two arguments expected ");
            reset();
            printf("[File Input] [Search String]\n\n");
        }
    }
    catch (...) {
        red();
        cout << "\tCaught Ctrl-c or exception!" << endl;
        reset();
    }
}
