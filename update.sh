#!/bin/bash

script_full_path=$(dirname "$0")
cd $script_full_path

cd framework
git pull
git submodule update --init --recursive

cd ../testsystem
git pull
git submodule update --init --recursive

echo "Update completed!"
