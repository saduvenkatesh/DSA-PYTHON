# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class solution:
    
    # build linked list through given list
    def buildLinkedList(self, list):
        
        head = ListNode(list[0])  # storing head value to return at end of func
        temp = head
        for value in list[1:] :   # appending remaining elements to the linked list using slicing method
            temp.next = ListNode(value)
            temp = temp.next
        return head  # returning head 
    
    # display linked list through given head link
    def display(self, head):
        temp = head
        
        while temp:
            print(f"{temp.val}->",end="")
            temp=temp.next
        print("None")
        
        
    
    def mergeTwoLists(self, list1, list2) :
      
      head = ListNode()
      
      tail = head
      
      while list1 and list2 :  # check if any list is empty
          if list1.val < list2.val : # compare the values of list1 and list2 traversing both the list simultaneously
              tail.next = list1
              list1 = list1.next
          else :
              tail.next = list2
              list2 = list2.next
          tail = tail.next
     
      if list1 : # check if list is non-empty
          tail.next = list1
      elif list2 : # check if list is non-empty
          tail.next = list2
      return head.next # return head reference

a = [1,2,4]
b = [1,3,4]

l1 = solution()
head1 = l1.buildLinkedList(a) # head reference for linked list 1
l1.display(head1)

l2 = solution()
head2 = l2.buildLinkedList(b) # head reference for linked list 2
l2.display(head2)

resultant_head = l1.mergeTwoLists(head1, head2) # finally , merge the both linked lists by pass both the heads 

l1.display(resultant_head)