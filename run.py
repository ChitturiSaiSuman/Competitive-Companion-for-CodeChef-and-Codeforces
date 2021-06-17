from typing import Tuple
from colorama import Fore, Style, Back
import sys
import os
import time

import pyttsx3
engine = pyttsx3.init()
engine.setProperty('rate', 150)

online_judge = True

program_to_be_executed = sys.argv[1]
if len(sys.argv) == 3:
    online_judge = False

os.system("clear")

start = None
end = None

print(Style.BRIGHT + "", end = "")

if ".java" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using javac 11.0.11")
    os.system("javac " + program_to_be_executed)
    if online_judge:
        start = time.time()
        os.system("timeout 4s java Main < in.in > output.out 2> err.err")
        end = time.time()
        if end - start > 4:
            print(Fore.RED + "Time Limit Exceeded")
            engine.say("Time Limit Exceeded")
            engine.runAndWait()
            exit(0)
    else:
        start = time.time()
        os.system("java Main < in.in > output.out 2> err.err")
        end = time.time()

elif ".cpp" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0")
    os.system("g++ -o runner " + program_to_be_executed + " -lm -O2")
    if online_judge:
        start = time.time()
        os.system("timeout 2s ./runner < in.in > output.out 2> err.err")
        end = time.time()
        if end - start > 2:
            print(Fore.RED + "Time Limit Exceeded")
            engine.say("Time Limit Exceeded")
            engine.runAndWait()
            exit(0)
    else:
        start = time.time()
        os.system("./runner < in.in > output.out 2> err.err")
        end = time.time()

elif ".c" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0")
    os.system("gcc -o runner "+program_to_be_executed+" -lm")
    if online_judge:
        start = time.time()
        os.system("timeout 2s ./runner < in.in > output.out 2> err.err")
        end = time.time()
        if end - start > 2:
            print(Fore.RED + "Time Limit Exceeded")
            engine.say("Time Limit Exceeded")
            engine.runAndWait()
            exit(0)
    else:
        start = time.time()
        os.system("./runner < in.in > output.out 2> err.err")
        end = time.time()

elif ".py" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using Python 3.8.5")
    if online_judge:
        start = time.time()
        os.system("timeout 10s python3 "+program_to_be_executed+" < in.in > output.out 2> err.err")
        end = time.time()
        if end - start > 10:
            print(Fore.RED + "Time Limit Exceeded")
            engine.say("Time Limit Exceeded")
            engine.runAndWait()
            exit(0)
    else:
        start = time.time()
        os.system("python3 "+program_to_be_executed+" < in.in > output.out 2> err.err")
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

for file in os.listdir():
    if "runner" in file or ".class" in file:
        os.remove(file)

os.system("python3 verify.py")
print(Fore.CYAN + "\nTime: " + Fore.GREEN + "%.6f"%(end - start), end = " s\n\n")