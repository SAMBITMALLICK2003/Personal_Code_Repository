class node:
    def __init__(self,value=None):
        self.data=value
        self.next = None

class stack:
    def __init__(self):
        self.top= None
        self.size = 0
    
    def push(self,value):
        Node = node(value)
        if self.top==None:
            self.top = Node
        else:
            Node.next = self.top
            self.top = Node
        self.size +=1
    
    def pop(self):
        if self.top == None:
            print("Stack empty")
            return None
        else:
            data = self.top.data
            self.size -= 1
            if self.top.next == None:
                self.top = None
            else:
                self.top = self.top.next
            return data
        
    def peek(self):
        if self.top == None:
            return None
        else:
            return self.top.data
        
    def disp(self):
        arr = []
        temp = self.top
        while(temp):
            arr.append(temp.data)
            temp = temp.next
        print(arr)
        
s1 = stack()
s1.push(2)
s1.push(5)
s1.push(3)
s1.push(10)
s1.pop()
s1.disp()