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

clear

echo "Compiling Generator.cpp"
g++ -std=c++17 -Wshadow -Wall -o generator Generator.cpp -O2 -Wno-unused-result
echo "Compiling $1"
g++ -std=c++17 -Wshadow -Wall -o exe1 $1 -O2 -Wno-unused-result
echo "Compiling $2"
g++ -std=c++17 -Wshadow -Wall -o exe2 $2 -O2 -Wno-unused-result

for((i = 1; ; ++i)); do
    echo "Test Case: $i"
    ./generator $i > STDIN
    diff=$(diff -w <(./exe1 < STDIN) <(./exe2 < STDIN))
    if [ "$diff" != "" ]
    then
        echo $diff
        echo "Removing generator"
        rm generator
        echo "Removing exe1"
        rm exe1
        echo "Removing exe2"
        rm exe2
        break
    fi
done