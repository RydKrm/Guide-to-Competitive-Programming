class CredirCart:
    # A Consumer credit card 

    # constructor to create a new cart
    # the space is define that the member of the class is non public which means these are not able to use from the outside 
    def __init__(self,customer,bank,account,limit):
        self._customer = customer
        self._bank = bank
        self._account = account
        self._limit = limit
        self._balance = 0

    # Getter functions
    def get_customer(self):
        return self._customer
    
    def get_back(self):
        return self._bank
    
    def get_account(self):
        return self._account
    
    def get_limit(self):
        return self._limit
    
    def get_balance(self):
        return self._balance
    
    # added extra change if account cross over the limit 
    def charge(self, price):
        # if current price plus balance is greater than limit then added extra price 
        if price + self._balance > self._limit:
            return False
        else:
            self._balance += price
            return True
        
    def make_payment(self, amount):
        if self._balance<amount:
            return False
        else:
            self._balance -= amount
            return True
