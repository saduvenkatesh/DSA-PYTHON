class Item:
    
    # class attribute
    pay_rate= 0.8 # The pay rate after 20% discount
    all=[]
    
    # validating the argument's data type is best practice
    # if parameter data type is float, you can pass either int or float as argument 
    # if you dont declare parameter datatype, then it won't validate the argument datatype
    # By initialising quantity as 0, automatically parameter quantity is declared as int, then also it validate datatype of arguments that were passed
    def __init__(self,name:str, price:float ,quantity=0): 
        
        # Run validations to the recieved arguments
        assert price >=0, f"Price shouldn't be negative" # custom message for assertion error
        assert quantity >=0, f"Quantity shouldn't be negative"
        
        # Assign to the self object to make them available for class methods and instances
        self.name=name
        self.qunatity=quantity 
        self.price=price
        
        # Action to execute
        Item.all.append(self)
        
    def __repr__(self):
        return f"Item('{self.name}', '{self.price}', '{self.qunatity}')" # Representive version of our object
    
    def calculate_price(self):
        return self.qunatity*self.price
    
    def apply_discount(self):
        self.price=self.price*self.pay_rate

item1 = Item("Phone",100,5)   # creating instance/object (also passing some arguments to initialise)
print(item1.calculate_price()) # Accessing class methods using an instance of class

item2 = Item("Laptop",200,10)  # creating instance/object (also passing some arguments to initialise)
print(item2.calculate_price()) # Accessing class methods using an instance of class

# Accessing attributes using instance object
print(item1.name)    
print(item1.price)
print(item1.qunatity)


# Accessing class attributes
print(Item.pay_rate)    # Accessing class attributes for class level
print(item1.pay_rate)   # Accessing class attributes for instance level
print(item2.pay_rate)   # Accessing class attributes for instance level
print()
print(Item.__dict__)    # All the attributes for class level
print("")
print(item1.__dict__)   # All the attributes for instance level 

item1.apply_discount()
print(item1.price) # gives 80.0 by applying pay_rate=0.8

item2.pay_rate=0.7 # modifying class level attribute
item2.apply_discount()
print(item2.price) # gives 140.0 by applying pay_rate=0.7

print("\n\n")
print(Item.all)  # it will print all the instances in class with their id

print("\n\n")
for item in Item.all:
    print(item.name)  # it will print all the names of their instances in class


# comma seperated values