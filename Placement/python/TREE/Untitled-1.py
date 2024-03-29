class tree:
    def __init__(self,data):
        self.left = None
        self.right = None
        self.data = data
    def insert(self,data):
        if self.data:
            if data<=self.data:
                if self.left is None:
                    self.left = tree(data)
                else:
                    self.left.insert(data)
            else:
                if self.right is None:
                    self.right = tree(data)
                else:
                    self.right.insert(data)
        else: 
            self.data=data
    def printinord(self):
        if self.left:
            self.left.printinord()
        print(self.data)
        if self.right:
            self.right.printinord()
    def delete_Node(self, key):
        if self is None:
            return self
        if key < self.data:
            self.left = self.left.delete_Node(key)
            return self
        elif key > self.data:
            self.right = self.right.delete_Node(key)
            return self
        if self.left is None:
            temp = self.right
            self = None
            return temp
        elif self.right is None:
            temp = self.left
            self = None
            return temp
        temp = self.right
        while temp.left is not None:
            temp = temp.left
        self.data = temp.data
        self.right = self.right.delete_Node(temp.data)
        return self

t = tree(10)
t.insert(15)
t.insert(5)
t.insert(2)
t.insert(13)
t.insert(7)
t.delete_Node(2)
t.printinord()

