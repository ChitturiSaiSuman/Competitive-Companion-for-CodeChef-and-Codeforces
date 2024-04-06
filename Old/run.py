from colorama import *
from os import listdir, remove
from pyttsx3 import *
from sys import *
from subprocess import *
from time import *

# Judge Environment Variables
# Override this to change time limit (in seconds)
time_limit = 2
# Override this to change memory limit (kB)
memory_limit = 10**6
# Override this to change Clock Speed (hertz)
max_boost_speed = 3 * 10**9

# Multipliers for popular languages
c_time_limit = time_limit
cpp_time_limit = time_limit
java_time_limit = 2 * time_limit
python_time_limit = 5 * time_limit
pypy_time_limit = 2 * time_limit

def get_cl_args() -> tuple:
    program_to_be_executed = argv[1]
    online_judge = not(len(argv) > 2)
    return (program_to_be_executed, online_judge)

def read_tests() -> tuple:
    stdin = ""
    with open("input.in", "r") as opened_file:
        stdin += opened_file.read()
    expected = ""
    with open("output.out", "r") as opened_file:
        expected += opened_file.read()
    return (stdin, expected)

def say(word: str) -> None:
    speaker = Engine()
    speaker.setProperty('rate', 175)
    speaker.say(word)
    speaker.runAndWait()

def delete_data() -> None:
    for file in listdir():
        if "exe" in file or ".class" in file or ".obj" in file:
            remove(file)

def parse_streams(stdin: str, stdout: str, stderr: str) -> None:
    if len(stdin) > 1000:
        print(Fore.RED + "Large STDIN")
    else:
        print(Fore.BLUE + "STDIN:")
        print(Fore.WHITE + stdin)
    
    if len(stdout) > 1000:
        print(Fore.RED + "Large STDOUT")
    else:
        print(Fore.BLUE + "STDOUT:")
        print(Fore.WHITE + stdout)

    if len(stderr) > 1000:
        print(Fore.RED + "Large STDERR")
    else:
        print(Fore.BLUE + "STDERR:")
        print(Fore.WHITE + stderr)

def judge_submission(stdin: str, stdout: str, stderr: str, expected_output: str, execution_time: float, submission_time_limit: float) -> None:

    parse_streams(stdin, stdout, stderr)
    print(Fore.CYAN + "Time: %.6f\n"%(execution_time) + Fore.WHITE)

    runtime_error = False
    keywords = ['exception', 'traceback', 'segmentation fault', 'line']
    stderr = stderr.lower()
    for keyword in keywords:
        if keyword in stderr:
            runtime_error = True

    if runtime_error:
        print(Fore.CYAN + "Verdict: ", end = "")
        print(Fore.RED + "Runtime Error")
        say("Run time Exception")

    elif expected_output == "":
        print(Fore.RED + "Cannot Validate")
        say("Cannot Validate")

    elif execution_time > submission_time_limit:
        print(Fore.CYAN + "Verdict: ", end = "")
        print(Fore.RED + "Time limit exceeded")
        say("Time limit exceeded")

    else:
        passed = True
        p_lines = list(map(str, stdout.strip().split('\n')))
        a_lines = list(map(str, expected_output.strip().split('\n')))

        if len(p_lines) != len(a_lines):
            passed = False

        if passed:
            for i in range(len(a_lines)):
                if a_lines[i].strip() != p_lines[i].strip():
                    passed = False
                    break

        print(Fore.CYAN + "Verdict: ", end = "")
        print(Fore.GREEN + "Samples Passed" if passed else Fore.RED + "Samples Failed")
        say("Samples Passed" if passed else "Samples Failed")


