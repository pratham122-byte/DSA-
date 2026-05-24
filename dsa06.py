class callcounter:
    def__int__(self,func):
        self.func=func
        self.count=0
    def__call__(self,*args,**kwargs):
        self.count+=1
        print(f"called(self.count)times")
        return self.func(*args,**kwargs)
@callcounter
def greet(name):
    return f"hello{name}"
print(greet{"pratham"})
print(greet{"nikhil"})