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
g++ -DSUMAN -std=c++17 -Wshadow -Wall -o generator Generator.cpp -O2 -Wno-unused-result
echo "Compiling $1"
g++ -DSUMAN -std=c++17 -Wshadow -Wall -o exe1 $1 -O2 -Wno-unused-result
echo "Compiling $2"
g++ -DSUMAN -std=c++17 -Wshadow -Wall -o exe2 $2 -O2 -Wno-unused-result

for((i = 1; ; ++i)); do
    echo "Test Case: $i"
    ./generator $i > STDIN
    ./exe1 < STDIN > out1
    ./exe2 < STDIN > out2
    diff=$(cmp out1 out2)
    if [ "$diff" != "" ]
    then
        echo $i
        cmp out1 out2
        break
    fi
done
