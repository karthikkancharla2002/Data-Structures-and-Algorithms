import sys
n=int(sys.argv[1])
file1 = open("toh.txt","w")

class Stack: #class for creating a stack with a variable top
    def __init__(self,size):
        self.size = size
        self.top = -1
        self.stack = []

def isEmpty(stack): #checking for stack underflow
    return len(stack)==0

def isFull(stack): #checking for stack overflow
    return len(stack)==n

def push(stackname,item):  #pushing an element into stack
    if isFull(stackname.stack):
        return
    stackname.stack.append(item)
    stackname.top = stackname.top+1

def pop(stackname): #poping an element from the stack
    if isEmpty(stackname.stack):
        return
    popel = stackname.stack[-1]
    stackname.top = stackname.top-1
    stackname.stack = stackname.stack[:-1]
    return popel
    
def namestr(obj,namespace): #a function to return name of a variable
    return [name for name in namespace if namespace[name] is obj][0]



def towerOfHanoi(n,source,destination,auxiliary,dict): #function for implementation of towers of hanoi
    if n==1:
        print(f"Pop disk 1 from Stack {source}",file = file1)
        a = pop(dict[source])
        print(f"Push disk 1 to Stack {destination}",file = file1)
        push(dict[destination],a)
        return
    towerOfHanoi(n-1,source,auxiliary,destination,dict)
    print(f"Pop disk {n} from Stack {source}",file = file1)
    b = pop(dict[source])
    print(f"Push disk {n} to Stack {destination}",file = file1)
    push(dict[destination],b)
    towerOfHanoi(n-1,auxiliary,destination,source,dict)
    


if __name__ == "__main__":

    A = Stack(n)    #for creating 3 stacks
    B = Stack(n)
    C = Stack(n)
    for i in range(n,0,-1):  #pushing elements into stack A
        push(A,i)
        print(f"Push disk {i} to Stack A",file = file1)
    dict = {"A":A,"B":B,"C":C}
    #towerOfHanoi(n,"A","C","B",dict) #calling the towers of hanoi function
