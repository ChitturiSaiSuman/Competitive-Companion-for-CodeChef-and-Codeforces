from colorama import Fore, Style
import sys
from os import system, listdir, remove
import time
from playsound import playsound
import pyttsx3

def say(word):
    speaker = pyttsx3.Engine()
    speaker.setProperty('rate', 175)
    speaker.say(word)
    speaker.runAndWait()

online_judge = True

program_to_be_executed = sys.argv[1]
if len(sys.argv) == 3:
    online_judge = False

system("clear")

start = None
end = None

print(Style.BRIGHT + "", end = "")

if ".java" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using javac 11.0.11")
    system("javac " + program_to_be_executed)
    if online_judge:
        start = time.time()
        system("timeout 2s java Main < in.in > output.out 2> err.err")
        end = time.time()
        if end - start > 2:
            print(Fore.RED + "Time Limit Exceeded")
            say("Time Limit Exceeded")
            exit(0)
    else:
        start = time.time()
        system("java Main < in.in > output.out 2> err.err")
        end = time.time()

elif ".cpp" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0")
    system("g++ -o runner " + program_to_be_executed + " -lm -O2")
    if online_judge:
        start = time.time()
        system("timeout 1s ./runner < in.in > output.out 2> err.err")
        end = time.time()
        if end - start > 1:
            print(Fore.RED + "Time Limit Exceeded")
            say("Time Limit Exceeded")
            exit(0)
    else:
        start = time.time()
        system("./runner < in.in > output.out 2> err.err")
        end = time.time()

elif ".c" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0")
    system("gcc -o runner "+program_to_be_executed+" -lm")
    if online_judge:
        start = time.time()
        system("timeout 1s ./runner < in.in > output.out 2> err.err")
        end = time.time()
        if end - start > 1:
            print(Fore.RED + "Time Limit Exceeded")
            say("Time Limit Exceeded")
            exit(0)
    else:
        start = time.time()
        system("./runner < in.in > output.out 2> err.err")
        end = time.time()

elif ".py" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using Python 3.8.5")
    if online_judge:
        start = time.time()
        system("timeout 5s python3 "+program_to_be_executed+" < in.in > output.out 2> err.err")
        end = time.time()
        if end - start > 5:
            print(Fore.RED + "Time Limit Exceeded")
            say("Time Limit Exceeded")
            exit(0)
    else:
        start = time.time()
        system("python3 "+program_to_be_executed+" < in.in > output.out 2> err.err")
        end = time.time()

with open("in.in", "r") as inputFile:
    s = inputFile.read()
    if len(s) > 1000:
        print(Fore.RED + "Large Input")
    else:
        print(Fore.CYAN + "STDIN:")
        print(Fore.WHITE + s)

with open("output.out", "r") as output:
    s = output.read()
    if len(s) > 1000:
        print(Fore.RED + "Large Output")
    else:
        print(Fore.CYAN + "STDOUT:")
        print(Fore.WHITE + s)

with open("err.err", "r") as err:
    s = err.read()
    if len(s) > 1000:
        print(Fore.RED + "Large Debug Output")
    else:
        print(Fore.CYAN + "STDERR:")
        print(Fore.WHITE + s)

for file in listdir():
    if "runner" in file or ".class" in file:
        remove(file)

system("python3 verify.py")
print(Fore.CYAN + "\nTime: " + Fore.GREEN + "%.6f"%(end - start), end = " s\n\n")