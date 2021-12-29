import pyperclip
import sys
sys.path.append("/home/suman/Desktop/Templates")

from C_PLUS_PLUS import *

c_plus_plus_keys = list(c_plus_plus_functions.keys())

function_name = input("Which Function do you need?: ")
function_name = list(map(str, function_name.lower().split()))

function_key = ""

for function in c_plus_plus_keys:
    if all([key_word in function.lower() or key_word in c_plus_plus_functions[function].lower() for key_word in function_name]):
        function_key = function
        break
print("Copied " + function_key + " into clipboard")
pyperclip.copy(c_plus_plus_functions[function_key])
pyperclip.waitForPaste(15)