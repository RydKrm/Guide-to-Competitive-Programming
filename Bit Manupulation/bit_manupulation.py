# And Operation 
a = 10
b = 12
print("Or",a&b)

# Or operation
print("And",a|b)

# Xor Operation 
print("Xor ", a^b)

# Not Operation 
print("Not", ~a)

# print binary number 
binary = bin(12) # 0b1100

# to remove 0b 
binary = bin(a)[2:]
print(binary)

# * Bit Shifts 

# * Left shift :- The left bit shift x << k appends k zero bits to the number while also means multiple 2^k in the end  
num = 12
print("Before shift ", bin(num)[2:])
left_shift = num<<1 
print("After binary shift ", bin(left_shift)[2:]) 

# * Right Shift : The right bit shift x >> k removes the k last bits from the number which also means divide number by 2^k
right_shift = num>>1
print("After right shift", bin(right_shift)[2:])

# * Bit Masking 
# ! Find the 4th bit of a number num 
mask = num&1<<4
print("nth bit", bin(mask)[2:])

# * Explanation : Binary representation of 1 is :- 000000000000001 so 1<<4 makes :- 0000000000010000 after and operation the num 4 this only left other field with set to 0 


