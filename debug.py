import os
import sys
from colorama import Fore, Style, Back

import pyttsx3
engine = pyttsx3.init()
engine.setProperty('rate', 150)

program1 = sys.argv[1]
program2 = sys.argv[2]

os.system("python3 run.py "+program1)
os.system("clear")
os.system("cp output.out out1.out")

os.system("python3 run.py "+program2)
os.system("clear")
os.system("cp output.out out2.out")

output1 = ""
output2 = ""

with open("out1.out") as out:
    output1+=out.read()
    output1 = list(map(str,output1.split('\n')))

with open("out2.out") as out:
    output2+=out.read()
    output2 = list(map(str,output2.split('\n')))

if output1 != output2:
    print(Fore.RED + "Unequal Outputs dude")
    engine.say("Unequal Outputs dude")
    engine.runAndWait()
    fail_count = 0
    for i in range(len(output1)):
        if output1[i]!=output2[i]:
            fail_count += 1
            print(Fore.RED + str(i+1) + "th test case failed")
            if fail_count == 10:
                print(Fore.RED + "There could be Many. First rectify these you Idiot!")
                break

    print("Output1")
    print(output1)

    print("Output2")
    print(output2)

else:
    print(Fore.GREEN + "Hurray! Outputs Matched")
    engine.say("Hurray! Outputs matched")
    engine.runAndWait()