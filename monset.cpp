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
        std::cout << R"(███╗   ███╗ ██████╗ ███╗   ██╗███████╗███████╗████████╗
████╗ ████║██╔═══██╗████╗  ██║██╔════╝██╔════╝╚══██╔══╝
██╔████╔██║██║   ██║██╔██╗ ██║███████╗█████╗     ██║   
██║╚██╔╝██║██║   ██║██║╚██╗██║╚════██║██╔══╝     ██║   
██║ ╚═╝ ██║╚██████╔╝██║ ╚████║███████║███████╗   ██║   
╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚══════╝   ╚═╝)" << "\n" << endl;
	reset();
}

int main( int argc, char *argv[] ){
    try {
        //If correct number of args
	banner();
	if ( argc == 3) {
            if (string(argv[2]) == "start") {
		green();
		printf("[~] ");
		reset();
	        cout << "Placing " << argv[1] << " into monitor mode" << endl;
		system("sudo airmon-ng check kill");
		
		string down1 = string("sudo ip link set ") + argv[1] + string(" down");
		string down2 = string("sudo iw dev ") + argv[1] + string(" set type monitor");
		string down3 = string("sudo ip link set ") + argv[1] + string(" up");
		string iwconfig = string("iwconfig ") + argv[1];

		system(down1.c_str());
		system(down2.c_str());
		system(down3.c_str());
		system(iwconfig.c_str());
	    } else if (string(argv[2]) == "stop") {
		green();
		printf("[~] ");
		reset();
	        cout << "Placing " << argv[1] << " into managed mode" << endl;
		system("sudo airmon-ng check kill");
		
		string down1 = string("sudo ip link set ") + argv[1] + string(" down");
		string down2 = string("sudo iw dev ") + argv[1] + string(" set type managed");
		string down3 = string("sudo ip link set ") + argv[1] + string(" up");
		string iwconfig = string("iwconfig ") + argv[1];

		system(down1.c_str());
		system(down2.c_str());
		system(down3.c_str());
		system(iwconfig.c_str());

	    } else {
		printf("[!] Improper action, options are [start/stop]");
	    }
        } else if ( argc > 3  ) {
            red();
            printf("[!] Too many arguments supplied\n");
            reset();
        } else {
            red();
            printf("[!] Two arguments expected\n\n");
            reset();
	    green();
            printf("[?]");
	    reset();
	    printf(" ./monset [interface] [start/stop]\n");
        }
    }
    catch (...) {
        red();
        cout << "\tCaught Ctrl-c or exception!" << endl;
        reset();
    }
}