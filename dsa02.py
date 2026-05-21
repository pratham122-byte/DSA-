def my_decoator(func):
    def wrapper():
        print("welcome")
        func()
    return wrapper

@my_decoator
def greet():
    print("good morning")
greet = my_decoator(greet)
greet()