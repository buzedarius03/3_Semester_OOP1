git clone git@gitlab.tugraz.at:oop1_ws/ws2023/framework.git framework
cd framework
git submodule update --init --recursive
cd ..
git clone git@gitlab.tugraz.at:oop1_ws/ws2023/testrunner.git testsystem
cd testsystem
git submodule update --init --recursive
cd ..
ECHO Setup completed!
