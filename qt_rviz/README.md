# qt-rviz
This is just an example about how to merge rviz and qt UI, especially for very beginners. Therefore, this software is simple in terms of features. If you need more funtions or features, I'm glad to add them.

### file notation
|file|notation|
|---|---|
|cmake|cmake files are used to include libraries to project|
|read_params.h|parse data from yaml node, type cast and handle with exception|
|display|generate window. set rviz. display cloud, path and other elements|
|publisher|read data from file and publish msg to ros|
|qt_rviz_node|main and entrance function|

### third_party
Not all code in third party are used. Used codes are listed here.

### compile and run
Get into root directory and run `./make.sh` to compile and run. Executable and other necessary files for execute are put into folder `install`. Here is a python3 script `create_trace.py` to generate a file. Click button `select trace` and select this file to show a line. Click button `select cloud` and select a pcd file to show a cloud. Now only point cloud files in pcd format are supported.