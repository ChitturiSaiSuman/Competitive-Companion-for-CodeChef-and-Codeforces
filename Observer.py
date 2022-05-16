#!/usr/bin/env python3
# A program that observes the Profile page of User

# Works based on the following logic:
# 1. Open the Profile page of the User
# 2. Get the last submission of the User
# 3. Refreshes the page and checks if the last submission has changed
# 4. If the last submission has changed, check the status of the submission
# 5. If the status is accepted, speak the message "Your submission has been accepted"
# 6. If the status is not accepted, speak the message "Your submission was not accepted"
# 7. Repeat steps 3-6

from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By

from time import sleep
from gtts import gTTS
from playsound import playsound
from os import remove
import sys

# Constants:
# Path to Templates, modify this based on your system
path_to_templates = '/home/suman/Competitive-Companion-for-Codechef'
sys.path.append(path_to_templates)

# This is the x_path of the last submission of the User
relative_xpath = "/html[1]/body[1]/main[1]/div[1]/div[1]/div[1]/aside[1]/div[2]/div[1]/div[1]/div[1]/table[1]/tbody[1]/tr[1]"

from Submission import *

# Speech synthesis for Accepted Submission
accepted = 'Your submission has been accepted'
processing = 'Your submissions is being processed'
rejected = 'Your submission was not accepted'

def speak(text: str) -> None:
    object = gTTS(text = text, lang = 'en', slow = False)
    destination_file = path_to_templates + '/Voice.mp3'
    object.save(destination_file)
    print(text, flush = True)
    playsound(destination_file)
    remove(destination_file)

def check_status(submission: Submission) -> None:
    verdict = submission.verdict
    if verdict == 'AC':
        speak(accepted)
    elif verdict == 'NA':
        speak(processing)
        sleep(5)
        check_status(submission)
    else:
        speak(rejected)

def get_submission_stack(url: str) -> list:
    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    driver = webdriver.Chrome(options = options)
    driver.get(url)

    stack = []

    for i in range(1, 13):
        path = relative_xpath[:-2] + str(i) + ']'
        element = WebDriverWait(driver, 100).until(EC.presence_of_all_elements_located((By.XPATH, path)))[0]
        submission = element.get_attribute('innerHTML')
        submission = parse_submission(submission)
        stack.append(submission)
    
    return stack

def start(url: str) -> None:
    old_stack = get_submission_stack(url)
    print("List of Submissions: ", flush = True)
    print(*old_stack, sep = '\n', flush = True, end = '\n\n')
    while True:
        new_stack = get_submission_stack(url)
        if any(new_stack[i] == old_stack[i] for i in range(len(new_stack))):
            sleep(10)
            continue
        print("New Submission Detected. Details:", new_stack[-1], flush = True)
        check_status(new_stack[-1])
        old_stack = new_stack


if __name__ == '__main__':
    # Change the URL to the Profile page of the User
    url = 'https://www.codechef.com/users/suman_18733097'
    start(url)