def run_java(program_to_be_executed: str, online_judge: bool, stdin: str, expected: str) -> None:
    javac_version = run(['javac', '--version'], stdout = PIPE).stdout.decode().strip()
    java_version = run(['java', '--version'], stdout = PIPE).stdout.decode().strip()
    java_version = list(map(str, java_version.split('\n')))[0]

    print(Fore.YELLOW + "Compiling Using Compiler " + javac_version)
    compilation_log = run(['javac', program_to_be_executed], capture_output = True, text = True).stderr.strip()

    if compilation_log:
        print(Fore.RED + "Compilation failed due to following errors")
        say("Compie lation failed")
        print(Fore.CYAN + compilation_log)
    else:
        print(Fore.GREEN + "Compiled Successfully. ", end = "")
        print(Fore.YELLOW + "Now Running Main using JVM " + java_version)
        execution_log = None

        if online_judge:
            memory_string = str(memory_limit)
            speed_string = str(max_boost_speed)
            start_time = time()
            execution_log = run(['perl', 'timeout', '-t', str(java_time_limit), '-m', memory_string, '-x', speed_string, 'java', 'Main'], capture_output = True, text = True, input = stdin, check = True)
            end_time = time()
            stdout = execution_log.stdout.strip()
            stderr = execution_log.stderr.strip()
            stderr = '\n'.join(list(map(str, stderr.split('\n')))[:-1])
            judge_submission(stdin, stdout, stderr, expected, end_time - start_time, java_time_limit)

        else:
            memory_string = str(memory_limit)
            speed_string = str(max_boost_speed)
            start_time = time()
            execution_log = run(['perl', 'timeout', '-m', memory_string, '-x', speed_string, 'java', 'Main'], capture_output = True, text = True, input = stdin, check = True)
            end_time = time()
            stdout = execution_log.stdout.strip()
            stderr = execution_log.stderr.strip()
            stderr = '\n'.join(list(map(str, stderr.split('\n')))[:-1])
            judge_submission(stdin, stdout, stderr, expected, end_time - start_time, java_time_limit)



def run_cpp(program_to_be_executed: str, online_judge: bool, stdin: str, expected: str) -> None:
    cpp_version = run(['g++', '--version'], stdout = PIPE).stdout.decode().strip()
    cpp_version = list(map(str, cpp_version.split('\n')))[0].strip()

    print(Fore.YELLOW + "Compiling Using Compiler " + cpp_version)
    compilation_log = run(['g++', '-DSUMAN', '-std=c++17', '-Wshadow', '-Wall', '-o', 'exe', program_to_be_executed, '-O2', '-Wno-unused-result'], capture_output = True, text = True).stderr.strip()

    if compilation_log:
        print(Fore.RED + "Compilation failed due to following errors")
        say("Compie lation failed")
        print(Fore.CYAN + compilation_log)
    else:
        print(Fore.GREEN + "Compiled Successfully. ", end = "")
        print(Fore.YELLOW + "Now Running Executable\n")
        execution_log = None

        if online_judge:
            memory_string = str(memory_limit)
            speed_string = str(max_boost_speed)
            start_time = time()
            execution_log = run(['perl', 'timeout', '-t', str(cpp_time_limit), '-m', memory_string, '-x', speed_string, './exe'], capture_output = True, text = True, input = stdin, check = True)
            end_time = time()
            stdout = execution_log.stdout.strip()
            stderr = execution_log.stderr.strip()
            stderr = '\n'.join(list(map(str, stderr.split('\n')))[:-1])
            judge_submission(stdin, stdout, stderr, expected, end_time - start_time, cpp_time_limit)

        else:
            memory_string = str(memory_limit)
            speed_string = str(max_boost_speed)
            start_time = time()
            execution_log = run(['perl', 'timeout', '-m', memory_string, '-x', speed_string, './exe'], capture_output = True, text = True, input = stdin, check = True)
            end_time = time()
            stdout = execution_log.stdout.strip()
            stderr = execution_log.stderr.strip()
            stderr = '\n'.join(list(map(str, stderr.split('\n')))[:-1])
            judge_submission(stdin, stdout, stderr, expected, end_time - start_time, cpp_time_limit)


