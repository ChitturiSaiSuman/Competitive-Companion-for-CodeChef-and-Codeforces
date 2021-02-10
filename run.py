from colorama import Fore, Style, Back
import sys
import os
import time

program_to_be_executed = sys.argv[1]
os.system("clear")

start = None
end = None

print(Style.BRIGHT + "", end="")

if ".java" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using javac 11.0.9.1")
    os.system("javac "+program_to_be_executed)
    start = time.time()
    os.system("java Main < in.in > output.out 2> err.err")
    end = time.time()

elif ".cpp" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0")
    os.system("g++ -o runner "+program_to_be_executed+" -lm")
    start = time.time()
    os.system("./runner < in.in > output.out 2> err.err")
    end = time.time()

elif ".c" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0")
    os.system("gcc -o runner "+program_to_be_executed+" -lm")
    start = time.time()
    os.system("./runner < in.in > output.out 2> err.err")
    end = time.time()

elif ".py" in program_to_be_executed:
    print(Fore.MAGENTA + "Running " + program_to_be_executed + Fore.YELLOW + " using Python 3.8.5")
    start = time.time()
    os.system("python3 "+program_to_be_executed+" < in.in > output.out 2> err.err")
    end = time.time()

with open("in.in", "r") as inputFile:
    s = inputFile.read()
    if len(s) > 1000:
        print(Fore.RED + "Huge Input")
    else:
        print(Fore.CYAN + "STDIN:")
        print(Fore.WHITE + s)

with open("output.out", "r") as output:
    s = output.read()
    if len(s) > 1000:
        print(Fore.RED + "Huge Output")
    else:
        print(Fore.CYAN + "STDOUT:")
        print(Fore.WHITE + s)

with open("err.err", "r") as err:
    s = err.read()
    if len(s) > 1000:
        print(Fore.RED + "Huge Debug Output")
    else:
        print(Fore.CYAN + "STDERR:")
        print(Fore.WHITE + s)

for file in os.listdir():
    if "runner" in file or ".class" in file:
        os.system("rm "+file)

os.system("python3 verify.py")
print(Fore.CYAN + "\nTime: " + Fore.GREEN + "%.6f"%(end - start), end = " s\n\n")