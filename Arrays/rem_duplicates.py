# Remove duplicates from sorted array

# class solution:
#     def remove_duplicates(self, nums: list[int])->int:
#         size=len(nums)
#         for i in range(1,size-1):
#             if(nums[i-1]==nums[i]):
#                 nums.remove(nums[i])
#         updated_size=len(nums)
#         for i in range(updated_size,size):
#             nums[i-1]="_"
#         return updated_size

# a=[1,1,2,2,3,3,3]

# obj = solution()
# k=obj.remove_duplicates(a)
# print(k)
class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        i = 1

        for j in range(1, len(nums)):
            if nums[j] != nums[i - 1]:
                nums[i] = nums[j]
                i += 1
        
        return i
    

a=[1,2,2,3,3,3,4,4,4,4]

obj = Solution()
k = obj.removeDuplicates(a)
print(k)