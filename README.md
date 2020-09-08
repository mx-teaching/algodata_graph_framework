# Graph Framework
This framework is used to represent graphs as adjacency lists with two files, one for vertices and one for edges.
Vertices and edges are designed to host attributes for visualization. 

## Features
* compute graphs based on gray scaled images (maps)
* cvs format to represent graphs
* tool to visualize graphs on or as images (maps) including paths
* designed for teaching
* features c++ 2014 and soon 2017
* for windows and linux

## Graph example
### Inner city of Viennas subway net

#### Graph
<img src="https://github.com/mx-teaching/algodata_graph_framework/blob/master/res/ubahn.png" width="400">

Two files are used to reprecent the vertices and and the edges.

ubahn.vertices.cvs
```
 vertex.id;             label;      value;       column;        row
         0;     Schottenring ;          1;          996;       372
         1;    Schwedenplatz ;          1;         1080;       453
         2;       Wien Mitte ;          1;         1080;       620
         3;         Stadtark ;          1;          986;       700
         4;       Karlsplatz ;          1;          837;       700
         5;  Muesumsquartier ;          1;          765;       620
         6;     Volkstheater ;          1;          756;       536
         7;         Rathhaus ;          1;          767;       447
         8;      Schottentor ;          1;          858;       372
         9;      Herrengasse ;          1;          840;       537
        10;     Stefansplatz ;          1;          920;       537
        11;        Stubentor ;          1;         1017;       551
```       
ubahn.edges.cvs
```
   edge.id;     weight;     src.id;     des.id
         0;          1;          0;          1
         1;          1;          1;          0
         2;          1;          1;          2
         3;          1;          2;          1
         4;          1;          2;          3
         5;          1;          3;          2
         6;          1;          3;          4
         7;          1;          4;          5
         8;          1;          1;         10
         9;          1;         10;          1
        10;          1;         10;          4
        11;          1;          4;         10
        12;          1;          4;          5
        13;          1;          5;          4
        14;          1;          5;          6
        15;          1;          6;          7
        16;          1;          7;          8
        17;          1;          8;          7
        18;          1;          8;          0
        19;          1;          0;          8
        20;          1;          6;          9
        21;          1;          9;          6
        22;          1;          9;         10
        23;          1;         10;          9
        24;          1;         10;         11
        25;          1;         11;         10
        26;          1;         11;          2
        27;          1;          2;         11
```    
#### Path
A file in the same format as edges us used to reprecent a path.
In this case the shortest path between Schwedenplatz to Museumsquartier. Which can also be visualized

ubahn.path.cvs  
```   
   edge.id;     weight;     src.id;     des.id
         8;          1;          1;         10
        10;          1;         10;          4
        12;          1;          4;          5
```    
<img src="https://github.com/mx-teaching/algodata_graph_framework/blob/master/res/ubahn.path.png" width="400">

### Cave enviroment
The framework is able to generate a vertices file and edge file based on a gray scaled image and visualize paths.
In this case (500x500pix) the graph as 250000 vertices and 1952916 edges. 

<img src="https://github.com/mx-teaching/algodata_graph_framework/blob/master/res/cave.path.example.png" width="400" border="1">

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
# unzip the OpenCV.zip or compile opencv as described later
```

Now you can combile the projects

```
cd $HOME\projects\algodata_graph_framework"
mkdir build
cd build
cmake -G "CodeBlocks - MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug  -DBUILD_SHARED_LIBS=OFF ..
mingw32-make
```
#### OpenCV on Windows
If you like to compile your own opencv you can use the following cmake command
```
cmake.exe -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX="$HOME\projects\algodata_graph_framework\3rdParty\OpenCV" `
  -DBUILD_SHARED_LIBS=OFF  `
  -DBUILD_opencv_calib3d=OFF `
  -DBUILD_opencv_dnn=OFF -DBUILD_opencv_features2d=OFF `
  -DBUILD_opencv_flann=OFF -DBUILD_opencv_gapi=OFF `
  -DBUILD_opencv_objdetect=OFF -DBUILD_opencv_photo=OFF `
  -DBUILD_opencv_stitching=OFF -DBUILD_opencv_ts=OFF `
  -DBUILD_opencv_video=OFF -DBUILD_opencv_videoio=OFF `
  -DBUILD_opencv_imgcodecs=ON ..
make install
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
