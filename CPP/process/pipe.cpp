#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main() {
    int p[2] = {0};
    int fd = pipe(p); // creates in-memory buffer, no disk file
    if(fd == -1) {
        cerr << "Pipe creation failed!" << endl;
        return 0;
    }

    // writing to p[1] write end
    string message = "Hello World";
    write(p[1], message.c_str(), message.length());
    
    // read from p[0] read end
    char buffer[256];
    ssize_t bytes_read = read(p[0], buffer, sizeof(buffer));

    cout << bytes_read << " " << buffer << endl;

    close(p[0]); // close read end of fd
    close(p[1]); // close write end of fd

    return 0;
}