# Competitive Companion for Codechef

**Automatically Scrape Test Cases for Codechef Contest problems. Also has a built-in judge that can Judge Solutions against Samples**

## 1. Introduction

Competetive Companion is a Python Script that can be used to scrape test cases for Codechef Contest problems. It also has a built-in judge that can Judge Solutions against Samples.

## 2. Usage

```
# Runs only on Linux based systems
# Run the following commands in a terminal:

# Clone the repository
git clone https://github.com/ChitturiSaiSuman/Competitive-Companion-for-Codechef.git

# Change directory to the repository
cd Competitive-Companion-for-Codechef

# Run the application
python3 Scrape.py

# Enter the link to a Codechef Contest
# Example: https://www.codechef.com/contests/DEC21A
```

## 3. Dependencies

* Selenium is the backbone of the application. Install selenium using the following command.
```
pip install selenium
```
* gtts (google text to speech) is used for speech synthesis. Install gtts using the following command.
```
pip install gTTS
```
* Colorama is used for colored output. Install coloroma using the following command.
```
pip install coloroma
```
* There are several other dependencies that are not listed here.
* Moreover, this is designed to work on Linux based systems.
* Post Scraping, a VS Code Workplace is lauched for you.

## 4. My Settings

* Open a terminal and run the following commands to set up aliases for Ubuntu.
```
# Open bashrc file
nano ~/.bashrc
# Add the following lines at the beginning of the file

alias run="bash /home/<user_name>/Competitive-Companion-for-Codechef/RUN_CPP.sh"
alias stress="bash /home/<user_name>/Competitive-Companion-for-Codechef/STRESS.sh"
alias debug="bash /home/<user_name>/Competitive-Companion-for-Codechef/DEBUG.sh"
alias clip="python3 /home/<user_name>/Competitive-Companion-for-Codechef/Snippet_Copier.py"

# Save the file using CTRL + O and then Y
# Exit nano using CTRL + X

# Now, run the following command to reload the aliases
source ~/.bashrc

# Aliases help quick access to frequently used commands.

# For example, to run any CPP Script in the current directory, run the following command.
run <file_name>.cpp
# This will run the CPP Script against STDIN file.

# To Stress test a buggy CPP Script against a Correct Solution, run the following command.
stress <buggy_solution_file_name>.cpp <correct_solution_file_name>.cpp
# You can also swap the order of the two files.
stress <correct_solution_file_name>.cpp <buggy_solution_file_name>.cpp
# Make sure that the file named Generator.cpp is present in the current directory.

# To Debug Solutions that are giving Runtime Errors, run the following command.
debug <file_name>.cpp

# To copy a snippet from a file to the clipboard, run the following command.
clip
# This will ask you to enter keywords so that you can access readymade templates from the clipboard.

```

## 5. Extension
Interested Users can create a pull-request and extend the project for implementing other features (or eliminate existing bugs) as well.

### Don't forget to Star the repository if you like it.
