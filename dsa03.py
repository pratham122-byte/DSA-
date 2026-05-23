def my_decorator(func):
    def wrapper(name):
        print("hello",name)
        func(name)
    return wrapper
@my_decorator
def greet(name):
    print("welcome to DSA class", name)
greet("krish")