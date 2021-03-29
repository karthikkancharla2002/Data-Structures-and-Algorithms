import sys

if __name__ == "__main__":
    file1 = open(sys.argv[1],"r") #opening the input file from command line argument
    file2 = open("sd.txt","w") #opening the file to output

    n , m = [int(x) for x in file1.readline().split()]

    edges = []  #this stores all the directed edges including weights
    dict2 = {}
    for i in range(n):
        dict2[i] = []

    while True:  #reading input and storing into list
        line1 = file1.readline() 
        dict1 = {}
        list1 = []
        if not line1:
            break
        x,y,w = [int(a) for a in line1.split()]
        dict1[y] = w
        list1.append(x)
        list1.append(y)
        list1.append(w)
        edges.append(list1)
        dict2[x].append(dict1)

    #Implementing the Bellman Ford Algorithm

    d = [float('inf') for i in range(n)]
    parent = [None for i in range(n)]
    d[0] = 0
    for i in range(n-1):
        for x,y,w in edges:
            if d[x]!=float('inf') and d[y] > d[x] + w:
                d[y] = d[x] + w
                parent[y] = x
    for x,y,w in edges:
            if d[x]!=float('inf') and d[y] > d[x] + w:
                d[y] = float('-inf')
                for b in range(len(parent)):
                    if parent[b]==y:        #marks the vertex after negative cycle and all vertices to which it is a parent as - infinity
                        m = b
                        d[b] = float('-inf')
            
    #Printing output to the required file
    print("0 0",file=file2)
    for i in range(1,n):
        if d[i] == float('inf'):
            print(f"{i} +inf",file = file2)
        elif d[i] == float('-inf'):
            print(f"{i} -inf",file = file2)
        else:
            print(f"{i} {d[i]}",file = file2)
