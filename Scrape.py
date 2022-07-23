#!/usr/bin/env python3

# Scrapes a Codechef's contest page
# Creates a folder for the contest
# Extracts samples for each problem in the Contest

import os
import shutil
import datetime
import concurrent.futures
from colorama import Fore

from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By

const_path_to_templates = '/home/suman/Competitive-Companion-for-Codechef'

def get_samples(problem_link: str) -> list:
    # Given the link to the problem page
    # This function will return a list of strings
    # [input0, output0, input1, output1, ...]
    # Probably doesn't work for interactive problems

    xpath = "//body/div[@id='ember-root']/div[@id='ember242']/div[@id='ember251']/main[@id='content-regions']/section[1]/div[1]/span[3]/pre[1]"
    # xpath of the sample test cases

    xpath_prefix = "/html[1]/body[1]/div[1]/div[1]/div[1]/div[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[2]/div[1]/div[1]/div[2]/div[1]/div["
    xpath_suffix_1 = "]/div[2]/div[1]/pre[1]"
    xpath_suffix_2 = "]/div[2]/div[2]/pre[1]"

    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    driver = webdriver.Chrome(options = options)
    # Headless Chrome driver
    # Runs in background, doesn't open a Chrome window

    try:
        driver.get(problem_link)
        element = WebDriverWait(driver, 50).until(EC.presence_of_all_elements_located((By.CLASS_NAME, "_input_output__table_lulsq_184")))
    except:
        print(Fore.RED + "Error extracting samples from " + problem_link)
        return []

    samples = []
    i = 2

    # iterate for multiple test cases
    while True:
        absolute_xpath_1 = xpath_prefix + str(i) + xpath_suffix_1
        absolute_xpath_2 = xpath_prefix + str(i) + xpath_suffix_2
        try:
            element = driver.find_element(By.XPATH, absolute_xpath_1)
            samples.append(element.get_attribute('innerHTML'))
            element = driver.find_element(By.XPATH, absolute_xpath_2)
            samples.append(element.get_attribute('innerHTML'))
            i += 1
        except:
            break

    driver.quit()
    print(Fore.YELLOW + "Extracting samples for " + problem_link + "... " + Fore.GREEN + "Done")
    return samples


def extract_problem_links(contest_link: str) -> list:
    # Given a link to a contest page
    # Returns a list of links to problem pages

    print(Fore.CYAN + "Extracting problem links... ", end = "", flush = True)
    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    driver = webdriver.Chrome(options = options)

    prefix = contest_link

    if "?" in contest_link:
        prefix = contest_link[:contest_link.index("?")]

    prefix += "/problems"

    driver.get(contest_link)

    # Wait until the problem links appear on the contest page
    element = WebDriverWait(driver, 50).until(EC.presence_of_all_elements_located((By.CLASS_NAME, "dataTable")))

    all_links = driver.find_elements(By.TAG_NAME, 'a')

    problem_links = []

    for link in all_links:
        try:
            link = str(link.get_attribute('href'))
            # A problem link is of the form:
            # https://www.codechef.com/<contest_code>/problems/<problem_code>
            if link.startswith(prefix):
                if problem_links != [] and problem_links[-1] == link:
                    continue
                problem_links.append(link)
        except:
            # Probably the contest has not started yet
            # or there is issue loading problems on the page

            print(Fore.RED + "Attempt to Extract failed. Retrying... ", flush = True)
            return []
    
    driver.quit()
    if problem_links == []:
        # Probably the contest has not started yet
        # or there is issue loading problems on the page
        print(Fore.RED + "Attempt to Extract failed. Retrying... ", flush = True)
        return []
    print(Fore.GREEN + "Done\n", flush = True)
    return problem_links


def get_contest_name(contest_link: str) -> str:
    # Given a contest link
    # Returns the contest name

    print(Fore.YELLOW + "Extracting contest name... ", end = "", flush = True)
    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    driver = webdriver.Chrome(options = options)
    driver.get(contest_link)

    element = WebDriverWait(driver, 50).until(EC.presence_of_all_elements_located((By.CLASS_NAME, "breadcrumbs")))
    element = driver.find_element(By.CLASS_NAME, 'breadcrumbs')
    inner_text = element.get_attribute('innerHTML')

    contest_name = inner_text[inner_text.rindex(";") + 1:].strip()
    driver.quit()
    print(Fore.GREEN + "Done", flush = True)
    print(Fore.YELLOW + "Contest Name: " + Fore.GREEN + contest_name, flush = True)
    return contest_name

def get_problem_codes(problem_links: list) -> list:

    # Given a list of problem links
    # Returns a list of problem codes

    problem_codes = []
    for link in problem_links:
        code = link[link.rindex('/') + 1:]
        problem_codes.append(code)
    
    return problem_codes


def extract_meta_data(contest_link: str) -> dict:

    # Contest Code
    contest_code = ""
    if "?" in contest_link:
        contest_code = contest_link[contest_link.rindex("/") + 1: contest_link.index("?")]
    else:
        contest_code = contest_link[contest_link.rindex("/") + 1:]

    # Contest Name
    contest_name = get_contest_name(contest_link)

    # Problem links
    problem_links = []
    while problem_links == []:
        problem_links = extract_problem_links(contest_link)

    # Problem Codes
    problem_codes = get_problem_codes(problem_links)

    # Problem Samples
    # Uses multi-threading concept to speed up the process
    # Creates N number of threads, where N is the number of problems
    # N = |Scorable problems| + |Non-scorable problems|

    with concurrent.futures.ThreadPoolExecutor(max_workers = len(problem_links)) as executor:
        results = executor.map(get_samples, problem_links)

    problem_samples = list(results)

    # Problem Meta Data
    meta_data = {}
    meta_data['contest_code'] = contest_code
    meta_data['contest_name'] = contest_name
    meta_data['problem_links'] = problem_links
    meta_data['problem_codes'] = problem_codes
    meta_data['problem_samples'] = problem_samples

    return meta_data

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
        # print(Fore.YELLOW + "Copying " + file + "...", end = "", flush = True)
        shutil.copy(path_to_templates + "/" + file, path_to_problem)
        # print(Fore.GREEN + "Done", flush = True)
    # print()

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
            header += "Scraped using https://github.com/ChitturiSaiSuman/Competitive-Companion-for-Codechef\n" + '*/\n'
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
    meta_data = extract_meta_data(contest_link)
    meta_data['time'] = now_str

    initialise_workplace(meta_data)

    # os.system("clear")

    total_time = "%.0f" % (datetime.datetime.now() - now).total_seconds()
    
    print(Fore.YELLOW + "\nScrape time: " + Fore.GREEN + "" + total_time + " seconds\n" + Fore.WHITE)

    # Run the Observer in the background
    os.system('python3 ' + const_path_to_templates + '/Observer.py')

def general():
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
    choice = input("Do you want to scrape a Codechef contest? (Y/N) ")
    if choice in "yesYesYES":
        codechef_scraper()
    else:
        general()