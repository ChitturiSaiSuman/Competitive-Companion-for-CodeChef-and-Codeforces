from colorama import Fore, Style

p_out = open("output.out", "r")
a_out = open("out.out", "r")

p_output = p_out.read()
a_output = a_out.read()

p_out.close()
a_out.close()

print(Fore.BLUE+"Status: ", end = "")

p_output = p_output.strip()
a_output = a_output.strip()
if a_output == "":
    print(Fore.RED + "Validation Failed")
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

print(Fore.GREEN + "Pre-Tests Passed" if passed else Fore.RED + "Pre-Tests Failed")