def run_c(program_to_be_executed: str, online_judge: bool, stdin: str, expected: str) -> None:
    c_version = run(['gcc', '--version'], stdout = PIPE).stdout.decode().strip()
    c_version = list(map(str, c_version.split('\n')))[0].strip()

    print(Fore.YELLOW + "Compiling Using Compiler " + c_version)
    compilation_log = run(['gcc', '-o', 'exe', program_to_be_executed, '-lm'], capture_output = True, text = True).stderr.strip()

    if compilation_log:
        print(Fore.RED + "Compilation failed due to following errors")
        say("Compie lation failed")
        print(Fore.CYAN + compilation_log)
    else:
        print(Fore.GREEN + "Compiled Successfully. ", end = "")
        print(Fore.YELLOW + "Now Running Executable\n")
        execution_log = None

        if online_judge:
            memory_string = str(memory_limit)
            speed_string = str(max_boost_speed)
            start_time = time()
            execution_log = run(['perl', 'timeout', '-t', str(c_time_limit), '-m', memory_string, '-x', speed_string, './exe'], capture_output = True, text = True, input = stdin, check = True)
            end_time = time()
            stdout = execution_log.stdout.strip()
            stderr = execution_log.stderr.strip()
            stderr = '\n'.join(list(map(str, stderr.split('\n')))[:-1])
            judge_submission(stdin, stdout, stderr, expected, end_time - start_time, c_time_limit)

        else:
            memory_string = str(memory_limit)
            speed_string = str(max_boost_speed)
            start_time = time()
            execution_log = run(['perl', 'timeout', '-m', memory_string, '-x', speed_string, './exe'], capture_output = True, text = True, input = stdin, check = True)
            end_time = time()
            stdout = execution_log.stdout.strip()
            stderr = execution_log.stderr.strip()
            stderr = '\n'.join(list(map(str, stderr.split('\n')))[:-1])
            judge_submission(stdin, stdout, stderr, expected, end_time - start_time, c_time_limit)

def run_python(program_to_be_executed: str, online_judge: bool, stdin: str, expected: str) -> None:
    python_version = run(['python3', '--version'], capture_output = True, text = True).stdout.strip()
    print(Fore.YELLOW + "Using Interpretor " + python_version)

    if online_judge:
        memory_string = str(memory_limit)
        speed_string = str(max_boost_speed)
        start_time = time()
        execution_log = run(['perl', 'timeout', '-t', str(python_time_limit), '-m', memory_string, '-x', speed_string, 'python3', program_to_be_executed], capture_output = True, text = True, input = stdin, check = True)
        end_time = time()
        stdout = execution_log.stdout.strip()
        stderr = execution_log.stderr.strip()
        stderr = '\n'.join(list(map(str, stderr.split('\n')))[:-1])
        judge_submission(stdin, stdout, stderr, expected, end_time - start_time, python_time_limit)

    else:
        memory_string = str(memory_limit)
        speed_string = str(max_boost_speed)
        start_time = time()
        execution_log = run(['perl', 'timeout', '-m', memory_string, '-x', speed_string, 'python3', program_to_be_executed], capture_output = True, text = True, input = stdin, check = True)
        end_time = time()
        stdout = execution_log.stdout.strip()
        stderr = execution_log.stderr.strip()
        stderr = '\n'.join(list(map(str, stderr.split('\n')))[:-1])
        judge_submission(stdin, stdout, stderr, expected, end_time - start_time, python_time_limit)

def execute(program_to_be_executed, online_judge):
    print(Fore.MAGENTA + "Running " + program_to_be_executed)
    stdin, expected = read_tests()

    if ".java" in program_to_be_executed:
        run_java(program_to_be_executed, online_judge, stdin, expected)
    elif ".cpp" in program_to_be_executed:
        run_cpp(program_to_be_executed, online_judge, stdin, expected)
    elif ".c" in program_to_be_executed:
        run_c(program_to_be_executed, online_judge, stdin, expected)
    elif ".py" in program_to_be_executed:
        run_python(program_to_be_executed, online_judge, stdin, expected)


if __name__ == '__main__':
    run(['clear'])
    args = get_cl_args()
    execute(args[0], args[1])
    delete_data()