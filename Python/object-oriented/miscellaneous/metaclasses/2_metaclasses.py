# Metaclasses are classes whose instances are also classes.
# Metaclasses are defined in the same way we define classes,
# but they inherit from type class. When a class statement
# that uses metaclass keyword ends, metaclasses called 
# automatically. If no metaclass keyword is used, type()
# is called by default.
 

# We can use a metaclass to augment philosopher classes
# in runtime based on imput.
def the_answer(self):
    return 5

class PhilosopherMetaClass(type):
    def __init__(cls, clsname, superclasses, attributedict):
        is_answer_needed = input(f"Do you need an answer from a {clsname}?")
        
        if is_answer_needed == 'y':
            cls.the_answer =  the_answer

class IdealistPhilosopher(metaclass=PhilosopherMetaClass):
    pass

class MaterialistPhilosopher(metaclass=PhilosopherMetaClass):
    pass

plato = IdealistPhilosopher()
diderot = MaterialistPhilosopher()


try:
    print(plato.the_answer())
except AttributeError:
    print(f"{plato.__class__}.exe is stopped!")

try:
    print(diderot.the_answer())
except AttributeError:
    print(f"{diderot.__class__}.exe is stopped!")