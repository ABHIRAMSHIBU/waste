def fact(n):
    if(n==1):
        return 1
    else:
        return n*fact(n-1)
def fib_calcn(n):
    n=n-1
    if n<=1:
        return 1
    else:
        return fib(n-1)+fib(n-2)
def pow_n(x,n=1):
    if n==1:
        return x
    else:
        return x*pow_n(x,n-1)
def print_menu():
    print "All are done using recurssion"
    print "This is a simple menu driven program, it can print these."
    print "           1)Factorial of a number."
    print "           2)Fibanocci Series of a given number."
    print "           3)Print power of a number."
def compute():
    print_menu()
    opt=input("Enter an option :")
    if opt==1:
            inp=input("Enter a number to calcualte factorial :")
            print "Factorial of the given number is ",fact(inp)
            return 0
    elif opt==3:
            inp=(input("Enter a number to calculate power :"))
            inp2=(input ("Enter the power :"))
            print "Answer of the given expression is ",pow(inp,inp1)
            return 0
    elif opt==2:
            inp=input("Enter a number to print fibanocci :")
            for i in range(inp):
                print fib_calcn(i)
            return 0
    else:
        print "Wrong input!"
c=1
while (c==1):
    c=compute()
