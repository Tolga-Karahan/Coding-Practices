# Metaclasses can be used to execute code automatically
# after the class definition. Suppose we want to add
# functionality to classes in runtime to do so we can
# get an input to add a functionality or not and we can
# define function that gets a class to add this 
# functionality upon a call.
class IdealistPhilosopher:
    pass

class MaterialistPhilosopher:
    pass

def the_answer():
    return 5

def add_answer(cls):
    if prompt == 'y':
        cls.the_answer = the_answer

if __name__ == '__main__':
    aristo = IdealistPhilosopher()
    marx = MaterialistPhilosopher()
    
    global prompt
    prompt = input("Do you need the answer?")

    try:
        add_answer(aristo)
        add_answer(marx)
        print(aristo.the_answer())
        print(marx.the_answer())
    except AttributeError:
        print("Philosopher.exe is stopped!")