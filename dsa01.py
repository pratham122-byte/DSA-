def my_deconator(func):
    def wrapper():
        print("before function execution")
        func()
        print("after function execution")
    return wrapper
@my_deconator
def say_hello():
    print("hello")
say_hello()