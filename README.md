# lineare_listen
## Download and Run Programm
Assuming you project should be located in ```$HOME\projects```.
```
mkdir -p "$HOME\projects"
cd "$HOME\projects"
git clone https://github.com/mx-teaching/algodata_graphs.git
cd algodata_graphs
mkdir 3rdParty
cd 3rdParty
git clone -b OpenCV-4.1.1-x64 https://github.com/huihut/OpenCV-MinGW-Build.git OpenCV
```

First extend the search path on your system with the directory ```$HOME\projects\algodata_graphs\3rdParty\OpenCV\x64\mingw\lib```. This is necessary to find the opencv dll need by the program

There you have two options:
* You can use the dialog System ```Properties -> Advanced -> Enviroment Variables``` or by using
* the terminal and the command ```$env:Path += ";$HOME\projects\algodata_graphs\3rdParty\OpenCV\x64\mingw\bin"```. Using the terminal exdends the serach path only for the current session!

Now you can combile the projects


```
$env:Path += ";$HOME\projects\algodata_graphs\3rdParty\OpenCV\x64\mingw\bin"
cd $HOME\projects\algodata_graphs"
mkdir build
cd build
cmake -G "CodeBlocks - MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
mingw32-make
```
