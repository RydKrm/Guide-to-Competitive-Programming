### Euler's Totient Theorem
Euler's Totient Theorem is a generalization of Fermat's Little Theorem. It plays a crucial role in 
number theory, particularly in the context of modular arithmetic and cryptography

### Theorem
If `n` is a positive integer and `a` is an integer such that `gcd(a,n) = 1`then:
`a ^ ϕ(n) ≡ 1(mod n)`
Here, `ϕ(n)` (Euler's totient function) counts the number of integers up to `n` that are coprime with `n`.

### Examples of Euler's Totient Theorem

#### Example 1: \( n = 9 \) and \( a = 2 \)

1. **Compute \(\phi(9)\):**
   \[
   \phi(9) = 9 \left( 1 - \frac{1}{3} \right) = 9 \cdot \frac{2}{3} = 6
   \]

2. **Apply the theorem:**
   \[
   2^6 \equiv 1 \pmod{9}
   \]

   **Calculation:**
   \[
   2^6 = 64
   \]
   \[
   64 \div 9 = 7 \text{ remainder } 1
   \]
   \[
   64 \equiv 1 \pmod{9}
   \]

## Example 2: \( n = 10 \) and \( a = 3 \)

1. **Compute \(\phi(10)\):**
   \[
   \phi(10) = 10 \left( 1 - \frac{1}{2} \right) \left( 1 - \frac{1}{5} \right) = 10 \cdot \frac{1}{2} \cdot \frac{4}{5} = 4
   \]

2. **Apply the theorem:**
   \[
   3^4 \equiv 1 \pmod{10}
   \]

   **Calculation:**
   \[
   3^4 = 81
   \]
   \[
   81 \div 10 = 8 \text{ remainder } 1
   \]
   \[
   81 \equiv 1 \pmod{10}
   \]
