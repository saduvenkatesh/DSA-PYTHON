class singlyLinkedList :
    def __init__(self,data: int):
        self.data=data
        self.next=None
        self.head=None
    
    def insert_at_begin(self, data: int):
        newnode = singlyLinkedList(data)
        if self.head==None:
            self.head=newnode
        else :
            newnode.next = self.head
            self.head=newnode
    
    def insert_at_end (self, data: int):
        newnode = singlyLinkedList(data)
        temp=self.head
        while temp.next!=None:
            temp=temp.next
        temp.next=newnode
    
    def display_list(self) :
        temp=self.head
        while temp!=None:
            print(f"{temp.data}->")
            temp=temp.next
        print("None",end="")
        

sll = singlyLinkedList()