
class listNode :
    head=None
    def __init__(self, val : int):
        self.val = val
        self.next = None
        
    
    def linkedlist (self, val : int) :
        newNode = listNode(val)
        if self.head ==None :
            self.head=newNode
        else : 
            temp = self.head
            while temp!=None:
                temp = temp.next
            
            temp2 =temp
            temp2.next= newNode
    
    def displayLinkedList(self) :
        curr = self.head
        
        while curr!=None : 
            print(curr.val)
            

head = listNode(0)
head.linkedlist(1)
head.linkedlist(2)
head.linkedlist(3)
head.linkedlist(4)
head.linkedlist(5)

head.displayLinkedList()

        