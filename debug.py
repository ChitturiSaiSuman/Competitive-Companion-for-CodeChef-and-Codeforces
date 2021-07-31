import os
import sys
import colorama
import pyttsx3

def say(word):
    speaker = pyttsx3.Engine()
    speaker.setProperty('rate', 175)
    speaker.say(word)
    speaker.runAndWait()

program1 = sys.argv[1]
program2 = sys.argv[2]

os.system("python3 run.py " + program1)
os.system("clear")
os.system("cp output.out out1.out")

os.system("python3 run.py " + program2)
os.system("clear")
os.system("cp output.out out2.out")

output1 = ""
output2 = ""

with open("out1.out") as out:
    output1 += out.read()
    output1 = list(map(str,output1.split('\n')))

with open("out2.out") as out:
    output2 += out.read()
    output2 = list(map(str,output2.split('\n')))

if output1 != output2:
    print(colorama.Fore.RED + "Unequal Outputs")
    say("Unequal Outputs")
    fail_count = 0
    for i in range(len(output1)):
        if output1[i] != output2[i]:
            fail_count += 1
            print(colorama.Fore.RED + str(i+1) + "th test case failed")
            if fail_count == 10:
                print(colorama.Fore.RED + "Could be more than 10")
                break

else:
    print(colorama.Fore.GREEN + "Outputs Matched")
    say("Outputs matched")