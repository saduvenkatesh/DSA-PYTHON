class ListNode :
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class solution :
    
    def build_linked_list(self, list) :
        
        head = ListNode(list[0])
        
        tail = head
        for value in list[1:] :
            tail.next = ListNode(value)
            tail = tail.next
        return head
    
    def display(self, head) :
        
         while head:
             print(f"{head.val}->", end="")
             head = head.next
         print("None")
    
    def delete_duplicates(self, list ) :
        
        prev = list
        while prev.next :
            curr = prev.next
            while curr :
              if prev.val == curr.val :
                 prev.next = curr.next
                 curr = curr.next
            prev = prev.next
    

obj = solution()

l1 = [1,2,2,3,3,4]
head1 = obj.build_linked_list(l1)
obj.display(head1)

l2 = [5,6,7,8]
head2 = obj.build_linked_list(l2)
obj.display(head2)

head3 = obj.delete_duplicates(head1)
obj.display(head3)