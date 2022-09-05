import sys
import json
import pyperclip

def read_json():
    path_to_templates = '/home/suman/Competitive-Companion-for-CodeChef-and-Codeforces/'
    with open(path_to_templates + 'CPP.json') as file:
        data = json.load(file)
    return data

def load_dict(data):
    c_plus_plus_functions = {}
    for snippet in data:
        keys = [snippet]
        prefix = data[snippet]['prefix']
        if isinstance(prefix, list):
            prefix = ' '.join(prefix)
        keys.append(prefix)
        keys.append(data[snippet]['description'])
        keys = ' '.join(keys)

        value = data[snippet]['body']
        value = '\n'.join(value)

        c_plus_plus_functions[keys] = value
    return c_plus_plus_functions

def query(snippets: dict):
    keys = list(snippets.keys())
    function_name = input("Which Function do you need?: ")
    function_name = list(map(str, function_name.lower().split()))
    function_key = ""
    for function in keys:
        if all([key_word in function.lower() or key_word in snippets[function].lower() for key_word in function_name]):
            function_key = function
            break

    if function_key == "":
        print("No Match Found")
        sys.exit()

    print("Copied " + ' '.join(function_name) + " into clipboard")
    pyperclip.copy(snippets[function_key])
    pyperclip.waitForPaste(15)


if __name__ == '__main__':
    data = read_json()
    c_plus_plus_functions = load_dict(data)
    query(c_plus_plus_functions)