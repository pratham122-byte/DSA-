def is_balanced(expression):
    stack = []
    for char in expression:
        if char in "({[":
            stack.append(char)   # push opening bracket
        elif char in ")}]":
            if not stack:
                return False     # no opening bracket to match
            top = stack.pop()    # pop last opening
            if (char == ")" and top != "(") or \
               (char == "}" and top != "{") or \
               (char == "]" and top != "["):
                return False     # mismatch found
    return not stack   # if stack empty, it's balanced


def evaluate_sum(expression):
    # remove parentheses and spaces, then split by '+'
    clean_expr = expression.replace("(", "").replace(")", "").replace(" ", "")
    parts = clean_expr.split("+")
    total = 0
    for p in parts:
        if p.isdigit():
            total += int(p)
    return total


# Main program
expr = input("Enter an expression: ")

if is_balanced(expr):
    print("Balanced")
    result = evaluate_sum(expr)
    print("Sum =", result)
else:
    print("Not Balanced")