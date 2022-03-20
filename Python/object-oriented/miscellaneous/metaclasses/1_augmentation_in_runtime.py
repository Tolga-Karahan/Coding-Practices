# The implementation in 0_augmentation_in_runtime module
# requires explicit calls that can cause problems. Instead 
# we can use the decorator syntax to augment the behaviour.
prompt = input("Do you need the answer?")

def the_answer(self):
    return 5

def add_answer(cls):
    if prompt == 'y':
        print("Augmenting the class in runtime!")
        cls.the_answer = the_answer
    return cls

@add_answer
class IdealistPhilosopher:
    pass

@add_answer
class MaterialistPhilosopher:
    pass

if __name__ == '__main__':
    aristo = IdealistPhilosopher()
    marx = MaterialistPhilosopher()

    try:
        print(aristo.the_answer())
        print(marx.the_answer())
    except AttributeError:
        print("Philosopher.exe is stopped!")