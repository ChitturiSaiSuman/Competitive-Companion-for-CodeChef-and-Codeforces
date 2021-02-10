from random import randint

def generate_input_as_string():
    size = 20
    n = randint(1,size)
    inputs = [n]
    string = ' '.join([str(i) for i in inputs])
    return string

def main():
    test = 10
    with open("in.in","w") as file:
        file.write(str(test)+'\n')
        for t in range(test):
            string = generate_input_as_string()
            file.write(string+"\n")

main()