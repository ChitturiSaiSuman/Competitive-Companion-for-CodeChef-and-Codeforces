# Scrapes a Codeforces contest page
# Creates a folder for the contest
# Extracts samples for each problem in the Contest

import re
from colorama import Fore
from selenium import webdriver
from selenium.webdriver.common.by import By

class Codeforces:
    def __init__(self, contest_link: str) -> None:
        # Contest link is of the form
        # https://www.codeforces.com/contest/<contest_code>
        self.main_page = contest_link
        self.contest_link = contest_link
        if "problems" not in self.contest_link:
            self.contest_link += "/problems"
        
    def __get_contest_name(self, driver: webdriver.Chrome) -> str:
        # Returns the contest name
        print(Fore.YELLOW + "Extracting contest name... ", end = "", flush = True)
        contest_name = driver.find_element(By.CLASS_NAME, 'caption')
        contest_name = contest_name.text
        print(Fore.GREEN + "Done", flush = True)
        print(Fore.YELLOW + "Contest Name: " + Fore.GREEN + contest_name, flush = True)
        return contest_name

    def __get_problem_links(self, num_problems: int) -> str:
        # Returns a list of links to problem pages
        print(Fore.CYAN + "Extracting problem links... ", end = "", flush = True)
        problem_links = []
        alpha = [chr(code) for code in range(65, 91)]
        for i in range(num_problems):
            problem_code = alpha[i]
            problem_link = self.main_page + '/problem/' + problem_code
            problem_links.append(problem_link)
        print(Fore.GREEN + "Done\n", flush = True)
        return problem_links

    def __get_problem_titles(self, driver: webdriver.Chrome) -> str:
        # Returns a list of problem titles
        titles = driver.find_elements(By.CLASS_NAME, 'title')
        titles = [title.text for title in titles]

        problem_titles = []
        for title in titles:
            if title not in ['input\nCopy', 'output\nCopy']:
                problem_titles.append(title.replace(' ', '_').replace('.', ''))

        return problem_titles

    def __get_samples(self, driver: webdriver.Chrome) -> str:
        # This function will return a list of list of tuples
        # [
        #   [input0, output0, input1, output1, ...],
        #   [input0, output0, input1, output1, ...],
        #   ...
        #   [input0, output0, input1, output1, ...],
        # ]
        elements = driver.find_elements(By.TAG_NAME, 'pre')
        num_problems = len(elements)
        samples = []

        for i in range(0, num_problems, 2):
            sample_input = elements[i].text + '\n'
            sample_output = elements[i + 1].text + '\n'
            samples.append([sample_input, sample_output])

        print(Fore.YELLOW + "Extracting samples... " + Fore.GREEN + "Done")
        return samples

    def extract_meta_data(self) -> dict:

        options = webdriver.ChromeOptions()
        options.add_argument('headless')
        driver = webdriver.Chrome(options = options)
        driver.get(self.contest_link)

        # Contest Code
        contest_code = re.findall(r'\d+', self.contest_link)[0]
        # Contest Name
        contest_name = self.__get_contest_name(driver)
        # Problem codes
        problem_codes = self.__get_problem_titles(driver)
        # Problem links
        problem_links = self.__get_problem_links(len(problem_codes))
        # Problem Samples
        problem_samples = self.__get_samples(driver)

        # Problems Meta Data
        meta_data = {}
        meta_data['contest_code'] = contest_code
        meta_data['contest_name'] = contest_name
        meta_data['problem_links'] = problem_links
        meta_data['problem_codes'] = problem_codes
        meta_data['problem_samples'] = problem_samples

        return meta_data


# if __name__ == '__main__':
#     contest = Codeforces('https://codeforces.com/contest/1721')
#     print(contest.extract_meta_data())