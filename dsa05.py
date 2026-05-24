from functools import wraps
def log_execution(func):
    @wraps(func)
    def wrapper(*args,**kwargs):
        print(f"Executing",(func.__name__))
        return func(*args,**kwargs)
    return wrapper
@log_execution
def compute(a,b):
    """This function adds to number"""
    return a+b
print(compute.__name__)
print(compute.__doc__)
print("result:",compute(5,7))