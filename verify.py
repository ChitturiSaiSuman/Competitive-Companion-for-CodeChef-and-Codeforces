from colorama import Fore, Style
from gtts import gTTS
from playsound import playsound
from os import system

def say(word):
    gTTS(word).save("sound.mp3")
    playsound("sound.mp3")
    system("rm sound.mp3")

p_out = open("output.out", "r")
a_out = open("out.out", "r")

p_output = p_out.read()
a_output = a_out.read()

p_out.close()
a_out.close()

print(Fore.BLUE + "Status: ", end = "")

p_output = p_output.strip()
a_output = a_output.strip()
if a_output == "":
    print(Fore.RED + "Cannot Validate")
    say("Cannont Validate")
    exit(0)

p_lines = list(map(str, p_output.split('\n')))
a_lines = list(map(str, a_output.split('\n')))

passed = True

if len(p_lines) != len(a_lines):
    passed = False

if passed:
    for i in range(len(a_lines)):
        if a_lines[i].strip() != p_lines[i].strip():
            passed = False
            break

print(Fore.GREEN + "Samples Passed" if passed else Fore.RED + "Samples Failed")

say("Samples Passed" if passed else "Samples Failed")