#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>

int bytesWaiting;
int STDIN = 0;
bool initialized = false;
int _kbhit() {
    //static const int STDIN = 0;
    //static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }    
    initialized = false;
    ioctl(STDIN, FIONREAD, &bytesWaiting);    
    return bytesWaiting;
}