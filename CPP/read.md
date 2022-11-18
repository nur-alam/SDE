
# Bits header file including
Here are the steps that I followed, if someone is still looking for an answer.
brew install gcc
gcc --version
cd to InstalledDir path:
cd /Library/Developer/CommandLineTools/usr/include
create bits directory in there. use sudo if permission issues
sudo mkdir bits
copy stdc++.h link in bits directory, in my case I downloaded it in Downloads.
cd bits
sudo cp ~/Downloads/stdc++.h stdc++.h
