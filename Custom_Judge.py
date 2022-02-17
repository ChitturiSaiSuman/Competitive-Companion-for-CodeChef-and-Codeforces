import os, sys

# The first argument must be the path 
# to the Correct Submission if do_stress is True
do_stress = False
limit = 100

def custom_judge(stdin: list, stdout: list, stdexpout: list) -> bool:
    # Default Judge
    if len(stdout) != len(stdexpout):
        return False
    for i in range(len(stdout)):
        if stdout[i] != stdexpout[i]:
            return False
    return True
    # Comment above and Write your custom judge here
    # 

    stdin = stdin[::-1]
    stdout = stdout[::-1]
    stdexpout = stdexpout[::-1]
    # Call this function for reading a single line of input
    def read(file):
        return file.pop()

    # T = int(read(stdin))

    return True
    

def stress_test(file_1: str, file_2: str):

    # Compile the Generator
    print('Compiling Generator.cpp')
    os.system('g++ -std=c++17 -Wshadow -Wall -o generator Generator.cpp -O2 -Wno-unused-result')

    # Compile the first Submission, which is the correct one
    print('Compiling ' + file_1)
    os.system('g++ -std=c++17 -Wshadow -Wall -o AC ' + file_1 + ' -O2 -Wno-unused-result')

    # Compile the second Submission, which is the one to be tested
    print('Compiling ' + file_2)
    os.system('g++ -std=c++17 -Wshadow -Wall -o WA ' + file_2 + ' -O2 -Wno-unused-result')

    for seed in range(1, limit + 1):
        print("Test Case:", seed, flush = True)
        # Generate the input
        os.system("./generator " + str(seed) + " > STDIN")
        # Run the Correct Submission
        os.system("./AC < STDIN > STDOUT1 2> STDERR1")
        # Run the Submission to be tested
        os.system("./WA < STDIN > STDOUT2 2> STDERR2")

        # Get the contents of input and output
        std_input = pre_process(get_contents('STDIN'))
        std_expout = pre_process(get_contents('STDOUT1'))
        std_output = pre_process(get_contents('STDOUT2'))

        if not custom_judge(std_input, std_output, std_expout):
            print("Wrong Answer:", seed, flush = True)
            remove_files()
            return
    remove_files()


def run_single(file: str) -> bool:
    # Compile the Submission
    print('Compiling ' + file)
    os.system('g++ -std=c++17 -Wshadow -Wall -o exe ' + file + ' -O2 -Wno-unused-result')
    # Run the Submission
    print('Running ' + file)
    os.system('./exe < STDIN > STDOUT')
    std_input = pre_process(get_contents('STDIN'))
    std_output = pre_process(get_contents('STDOUT'))
    std_expout = pre_process(get_contents('STDEXPOUT'))
    verdict = custom_judge(std_input, std_output, std_expout)
    return verdict


def get_contents(file_name: str) -> str:
    with open(file_name, 'r') as file:
        return file.read()

def pre_process(contents: str) -> list:
    contents = contents.strip()
    contents = contents.split('\n')
    for i in range(len(contents)):
        contents[i] = contents[i].strip()
    return contents

def remove_files() -> None:
    files_to_be_removed = ['AC', 'WA', 'exe', 'generator', 'STDOUT1', 'STDOUT2', 'STDERR1', 'STDERR2']
    for file in files_to_be_removed:
        if os.path.exists(file):
            print('Removing ' + file)
            os.remove(file)

if __name__ == '__main__':
    os.system('clear')
    do_stress = do_stress or len(sys.argv) == 3
    if do_stress:
        if len(sys.argv) < 3:
            print("Please Provide necessary arguments")
            exit(0)
        print("Running Stress Test")
        file_1, file_2 = sys.argv[1], sys.argv[2]
        stress_test(file_1, file_2)
    else:
        if len(sys.argv) < 2:
            print("Please Provide necessary arguments")
            exit(0)
        print("Running Single Test")
        file = sys.argv[1]
        verdict = run_single(file)
        print('Verdict: ' + ('Accepted' if verdict else 'Wrong Answer'))
        remove_files()