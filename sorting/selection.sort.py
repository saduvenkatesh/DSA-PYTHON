# Selection sort :
# It works on the principle of identifying the smallest element in the list and moving it to the beginning of the list
# This process is repeated until all the elements in the list  are sorted


class sorting :
    def __init__(self,list):
        self.list=list
        self.size=len(list)
        print("The given list is : ",list)
    
    # Selection Sort
    def selection_sort(self)-> list:
        
        for i in range(0,self.size):
            min_index= self.find_min_element(i,self.size)
            if self.list[min_index] < self.list[i] :
                temp=self.list[i]
                self.list[i]=self.list[min_index]
                self.list[min_index]=temp
            i+=1 
        return self.list
    
    # find minimum element index in a given list
    def find_min_element(self,lower_bound : int, upper_bound : int) -> int:
        min_element= float('inf')
        for i in range(lower_bound, upper_bound):
            if self.list[i] < min_element :
                min_element=self.list[i]
                min_index=i
        return min_index


# arr=[18,3,2,33,21]
# list= sorting(arr)
# sorted_list = list.selection_sort()
# print("The sorted list is : ",sorted_list)


def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        # Find the minimum element in the remaining unsorted array
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Example usage
arr = [64, 25, 12, 22, 11]
selection_sort(arr)
print("Sorted array:", arr)
