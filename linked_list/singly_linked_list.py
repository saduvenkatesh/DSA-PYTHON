# Implementation of singly linked list

class node :
    def __init__(self,data):
        self.data = data
        self.next = None

class singlyLinkedList :
    
    def __init__(self):
        self.head = None
    
    def append (self, data: int) :
        
        newNode = node (data)
        if self.head == None :
            self.head = newNode
        else :
            temp = self.head
            
            while temp.next :
                temp = temp.next
            temp.next = newNode
    
    def prepend(self, data: int):
        
        newNode = node(data)
        
        if not self.head :
            
            self.head = newNode
        else :
            temp = self.head
            newNode.next = temp
            self.head = newNode
            
    
    def insert_at_position(self, data: int, position: int):
        
        newNode = node(data)
        
        if not self.head :
            self.head = newNode
        else :
            temp = self.head
            while position >2 :
                temp = temp.next
                position-=1
            newNode.next = temp.next
            temp.next = newNode
            
    def display(self) :
        
        temp = self.head
        
        while temp :
            print(f"{temp.data}->",end="")
            temp = temp.next
        print("None")
    


sll = singlyLinkedList()

sll.append(1)
sll.append(2)

sll.append(3)
sll.append(5)
sll.insert_at_position(4,4) # data, position
sll.insert_at_position(6,6)
sll.insert_at_position(10,4)


sll.display()