cd framework
git pull origin main
git submodule update --init --recursive
cd ..
cd testsystem
git pull origin main
git submodule update --init --recursive
cd ..
ECHO Update completed!
