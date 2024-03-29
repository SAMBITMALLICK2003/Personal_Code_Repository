class stack:
    MAX_LEN = 5
    def __init__(self):
        self.arr = []

    def push(self,value):
        if(self.isFull()):
            print("stack full")
        else:
            self.arr.append(value)

    def pop(self):
        if(self.isEmpty()):
            print("stack empty")
        else:
            val = self.arr.pop()
            return val
    
    def isFull(self):
        return len(self.arr) == self.MAX_LEN
    
    def isEmpty(self):
        return len(self.arr) == 0
    
    def disp(self):
        print(self.arr)
s1 = stack()
s1.pop()
s1.disp()
s1.MAX_LEN=100
print(s1.MAX_LEN)