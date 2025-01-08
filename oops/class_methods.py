import csv

class Item :
    all=[]
    def __init__(self, name:str, price: float, quantity: float):
        
        # validation
        assert price>=0, f"Price shouldn't be negative"
        assert quantity>=0, f"Quantity shouldn't be negative"
        
        self.name=name
        self.price=price
        self.quantity=quantity
        
        # actions to be executed
        Item.all.append(self)
    
    def __repr__(self):
        return f"Item({self.name}, {self.price}, {self.quantity})"
    
    @classmethod
    def instantiate_from_csv(cls):
        with open('./data.csv', 'r') as f:
            reader = csv.DictReader(f)
            items = list(reader)
        
        for item in items:
           Item(
               name = item.get('name'),
               price = float(item.get('price')),
               quantity = int(item.get('quantity'))
           )

Item.instantiate_from_csv()
print(Item.all)
