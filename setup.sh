#!/bin/bash

script_full_path=$(dirname "$0")
cd $script_full_path

git clone git@gitlab.tugraz.at:oop1_ws/ws2023/framework.git framework
cd framework
git submodule update --init --recursive

cd ..
git clone git@gitlab.tugraz.at:oop1_ws/ws2023/testrunner.git testsystem
cd testsystem
git submodule update --init --recursive
cd ..

echo "Setup completed!"
