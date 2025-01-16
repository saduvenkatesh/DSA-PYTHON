class ListNode :
    head=None
    def __init__(self, val=0):
        self.val = val
        self.next = None
        
    def linkedlist(self, val : int) :
        
            
        

class solution : 
    
    def removeNthFromEnd(self, head : ListNode, n : int) :
        temp = head
        length=0
        while temp!=None :
            temp = temp.next
            length = length +1
        
        curr = head
        
        for i in range(1,length-1):
            curr = curr.next
        temp1 = curr.next
        curr.next = temp1.next
        del curr

problem = solution()

problem.removeNthFromEnd()
        
    
    
        
        
            