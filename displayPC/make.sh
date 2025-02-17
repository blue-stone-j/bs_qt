
# rm -rf build

# compile and run
mkdir -p build

cd ./build

cmake .. &&
make -j7 &&
./display_cloud