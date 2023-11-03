#!/usr/bin/env bash

set -euo pipefail

PATH_TO_LIBBSON=$PWD/libbson/
MONGO_CXX_INSTALL_DIR=$PWD/mongo-cxx/

# build libbson
cd ./libbson/
if [ ! -f configure ]; then
    ./autogen.sh
fi
if [ ! -f Makefile ]; then
    ./configure
fi
make

# build mongocxx
cd ../
mkdir -p mongo-cxx/lib
cd mongo-cxx-driver/build
cmake ..                                                \
    -DCMAKE_BUILD_TYPE=Release                          \
    -DBSONCXX_POLY_USE_BOOST=1                          \
    -DMONGOCXX_OVERRIDE_DEFAULT_INSTALL_PREFIX=OFF      \
    -DCMAKE_CXX_STANDARD_LIBRARIES="-L$PATH_TO_LIBBSON" \
    -DCMAKE_INSTALL_PREFIX=$MONGO_CXX_INSTALL_DIR       \
    -DCMAKE_INSTALL_RPATH=$MONGO_CXX_INSTALL_DIR/lib
make
make install
