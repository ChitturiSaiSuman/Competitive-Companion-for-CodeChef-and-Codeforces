import os
import concurrent.futures
import time

from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By

def get_code(link: str) -> None:
    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    driver = webdriver.Chrome(options = options)

    submission_id = link.split('/')[-1]
    driver.get(link)
    code = driver.find_element(By.XPATH, "//div[@class='ace_content']").text
    language = driver.find_element(By.XPATH, "/html[1]/body[1]/main[1]/div[1]/section[1]/div[1]/section[1]/aside[1]/div[1]/div[1]/div[1]").text
    language = language[language.index(' ') + 1: ]

    driver.close()
    return (submission_id, language, code)

def download_submissions(submission_links: list, problem_code: str) -> None:
    try:
        os.makedirs(problem_code)
    except:
        pass

    extensions = {
        'C++14': '.cpp',
        'C': '.c',
        'JAVA': '.java',
        'PYTH 3.6': '.py',
        'C++17': '.cpp',
        'PYTH': '.py',
        'PYPY3': '.py',
        'PYPY': '.py',
    }
    with concurrent.futures.ThreadPoolExecutor(max_workers = 8) as executor:
        results = executor.map(get_code, submission_links)
        results = list(results)
        for result in results:
            submission_id, language, code = result
            try:
                language = extensions[language]
            except:
                language = '.txt'
            path_to_file = os.path.join(problem_code, submission_id + language)
            with open(path_to_file, 'w') as f:
                f.write(code)


def get_submission_links(page: str) -> list:
    print("Extracting Submission links from " + page)
    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    driver = webdriver.Chrome(options = options)
    driver.get(page)

    all_links = driver.find_elements(By.TAG_NAME, 'a')
    sub_str = '/viewsolution/'

    submission_links = []
    for link in all_links:
        link = str(link.get_attribute('href'))
        if sub_str in link:
            submission_links.append(link)

    driver.close()
    return submission_links

if __name__ == '__main__':
    try:
        # Read the URL of submissions page from user
        # The URL is of the form 
        # https://www.codechef.com/<contest_code>/status/<problem_code>

        print("Enter a URL of the following kind")
        print("https://www.codechef.com/<contest_code>/status/<problem_code>")
        main_page = input()
        problem_code = input("Enter Problem Code: ")
        print()

        start_index = int(input("Enter the first page number: "))
        end_index = int(input("Enter the last page number: "))
        print('\n')
        
        start_time = time.time()

        for index in range(start_index, end_index):
            try:
                page_start_time = time.time()
                page = main_page + '?page=' + str(index) + "&sort_by=All&sorting_order=asc&language=All&status=FullAC&handle=&Submit=GO"
                submission_links = get_submission_links(page)
                download_submissions(submission_links, problem_code)
                print("Downloaded " + str(len(submission_links)) + " submissions from page " + str(index), flush = True)
                print("Time: %.0f" %(time.time() - page_start_time), flush = True)
                print(flush = True)
            except Exception as e:
                print('\n')
                print("Failed at page " + str(index))
                print("Exception: ", repr(e), ".", sep = "")
                print("Please retry after some time")
                print('\n')
                break
            
        print("Total time: %.0f seconds" % (time.time() - start_time))
    except KeyboardInterrupt:
        print("\n\n")
        print("Process was interrupted")
        print("--- %s seconds ---" % (time.time() - start_time))