# Graph Framework
This framework is used to represent graphs as adjacency lists with two files, one for vertices and one for edges.
Vertices and edges are designed to host attributes for visualization. 

## Features
* compute graphs based on gray scaled images (maps)
* cvs format to represent graphs
* tool to visualize graphs on or as images (maps) including paths
* designed for teaching

## Download and Run Programm 
### Windows
Install and setup mingw64 or Codeblocks 20*.

Assuming you project should be located in ```$HOME\projects```.
```
mkdir -p "$HOME\projects"
cd "$HOME\projects"
git clone https://github.com/mx-teaching/algodata_graph_framework.git
cd algodata_graph_framework
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
cd $HOME\projects\algodata_graph_framework"
mkdir build
cd build
cmake -G "CodeBlocks - MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
mingw32-make
```

### Linux
Install ```libopencv-dev``` 
Assuming you project should be located in ```$HOME/projects```.
```
mkdir -p $HOME/projects
cd $HOME/projects
git clone https://github.com/mx-teaching/algodata_graph_framework.git
cd algodata_graph_framework
```

Now you can combile the projects

```
mkdir $HOME/projects/algodata_graph_framework/build
cd $HOME/projects/algodata_graph_framework/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```
