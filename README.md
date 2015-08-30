# OpenVox
OpenVox is an open source C++ voxel engine built by the [r/voxelgamedev](http://www.reddit.com/r/voxelgamedev) community.

## License
All source code files are licensed under the [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0) unless marked otherwise in a particular folder/file.  Please see the [NOTICE](https://github.com/VoxelGameDev/OpenVox/blob/master/NOTICE) file for information on additional licensed works used in the project.

## Requirements for OpenVox
The engine is built and tested for Windows, Linux, and MacOS X.  It requires a graphics card and drivers capable of running OpenGL 3.2 or greater. To compile OpenVox you will need a C++ compiler that supports C++11.  Cmake is used for building the project files.

## How To Contribute
If you're interested in helping please read the [CONTRIBUTING](https://github.com/VoxelGameDev/OpenVox/blob/master/CONTRIBUTING.md) documentation.

## Setup:

### Pre-installation requirements
1.  [Install CMake](http://www.cmake.org/install/)
2.  [Install git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)

### Clone Repository and Build

#### Windows
git clone --recurse-submodules https://github.com:VoxelGameDev/OpenVox openvox
```
cd openvox
./build.bat
```

#### Mac or Linux
```
git clone --recurse-submodules https://github.com:VoxelGameDev/OpenVox openvox
cd openvox
./build.sh
```
