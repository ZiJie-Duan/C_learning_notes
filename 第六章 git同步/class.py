
from time import sleep


class Animal:

    def __init__(self,type,age):
        self.type = type
        self.age = age
    
    def print_id_self(self):
        print("Animal: " + id(self))

class Human(Animal):
    
    def __init__(self,age,name):
        Animal.__init__(type="Human",age=age)
        self.name = name
    
    def print_id_self(self):
        Animal.print_id_self(self)
        print("Human: " + id(self))


peter = Human("Human",18,"Peter")
peter.print_id_self()
input()