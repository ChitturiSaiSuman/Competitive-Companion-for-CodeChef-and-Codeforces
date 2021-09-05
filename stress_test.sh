trap clean SIGINT
clean() {
    echo ""
    echo "Removing generator"
    rm generator
    echo "Removing exe1"
    rm exe1
    echo "Removing exe2"
    rm exe2
    exit
}

echo "Compiling generator.cpp"
g++ -std=c++17 -Wshadow -Wall -o generator generator.cpp -O2 -Wno-unused-result
echo "Compiling $1"
g++ -std=c++17 -Wshadow -Wall -o exe1 $1 -O2 -Wno-unused-result
echo "Compiling $2"
g++ -std=c++17 -Wshadow -Wall -o exe2 $2 -O2 -Wno-unused-result

for((i = 1; ; ++i)); do
    echo "Test Case: $i"
    ./generator $i > input.in
    # echo "Running $1"
    # ./exe1 < input.in > out1.out
    # echo "Running $1"
    # ./exe2 < input.in > out2.out
    # diff -w out1.out out2.out || break
    diff -w <(./exe1 < input.in) <(./exe2 < input.in) || break
done