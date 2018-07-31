#include "breach.h";

void screenSetUp () {

    initscr ();
    printw ("Breach!!");
    noecho ();
    refresh ();

}

int main (void) {

    screenSetUp ();

    return 0;

}