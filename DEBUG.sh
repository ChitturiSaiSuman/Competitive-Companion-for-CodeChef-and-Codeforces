# Black        0;30     Dark Gray     1;30
# Red          0;31     Light Red     1;31
# Green        0;32     Light Green   1;32
# Brown/Orange 0;33     Yellow        1;33
# Blue         0;34     Light Blue    1;34
# Purple       0;35     Light Purple  1;35
# Cyan         0;36     Light Cyan    1;36
# Light Gray   0;37     White         1;37

NC='\033[0m'
ORANGE='\033[0;33m'
BLACK='\033[1;30m'
RED='\033[1;31m'
GREEN='\033[1;32m'
BLUE='\033[1;34m'
PURPLE='\033[1;35m'
CYAN='\033[1;36m'
YELLOW='\033[1;33m'

clear

echo "Compiling $1 using Debug Flags"
g++ -std=c++17 -Wshadow -Wall -o exe $1 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
file_name=$(echo $1 | cut -d'.' -f1)
input_file="$file_name"_01.in
output_file="$file_name"_01.out

if [ "$?" != "0" ]
then
    printf "${CYAN}STATUS: ${RED}COMPILATION ERROR\n${NC}"
    out=$(paplay /home/suman/Music/CP_SOUNDS/CFAILED.ogg)

else
    echo "Now Running $1 in Debug Mode"
    ./exe < $input_file > STDOUT
    if [ "$?" != "0" ]
    then
        paplay /home/suman/Music/CP_SOUNDS/RTE.ogg
    fi
    rm exe
fi