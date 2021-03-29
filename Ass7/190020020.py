import sys

parent = {} #the dictionary that stores parent of a given vertex if present


def dfsvisit(adj,s,topsort): #the recursive dfsvisit function
    for v in adj[s]:
        if v not in parent:
            parent[v] = s
            dfsvisit(adj,v,topsort)
    topsort.append(s)    #using dfs to do topological sorting of a DAG


if __name__ == "__main__":
    file1 = open(sys.argv[1],"r") #opening the input file from command line argument
    file2 = open("ts.txt","w") #opening the file to output
    n , m = [int(x) for x in file1.readline().split()]
    adj = [[] for i in range(n)] #list of lists containing the adj vertices for each vertex, vertex as index
    
    while True:
        line1 = file1.readline()
        if not line1:
            break
        x,y = [int(a) for a in line1.split()]
        if y not in adj[x]:         #building the adj list of lists
            adj[x].append(y)
        
    topsort = []  #This stores the values of the topological sort in reverse order
    vertices = []
    for i in range(n):
        vertices.append(i)
    
    #Implementing dfs

    for s in vertices:   #for each vertex if not present in parent we use dfsvisit function to add it
        if s not in parent:
            parent[s] = None
            dfsvisit(adj,s,topsort)


    topsort.reverse()  #Reversing the order as we append to the back while appending

    for i in topsort:  #printing the topological sort order into text file
        print(i,file=file2)