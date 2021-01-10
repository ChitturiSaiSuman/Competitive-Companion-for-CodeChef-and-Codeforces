import sys
import os
import time
program_to_be_executed = sys.argv[1]
os.system("clear")
print("Debug Output:")
print("*"*50)
this = time.time()
if ".java" in program_to_be_executed:
    os.system("javac "+program_to_be_executed)
    this = time.time()
    os.system("java Main "+"< input.txt > output.txt")
elif ".cpp" in program_to_be_executed:
    os.system("g++ -o runner "+program_to_be_executed+" -lm")
    this = time.time()
    os.system("./runner "+"< input.txt > output.txt")
elif ".c" in program_to_be_executed:
    os.system("gcc -o runner "+program_to_be_executed+" -lm")
    this = time.time()
    os.system("./runner "+"< input.txt > output.txt")
elif ".py" in program_to_be_executed:
    this = time.time()
    os.system("python3 "+program_to_be_executed+" < input.txt > output.txt")
print("*"*50)
with open("output.txt","r") as output:
    s = output.read()
    if len(s)>1000:
        print("Huge Output")
    else:
        print("Output:")
        print("*"*50)
        os.system("cat output.txt")
        print("*"*50)
print("Time: ",time.time()-this)
print("Done!")
for file in os.listdir():
    if "runner" in file or ".class" in file:
        os.system("rm "+file)