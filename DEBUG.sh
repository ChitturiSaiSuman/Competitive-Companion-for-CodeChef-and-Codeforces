# Black        0;30     Dark Gray     1;30
# Red          0;31     Light Red     1;31
# Green        0;32     Light Green   1;32
# Brown/Orange 0;33     Yellow        1;33
# Blue         0;34     Light Blue    1;34
# Purple       0;35     Light Purple  1;35
# Cyan         0;36     Light Cyan    1;36
# Light Gray   0;37     White         1;37

# Modify this to change the source of Templates
templates_directory='/home/suman/Competitive-Companion-for-Codechef'

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

# Check if all of the following files are present
# If not present, create them
declare -a files=("STDIN" "STDOUT" "STDEXPOUT" "STDERR" "DEBUG.cpp" "DEBUG.h" )
for val in ${files[@]};
do
    if test -f "$val"; then
        :
    else
        touch $val
    fi
done

echo "Compiling $1 using Debug Flags"
g++ -DSUMAN DEBUG.cpp -std=c++17 -Wshadow -Wall -o exe $1 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

if [ "$?" != "0" ]
then
    printf "${CYAN}STATUS: ${RED}COMPILATION ERROR\n${NC}"
    paplay $templates_directory/CP_SOUNDS/CFAILED.ogg

else
    echo "Now Running $1 in Debug Mode"
    ./exe < STDIN > STDOUT
    if [ "$?" != "0" ]
    then
        paplay $templates_directory/CP_SOUNDS/RTE.ogg
    fi
    rm exe
fi