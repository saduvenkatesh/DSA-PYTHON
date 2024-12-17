# Node class to represent an individual element in the linked list
class Node:
    def __init__(self, data):
        self.data = data  # Data to store in the node
        self.next = None  # Pointer to the next node

# Singly Linked List class
class SinglyLinkedList:
    def __init__(self):
        self.head = None  # Initialize the head of the list

    # Method to insert a node at the beginning of the list
    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # Method to insert a node at the end of the list
    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:  # If the list is empty, set the new node as the head
            self.head = new_node
            return
        current = self.head
        while current.next:  # Traverse to the last node
            current = current.next
        current.next = new_node

    # Method to delete a node by value
    def delete_by_value(self, value):
        if not self.head:  # If the list is empty
            print("List is empty.")
            return
        
        # If the head node itself holds the value to be deleted
        if self.head.data == value:
            self.head = self.head.next
            return
        
        # Traverse the list to find and delete the node
        current = self.head
        while current.next and current.next.data != value:
            current = current.next
        
        if not current.next:  # Value not found
            print(f"Value {value} not found in the list.")
            return
        
        current.next = current.next.next  # Unlink the node to delete it

    # Method to display the linked list
    def display(self):
        if not self.head:  # If the list is empty
            print("List is empty.")
            return
        current = self.head
        while current:  # Traverse the list and print each node's data
            print(current.data, end=" -> ")
            current = current.next
        print("None")  # Indicate the end of the list

# Example usage
if __name__ == "__main__":
    sll = SinglyLinkedList()

    # Insert elements at the end
    sll.insert_at_end(10)
    sll.insert_at_end(20)
    sll.insert_at_end(30)

    # Insert element at the beginning
    sll.insert_at_beginning(5)

    # Display the list
    print("Linked list:")
    sll.display()

    # Delete a node
    print("\nDeleting 20:")
    sll.delete_by_value(20)
    sll.display()

    # Attempt to delete a non-existent node
    print("\nDeleting 50:")
    sll.delete_by_value(50)
    sll.display()
