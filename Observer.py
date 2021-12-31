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
# Use the above two imports instead of sleep() for better performance

from selenium.webdriver.common.by import By

from gtts import gTTS
from os import system
from time import sleep

# Path to Templates, modify this based on your system
path_to_templates = '/home/suman/Competitive-Companion-for-Codechef'

def speak(text: str) -> None:
    object = gTTS(text = text, lang = 'en', slow = False)
    destination_file = path_to_templates + 'Voice.mp3'
    object.save(destination_file)
    system('mpg123 ' + destination_file)
    system('rm ' + destination_file)


def check_status(url: str) -> None:

    # Create an instance of Chrome
    options = webdriver.ChromeOptions()
    # Headless implies no GUI
    options.add_argument('headless')
    driver = webdriver.Chrome(options = options)

    # Open the Profile page of the User
    driver.get(url)
    sleep(4)

    # Get the last submission of the User
    element = driver.find_element(By.XPATH, '//tbody/tr[1]/td[3]/span[1]/img[1]')

    # Get the status of the last submission
    src = element.get_attribute('src')
    if 'tick' in src:
        speak("Your submission has been accepted")
    else:
        speak("Your submission was not accepted")


def start(url: str) -> None:

    # This is the x_path of the last submission of the User
    relative_xpath = "//tbody/tr[1]/td[5]/a[1]"

    # Create an instance of Chrome
    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    driver = webdriver.Chrome(options = options)

    # Open the Profile page of the User
    driver.get(url)
    sleep(4)

    # Get the last submission of the User
    element = driver.find_element(By.XPATH, relative_xpath)
    last_submission = element.get_attribute('href')
    last_submission_id = last_submission.split('/')[-1]

    while True:
        driver.get(url)
        sleep(5)
        element = driver.find_element(By.XPATH, relative_xpath)
        current_submission = element.get_attribute('href')

        # If the last submission has changed, check the status of the submission
        current_submission_id = current_submission.split('/')[-1]
        if current_submission_id != last_submission_id:
            check_status(url)

        last_submission_id = current_submission_id


if __name__ == '__main__':
    # Change the URL to the Profile page of the User
    url = 'https://www.codechef.com/users/suman_18733097'
    start(url)