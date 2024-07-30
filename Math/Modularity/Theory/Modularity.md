### Basic
Modularity is find the remander when one number is divide by other number. If I have 7 apple and need to divide that apple with in 2 people then every people 
will get 3 apple and one apple remain. 

`7 mod 2 = 1`

other way 
`a % m`
`a - floor(a/m)*m`
Example :-
` => 7 - (7/2)*2 `
` => 7 - (3*2) `
` => 7 - 6 `
` => 1 `

##### Find the mod of negative number 
If you have -1 apple and you need to divide it among 3 people, you can think of it as if you start with 0 apples and then take away 1 apple, ending up with -1. 
If we imagine distributing apples in a way that the remainder is positive, you'd effectively be saying you need 2 more apples to get back to a state where you 
can evenly distribute them among the 3 people

`-1 mod 3 = ?` 
`(-1 + 0) mod 3`
`(-1 + 3 mod 3) mod 3`
`( 2 mod 3) mod 3`
` 2 mod 3`
`2`

Try the equation :-
`a - floor(a/m)*m`
`=> -1 - floor(-1/3)*3 ` IN modular this is will be 1
`=> -1 - (-1)*3 `
`=> -1 +3`
`=> 2`

#### Modulo Addition, Subtraction, Multiplication

`(a+b) mod m = ((a mod m)+(b mod m)) mod m` <br>
`(a-b) mod m = ((a mod m)-(b mod m)) mod m` <br>
`(a*b) mod m = ((a mod m)*(b mod m)) mod m`


#### Modulo Division 
Modulo works with only integer number.