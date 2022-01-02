# Black        0;30     Dark Gray     1;30
# Red          0;31     Light Red     1;31
# Green        0;32     Light Green   1;32
# Brown/Orange 0;33     Yellow        1;33
# Blue         0;34     Light Blue    1;34
# Purple       0;35     Light Purple  1;35
# Cyan         0;36     Light Cyan    1;36
# Light Gray   0;37     White         1;37

# A Shell Script to run a C++ Program

# Constants for colors
NC='\033[0m'
ORANGE='\033[0;33m'
BLACK='\033[1;30m'
RED='\033[1;31m'
GREEN='\033[1;32m'
BLUE='\033[1;34m'
PURPLE='\033[1;35m'
CYAN='\033[1;36m'
YELLOW='\033[1;33m'

path_to_templates='/home/suman/Competitive-Companion-for-Codechef'

clear

# Pass any additional argument to the script for No Judge

if [ "$2" != "" ]
then
    online_judge="0"
else
    online_judge="1"
fi

compilation_log=$(g++ -std=c++17 -Wshadow -Wall -o exe $1 -O2 -Wno-unused-result)

if [ "$?" != "0" ]
then
    printf "\n${CYAN}STATUS: ${RED}COMPILATION ERROR\n${NC}"
    out=$(paplay $path_to_templates/CP_SOUNDS/CFAILED.ogg)
    
else
    if [ "$online_judge" == "0" ]
    then
        # Run the program against one sample
        # Output is captures in a file named STDOUT
        # STDERR stream is captured in a file named STDERR
        ./exe < STDIN > STDOUT 2> STDERR
        rm exe
    else
        # To Capture the time taken for the program
        start=`date +%s.%6N`
        timeout 2s ./exe < STDIN > STDOUT 2> STDERR
        end=`date +%s.%6N`
        if [ "$?" != "0" ]
        # Implies runtime error
        then
            printf "${YELLOW}RUNTIME ERROR\n${NC}"
            ./exe < $input_file > STDOUT
            paplay $path_to_templates/CP_SOUNDS/RTE.ogg
            exit
        fi
        runtime=$(echo "scale=2 ; $end - $start > 1" | bc)
        if [ "$runtime" == "1" ]
        then
            printf "${YELLOW}Time Limit Exceeded\n${NC}"
            paplay $path_to_templates/CP_SOUNDS/TLE.ogg
        else
            runtime=$( echo "$end - $start" | bc -l )
            check=$(diff --strip-trailing-cr -w STDOUT STDEXPOUT)
            printf "${CYAN}STDIN:\n${NC}"
            cat STDIN
            printf "\n${CYAN}EXPECTED OUTPUT:\n${NC}"
            cat STDEXPOUT
            printf "\n${CYAN}YOUR OUTPUT:\n${NC}"
            cat STDOUT
            printf "\n${CYAN}STDERR:\n${NC}"
            cat STDERR
            printf "\n${ORANGE}TIME: ${runtime} S\n${NC}"
            if [ "$check" != "" ]
            then
                printf "\n${BLUE}STATUS: ${RED}Failed\n${NC}"
                paplay $path_to_templates/CP_SOUNDS/SFAILED.ogg
            else
                printf "\n${BLUE}STATUS: ${GREEN}Passed\n${NC}"
                paplay $path_to_templates/CP_SOUNDS/SPASSED.ogg
            fi
        fi
        rm exe
    fi
fi
