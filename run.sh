cd build/
cmake ..
cmake --build .
rm -rf ../output
mkdir ../output
./main 2 encomendas3000.txt carrinhas50.txt