# merge strings alternatively

class solution :
    
    def merge_strings_alternatively(self, word1 : str, word2 : str)-> str:
        
        # find the minimum length of the given two words
        len1 = len(word1)
        len2 = len(word2)
        
        minlen = min(len1, len2)
        
        resultant_string = "" # initialize the empty resultant string
        
        for i in range(minlen) :
             resultant_string += word1[i]
             resultant_string += word2[i]
        
        # now concatenate the remaining letters of the word with greater length
        
        if len1 > len2 :
            resultant_string += word1[minlen : ]  # use slicing to concatinate remaining letters
        else :
            resultant_string += word2[minlen : ]  # use slicing to concatinate remaining letters
        
        return resultant_string # return the resultant string

obj = solution()

result = obj.merge_strings_alternatively("abc", "pqrst")
print(result)