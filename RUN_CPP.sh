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
compilation_log=$(g++ -std=c++17 -Wshadow -Wall -o exe $1 -O2 -Wno-unused-result)
if [ "$2" != "" ]
then
    online_judge="0"
else
    online_judge="1"
fi
if [ "$?" != "0" ]
then
    printf "\n${CYAN}STATUS: ${RED}COMPILATION ERROR\n${NC}"
    out=$(paplay /home/suman/Music/CP_SOUNDS/CFAILED.ogg)
else
    if [ "$online_judge" == "0" ]
    then
        ./exe < STDIN > STDOUT 2> STDERR
        rm exe
    else
        start=`date +%s.%6N`
        timeout 2s ./exe < STDIN > STDOUT 2> STDERR
        end=`date +%s.%6N`
        if [ "$?" != "0" ]
        then
            printf "${YELLOW}RUNTIME ERROR\n${NC}"
            ./exe < STDIN > STDOUT
            rm exe
            paplay /home/suman/Music/CP_SOUNDS/RTE.ogg
            exit
        fi
        rm exe
        time_taken=$(grep -oP '(?<=CPU )[0-9]+[.]+[0-9]+' STDERR)
        runtime=$( echo "$end - $start" | bc -l )
        if [[ ( $time_taken -gt 2 )]]
        then
            printf "${YELLOW}Time Limit Exceeded\n${NC}"
            paplay /home/suman/Music/CP_SOUNDS/TLE.ogg
        else
            check=$(diff --strip-trailing-cr -w STDOUT STDEXPOUT)
            printf "${CYAN}STDIN:\n${NC}"
            head -10 STDIN
            n_lines=$(wc -l STDIN | grep -o -E '[0-9]+')
            if [[ ( $n_lines -gt 10 ) ]]
            then
                echo "..."
            fi
            printf "\n${CYAN}EXPECTED OUTPUT:\n${NC}"
            head -10 STDEXPOUT
            n_lines=$(wc -l STDEXPOUT | grep -o -E '[0-9]+')
            if [[ ( $n_lines -gt 10 ) ]]
            then
                echo "..."
            fi
            printf "\n${CYAN}YOUR OUTPUT:\n${NC}"
            head -10 STDOUT
            n_lines=$(wc -l STDOUT | grep -o -E '[0-9]+')
            if [[ ( $n_lines -gt 10 ) ]]
            then
                echo "..."
            fi
            printf "\n${CYAN}STDERR:\n${NC}"
            head -n -2 STDERR
            n_lines=$(wc -l STDERR | grep -o -E '[0-9]+')
            if [[ ( $n_lines -gt 10 ) ]]
            then
                echo "..."
            fi
            printf "\n${ORANGE}TIME: ${runtime} S\n${NC}"
            if [ "$check" != "" ]
            then
                printf "\n${BLUE}STATUS: ${RED}Failed\n${NC}"
                paplay /home/suman/Music/CP_SOUNDS/SFAILED.ogg
            else
                printf "\n${BLUE}STATUS: ${GREEN}Passed\n${NC}"
                paplay /home/suman/Music/CP_SOUNDS/SPASSED.ogg
            fi
        fi
    fi
fi
