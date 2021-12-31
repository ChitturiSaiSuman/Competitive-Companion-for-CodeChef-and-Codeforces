#!/usr/bin/env python3

from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By

from gtts import gTTS
from os import system
from time import sleep

def speak(text: str) -> None:
    object = gTTS(text = text, lang = 'en', slow = False)
    object.save('/home/suman/Desktop/Templates/voice.mp3')
    system('mpg123 /home/suman/Desktop/Templates/voice.mp3')
    system('rm /home/suman/Desktop/Templates/voice.mp3')


def check_status(url):
    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    driver = webdriver.Chrome(options = options)

    driver.get(url)
    sleep(4)

    element = driver.find_element(By.XPATH, '//tbody/tr[1]/td[3]/span[1]/img[1]')
    href = element.get_attribute('src')
    if 'tick' in href:
        speak("Your submission has been accepted")
    else:
        speak("Your submission was not accepted")


def start(url):
    relative_xpath = "//tbody/tr[1]/td[5]/a[1]"

    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    driver = webdriver.Chrome(options = options)

    driver.get(url)
    sleep(4)
    element = driver.find_element(By.XPATH, relative_xpath)
    last_submission = element.get_attribute('href')
    last_submission_id = last_submission.split('/')[-1]

    while True:
        driver.get(url)
        sleep(5)
        element = driver.find_element(By.XPATH, relative_xpath)
        current_submission = element.get_attribute('href')
        current_submission_id = current_submission.split('/')[-1]
        if current_submission_id != last_submission_id:
            check_status(url)

        last_submission_id = current_submission_id


if __name__ == '__main__':
    url = 'https://www.codechef.com/users/suman_18733097'
    start(url)