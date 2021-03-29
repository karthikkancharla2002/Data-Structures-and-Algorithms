import sys

if __name__ == "__main__":
    file1 = open(sys.argv[1],"r") #opening the input file from command line argument
    file2 = open("sd.txt","w") #opening the file to output
    n , m = [int(x) for x in file1.readline().split()]
    adj = [[] for i in range(n)] #list of lists containing the adj vertices for each vertex, vertex as index
    
    while True:
        line1 = file1.readline()
        if not line1:
            break
        x,y = [int(a) for a in line1.split()]
        if y not in adj[x]:         #building the adj list of lists
            adj[x].append(y)
        if x not in adj[y]:
            adj[y].append(x)

    s = 0
    #code to implement bfs
    level = {s:0}
    parent = {s:None}
    i = 1
    frontier = [s]
    while frontier:
        next = []
        for u in frontier:
            for v in adj[u]:
                if v not in level:
                    level[v] = i
                    parent[v] = u
                    next.append(v)
        frontier = next
        i+=1


    for i in range(n): #printing the length of shortest distance if possible else printing -1
        if i in level.keys():
            print(level[i],file=file2)
        else:
            print("-1",file=file2)
    




        
    
