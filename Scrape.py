#!/usr/bin/env python3

# Scrapes a Codechef's contest page
# Creates a folder for the contest
# Extracts samples for each problem in the Contest

import os
import shutil
import datetime
from colorama import Fore
from Codechef import Codechef
from Codeforces import Codeforces

const_path_to_templates = '/home/suman/Competitive-Companion-for-CodeChef-and-Codeforces'


def copy_default_files(path_to_problem, path_to_templates) -> None:
    # Use this to copy templates to the Workplace folder
    print()

    # Default.cpp : Default tempalte for C++
    # Extended.cpp: Consists of all utility functions for faster reference
    # Generator.cpp: C++ Program to generate test cases for test purpose
    # Test.cpp: C++ Program to write Bruteforce solution
    # Custom_Judge.py: Judge for problems that allow printing any valid answer

    files_needed = ['Default.cpp', 'Extended.cpp', 'Generator.cpp', 'Test.cpp']
    files_needed += ['DEBUG.h', 'Custom_Judge.py', 'STDIN', 'STDEXPOUT']

    for file in files_needed:
        shutil.copy(path_to_templates + "/" + file, path_to_problem)

def create_problem(path_to_workplace: str, default_source: str, header: str, problem_link: str, problem_code: str, test_cases: list) -> None:

    # Creates files neccessary for a problem in the Workplace folder
    # Files include: <problem_code>.cpp, <problem_code>_00.in, <problem_code>_00.out
    # <problem_code>_01.in, <problem_code>_01.out, ...

    # Create a folder for the problem
    path_to_problem = path_to_workplace + "/" + problem_code
    try:
        os.makedirs(path_to_problem)
    except:
        # Folder already exists
        pass

    global const_path_to_templates

    copy_default_files(path_to_problem, const_path_to_templates)

    path_to_file = path_to_problem + "/Solution.cpp"
    print(Fore.YELLOW + "Creating files for " + problem_code + "... ", end = "", flush = True)

    if not os.path.exists(path_to_file):
        with open(path_to_file, 'w') as file:
            problem_link = "Problem: " + problem_link + "\n"
            header = '/*\n' + header + problem_link + '\n'
            header += "Scraped using https://github.com/ChitturiSaiSuman/Competitive-Companion-for-CodeChef-and-Codeforces\n" + '*/\n'
            source_code = header + default_source
            file.write(source_code)

    # Creates test cases

    for i in range(len(test_cases)):
        test_case = test_cases[i]
        sample_input = test_case[0]
        sample_output = test_case[1]

        input_file = path_to_problem + "/" + "Case_" + str(i).zfill(2) + ".in"
        with open(input_file, 'w') as file:
            file.write(sample_input)

        output_file = path_to_problem + "/" + "Case_" + str(i).zfill(2) + ".out"
        with open(output_file, 'w') as file:
            file.write(sample_output)

    try:

        shutil.copy(path_to_problem + "/Case_00.in", path_to_problem + "/STDIN")
        shutil.copy(path_to_problem + "/Case_00.out", path_to_problem + "/STDEXPOUT")
    
    except:
        print(Fore.RED + "Error: No proper Samples found for " + problem_code, flush = True)
    
    print(Fore.GREEN + "Done", flush = True)
    

def parse_test_cases(test_cases: list, problem_code: str) -> list:
    # Given is a list of strings
    # [input0, output0, input1, output1, ...]
    # Returns list of tuples
    # With input and output zipped
    # [(input0, output0), (input1, output1), ...]
    parsed_test_cases = []
    for i in range(0, len(test_cases), 2):
        try:
            parsed_test_cases.append((test_cases[i], test_cases[i + 1]))
        except:
            # Probably because it's interactive problem
            print(Fore.RED + "Error in parsing test cases for " + problem_code)
    return parsed_test_cases

def initialise_workplace(meta_data: dict) -> None:

    # Header to include in the source code
    # Modify it as needed

    header = "Author: Sai Suman Chitturi" + "\n"
    header += "Powered by: Amazon CodeWhisperer" + "\n"
    header += "Created: " + meta_data['time'] + "\n"
    header += "Contest: " + meta_data['contest_name'] + "\n"

    # Path to Workplace, modify it as needed
    path_to_workplace = '/home/suman/' + meta_data['contest_code']

    path_to_templates = const_path_to_templates

    print(Fore.YELLOW + "\nCreating workplace " + path_to_workplace + "...\n", flush = True)

    try:
        os.makedirs(path_to_workplace)
    except:
        pass

    # Template is named Default.cpp
    default_source = ""
    with open(path_to_templates + "/Default.cpp", 'r') as file:
        default_source += file.read()

    # Create files for all contest problems
    for i in range(len(meta_data['problem_codes'])):
        problem_link = meta_data['problem_links'][i]
        problem_code = meta_data['problem_codes'][i]
        test_cases = meta_data['problem_samples'][i]
        test_cases = parse_test_cases(test_cases, problem_code)
        create_problem(path_to_workplace, default_source, header, problem_link, problem_code, test_cases)

    print()

    # Open the Workplace folder in Visual Studio Code
    print(Fore.YELLOW + "Opening " + path_to_workplace + " in Code... ", end = "", flush = True)
    os.system("code " + path_to_workplace)
    print(Fore.GREEN + "Done" + Fore.WHITE, flush = True)


def codechef_scraper():
    contest_link = input(Fore.YELLOW + "Enter Contest Link: " + Fore.WHITE)

    now = datetime.datetime.now()
    now_str = str(now.strftime("%Y-%m-%d %H:%M:%S"))

    print()
    contest = Codechef(contest_link)
    meta_data = contest.extract_meta_data()
    meta_data['time'] = now_str

    initialise_workplace(meta_data)

    total_time = "%.0f" % (datetime.datetime.now() - now).total_seconds()
    
    print(Fore.YELLOW + "\nScrape time: " + Fore.GREEN + "" + total_time + " seconds\n" + Fore.WHITE)

    # Run the Observer in the background
    # os.system('python3 ' + const_path_to_templates + '/Observer.py')

def codeforces_scraper():
    contest_link = input(Fore.YELLOW + "Enter Contest Link: " + Fore.WHITE)

    now = datetime.datetime.now()
    now_str = str(now.strftime("%Y-%m-%d %H:%M:%S"))

    print()
    contest = Codeforces(contest_link)
    meta_data = contest.extract_meta_data()
    meta_data['time'] = now_str

    initialise_workplace(meta_data)

    total_time = "%.0f" % (datetime.datetime.now() - now).total_seconds()
    
    print(Fore.YELLOW + "\nScrape time: " + Fore.GREEN + "" + total_time + " seconds\n" + Fore.WHITE)

def generic():
    contest_name = input("Contest Name: ")
    n = int(input("Number of Problems: "))

    now = datetime.datetime.now()
    now_str = str(now.strftime("%Y-%m-%d %H:%M:%S"))

    meta_data = {}
    meta_data['time'] = now_str
    meta_data['contest_code'] = os.path.join(contest_name.replace(' ', '_'))
    meta_data['contest_name'] = contest_name
    meta_data['problem_links'] = ['NA'] * n
    meta_data['problem_codes'] = [str(i) for i in range(1, n + 1)]
    meta_data['problem_samples'] = [[] for _ in range(n)]

    initialise_workplace(meta_data)

if __name__ == '__main__':
    os.system("clear")
    print("Select one among the following")
    print("1. CodeChef")
    print("2. Codeforces")
    print("3. Generic Contest")

    choice = input("Enter your input: ")
    if choice == "1":
        codechef_scraper()
    elif choice == "2":
        codeforces_scraper()
    else:
        generic()