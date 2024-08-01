### Big number factorials

#### Question 
Find out the factorials of 100!

#### Think an a logical way 
How to find the factorials of 5!

Answer will be 
 => `1` 
 => `1 * 2`
 => `2 * 3`
 => `6 * 4`
 => `24 * 5`

If it was 100` we can go through the 100 and multiple each time with the 
answer. But the problem is interger variable cannot hold that much large 
number.
So If I used an array instand to store the number and when multiple with 
number update the value of each index then their will be updated answer 
with number multiple 


#### Example with explanation of logic 
Need to find the factorial of 22!. 

Let use an vector array with size `1000`. Which will be store the answer so 
let's calls it `ans`. Escape the 0 index. And answer will be store in 
reverse order so that  extra value can be added to it 

for `fact => 1` => `ans |1|0|....`
for `fact => 2` => `ans |2|0|....`
for `fact => 3` => `ans |6|0|....`
for `fact => 4` => `ans |4|2|0|0....`


At this point we need to added an extra number in the array first do multiple with `fact * ans[0]`. if the multiple number will be greater than 10 so need an `carry` variable to store that number. when we added next number that will be also multiple and added carry and check if it's greater 
then `10` or not. If it is then also store it in the carry.

If a carry left out then also need to added with a while loop.


```c++

#include<iostream>
#include<vector>
using namespace std;

void multiply(vector<int> &ans,int num, int &size){
    int carry = 0;
    for(int i=0; i<size; i++){
        int product = ans[i] * num + carry;
        ans[i] = product % 10;
        carry = product / 10;
    }

    // handle the carry 
    while(carry){
        ans[size] = carry % 10;
        carry = carry/10;
        size++;
    }

}

int main(){
    int n;
    cin>>n;

    vector<int> ans(1000,0);
    ans[0] = 1;
    int size = 1;

    for(int i=2;i<=n;i++){
        multiply(ans, i, size);
    }

    for(int i = size - 1; i>=0; i--){
        cout<<ans[i];
    }

    return 0;
}


```




