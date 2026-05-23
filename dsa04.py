def authorize(role):
    def decorator(func):
        def wrapper(user_role,*args,**kwargs):
            if user_role!= role:
                raise PermissionError("unauthorized access")
            return func(user_role,*args,**kwargs)
        return wrapper
    return decorator
@authorize("admin")
def delete_user(user_role,user_id):
    return f"user(user_id)deleted"
print("")