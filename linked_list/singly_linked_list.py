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
    
    def delete_at_begin (self ):
        
        temp = self.head
        self.head = temp.next
        
        temp = None
    
    def delete_at_end(self) :
        temp = self.head
        while temp.next.next :
            temp = temp.next
        temp.next = None
        
    def delete_at_specific_position(self, position: int) :
        
        prev = self.head
        
        while position > 2 :
            prev = prev.next
            position-=1
        curr = prev.next
        
        prev.next = curr.next
        
        curr = None
        
            
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
sll.append(4)
sll.append(5)
sll.delete_at_specific_position(3)
sll.delete_at_specific_position(4)


sll.display()