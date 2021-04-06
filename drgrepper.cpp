#include <stdio.h>
//#include <io.h> //#include <unistd.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <thread>
#include <string>

using namespace std;

int WAIT_TIME = 3;

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
        std::cout << R"(▓█████▄  ██▀███       ▄████  ██▀███  ▓█████  ██▓███   ██▓███  ▓█████  ██▀███  
▒██▀ ██▌▓██ ▒ ██▒    ██▒ ▀█▒▓██ ▒ ██▒▓█   ▀ ▓██░  ██▒▓██░  ██▒▓█   ▀ ▓██ ▒ ██▒
░██   █▌▓██ ░▄█ ▒   ▒██░▄▄▄░▓██ ░▄█ ▒▒███   ▓██░ ██▓▒▓██░ ██▓▒▒███   ▓██ ░▄█ ▒
░▓█▄   ▌▒██▀▀█▄     ░▓█  ██▓▒██▀▀█▄  ▒▓█  ▄ ▒██▄█▓▒ ▒▒██▄█▓▒ ▒▒▓█  ▄ ▒██▀▀█▄  
░▒████▓ ░██▓ ▒██▒   ░▒▓███▀▒░██▓ ▒██▒░▒████▒▒██▒ ░  ░▒██▒ ░  ░░▒████▒░██▓ ▒██▒
 ▒▒▓  ▒ ░ ▒▓ ░▒▓░    ░▒   ▒ ░ ▒▓ ░▒▓░░░ ▒░ ░▒▓▒░ ░  ░▒▓▒░ ░  ░░░ ▒░ ░░ ▒▓ ░▒▓░
 ░ ▒  ▒   ░▒ ░ ▒░     ░   ░   ░▒ ░ ▒░ ░ ░  ░░▒ ░     ░▒ ░      ░ ░  ░  ░▒ ░ ▒░
 ░ ░  ░   ░░   ░    ░ ░   ░   ░░   ░    ░   ░░       ░░          ░     ░░   ░ 
   ░       ░              ░    ░        ░  ░                     ░  ░   ░     
 ░                                                                            )" << "\n" << endl;
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
    green();
    printf("[~] ");
    reset();
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
        banner();
        //If correct number of args
	if (argc == 4 ) {
	    WAIT_TIME = stoi(argv[3]);
	} else {
	    //Continue
	}
	if ( argc >= 3 && argc < 5) {
            if (FileExist(argv[1]) == true) {
                for (; true; )  { //Infinite loop until found
                    bool findsearch = SearchFind(argv[1], argv[2]);
                    if (findsearch != true) {
                        //Continue
                    } else {
			// Current date/time based on current system
			time_t now = time(0);

			// Convert now to tm struct for local timezone
			tm* localtm = localtime(&now);

                        clearScreen();
		        banner();
                        green();
                        printf("[~]");
			reset();
			printf(" Found tipper >> ");
                        reset();
			green();
                        cout << argv[2];
			reset();
			printf(" >> ");
			printf(asctime(localtm));
                        fflush(stdout);
                        break;
                    }
                ProgressBar(WAIT_TIME, argv[1]);
                }
            } else {
                red();
                cout << "[!] Input file ";
		reset();
		cout << argv[1]; 
		red();
		cout << " does not exist" << endl;
                reset();
            }
        } else if ( argc > 4  ) {
            red();
            printf("[!] Too many arguments supplied\n");
            reset();
        } else {
            red();
            printf("[!] At least two arguments expected\n\n");
            reset();
	    green();
            printf("[?]");
	    reset();
	    printf(" ./drgrepper [file] [tipper] (optional: wait value)\n");
        }
    }
    catch (...) {
        red();
        cout << "\tCaught Ctrl-c or exception!" << endl;
        reset();
    }
}