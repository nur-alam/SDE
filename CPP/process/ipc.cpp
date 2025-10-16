#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main() {
    int p[2] = {0}; 
    int fd = pipe(p); // p[0] = read end and p[1] = write end
    if(fd == -1) {
        cerr << "Pipe creation failed!!" << endl;
        return 0;
    }

    pid_t pid = fork();

    if(pid < 0) {
        cerr << "Fork failed!" << endl;
        return 0;
    } else if (pid == 0 ) { // child process
        close(p[1]);
        char buffer[256];
        ssize_t bytes_read = read(p[0], buffer, sizeof(buffer));
        if(bytes_read > 0) {
            cout << "child received: " << string(buffer, bytes_read) << endl;
        }
        close(p[0]);
    } else { // parent process
        close(p[0]);
        string message = "Hello from parent process";
        write(p[1], message.c_str(), message.length());
        close(p[1]);
        wait(NULL);
    }

    return 0;
}