#### Prime Number 
If a number is prime then that will be divide by 1 and that number itself. Example :- 3,7,9,13,17...

##### Check for a prime number 
For checking a number `N` is prime or not, start a loop from 2 to `N-1` and divide the number. If it is
divisible in that range then it's not a prime number otherwise it's a prime number. 
Example : check 6, which is divisible by 2,3 but checking 13 which is  not divisible by any number from 
2 to 12. So that a prime number

```cpp
 bool isPrime(int n){
  for(int i = 2; i<n; i++ ){
    if(n%i == 0) return false;
  }
  
  return true;
}

```
The complexity of this problem is `O(n)`

##### Square root theorem
A number is prime or not can be check in `O(sqrt(n))` complexity. Let,s check 36 prime or not?
36 can be divide by `2,3,6,12,18`. so if a number `N` divide by another number in range of `2  to n-1`. 
That means it's not a prime number. Let's again says `N` is divide by `a` and result `b`. so we can 
also says that `a * b = N` For 36 we can write with pair of two number like `2 * 18 = 36`, `2 * 9 = 36`, `6 * 6 = 36`. 
In those pair, one of two number will be less or equals `sqrt(n)`. So If a number is not prime then a 
number `a` is exists in the range of 2 to `sqrt(n)` where n is divisible. 

```cpp
 bool isPrime(int n){
  for(int i = 2; i*i<=n; i++ ){
    if(n%i == 0) return false;
  }
  return true;
}

Now the complexity will be `O(sqrt(n))`

```



