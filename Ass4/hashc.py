import sys


def hashing_func(key):
    #This is the hash function that determines index in the array
    sum = 0
    for i in range(len(key)):
        sum += ord(key[i])
    return sum

def deter(word1,word2):
    #This finds if two words are anagrams or not
    s1 = len(word1)
    s2 = len(word2)

    if s1 != s2:
        return 0
    
    word1 = sorted(word1)
    word2 = sorted(word2)

    for i in range(0,s1):
        if word1[i] != word2[i]:
            return 0
    return 1

class node:
    def __init__(self,value,next):
        self.value = value
        self.next = None


if __name__ == "__main__":
    key = "brainy"
    #m = 25000
    

    file1 = open(sys.argv[1],"r")
    m = int(sys.argv[2])
    #print(hashing_func(key))
    i=0
    list = [None]*m
    while True:
        line1 = file1.readline()
        if not line1:
            break
        line = line1.strip()
        p = hashing_func(line)
        n1 = node(line,None)
        if list[p]==None:
            list[p] = n1
        else:
            n1.next = list[p]
            list[p] = n1

    file3 = open("query1.txt","r")
    file2 = open("anagrams.txt","w")
    while True:
        line2 = file3.readline()
        if not line2:
            break
        line3 = line2.strip()

        word = line3
        #word = "abusive"
        wordh = hashing_func(word)
        wordn = list[wordh]
        #print(wordn.next.next.value)
        j = 0
        while wordn!= None:
            a = deter(wordn.value,word)
            if a==1 and j==0:
                g1 = wordn.value
                file2.write(g1)
                j= j+1
            elif a==1 :
                g2 =  " " + wordn.value
                file2.write(g2)
                j= j+1
            
            wordn = wordn.next
        if line2 != "\n":
            file2.write("\n")
    
    
   
    file1.close()
    file2.close()