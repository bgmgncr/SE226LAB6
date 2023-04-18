from math import factorial
n = int(input("n: "))
x = int(input("x: "))

term = lambda i: n**i / factorial(i)
terms = [term(i)for i in range(x+1)]
result = sum(terms)+1
print(f"e^{n}")

#Implementing a recursive function
#Since this symbol is a summation symbol, we have to do a recursive summation function.
def rec_func(n,k):
    global total
    if k>n:
        return
    term=-1**k+1*k
    total += term
    rec_func(n,k+1)
total =0

rec_func(9,2)
print(f"{total}")
