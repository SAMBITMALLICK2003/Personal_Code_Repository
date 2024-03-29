class MyQueue(object):

    def __init__(self):
        self.inb = []
        self.outb = []
        self.size = 0

    def push(self, x):
        self.inb.append(x)
        self.size += 1
        

    def pop(self):
        if not self.outb:
            while(self.inb):
                self.outb.append(self.inb.pop())
        a = self.outb.pop()
        self.size -= 1
        while(self.outb):
                self.inb.append(self.outb.pop())
        return a
        

    def peek(self):
        if not self.outb:
            while(self.inb):
                self.outb.append(self.inb.pop())
        a = self.outb[-1]
        while(self.outb):
                self.inb.append(self.outb.pop())
        return a
        

    def empty(self):
        return self.size==0
        

myQueue = MyQueue()
print(myQueue.push(1))
print(myQueue.push(2))
print(myQueue.peek())
print(myQueue.pop())
print(myQueue.empty())