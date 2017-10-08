#!/bin/bash
CONFIG=Release
BUILDDIR=.build_nix

rm -r -d ${BUILDDIR}
mkdir ${BUILDDIR}
cd ${BUILDDIR}
cmake -DCMAKE_BUILD_TYPE=${CONFIG} ../src
cmake --build .
cmake --build . --target install

if [ $? -eq 0 ]
then
  CEC="cmake -E cmake_echo_color --green"
  ${CEC} "========================================"
  ${CEC} "Build completed."
  ${CEC} "Look for executables in bin directory"
  ${CEC} "========================================"
fi
cd ..
