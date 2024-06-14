# Mathematics

## Greatest Common Divisor
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/aa4ce605-cac9-4893-9ac7-134046da5735)

We have to write a script to find the GCD of the two numbers
We can do so using the following script.
```python
def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)
a=66528
b=52920
print(gcd(a,b))
```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/7cf952b6-eec9-4744-b393-5a351f64a83c)


> Flag: 1512

<br/>
<br/>
<br/>
<br/>

## Extended GCD

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/7482ded7-5139-4393-af70-ae2e87ec5d20)

Here we have to write a script to implement Extended Euclidean Algorithm here is the required script 
```python
def extended_gcd(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        g, u1, v1 = extended_gcd(b, a % b)
        u = v1
        v = u1 - (a // b) * v1
        return (g, u, v)

# Example usage
gcd, u, v = extended_gcd(26513, 32321)
print("GCD: {}\nu: {}\nv: {}".format(gcd,u,v))
```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/138fef5a-9c1c-45f1-91dd-5cca988427f3)

Since we have to get the lowest number 

> Flag: -8404

<br/>
<br/>
<br/>
<br/>

## Modular Arithmetic 1

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/2308ae73-5355-4b5c-86a7-83906448b35f)

here in the challenge we have to firstly find the modulus and then submit the lowerest number.
we can do so by the following script

```python
# 11 ≡ x mod 6
# 8146798528947 ≡ y mod 17
a = 11 % 6
b = 8146798528947 % 17
print(a if a < b else b)
```
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/5db5c899-6894-4b43-8b58-e0ef266c6f4e)

> Flag: 4


<br/>
<br/>
<br/>
<br/>

## Modular Arithmetic 2

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/8e797f88-3e59-4d43-b44e-5a86dfb6f01e)

We have to solve the challange with the use od **Fermat's little theorem** according to which 

If p is a prime number and a is any integer such that a is not divisible by p (i.e., p does not divide a), then:
> a ^ (p-1) ≡ 1 (mod p)

so by using this therorem 

273246787654^(65536) mod 65537 
is equal to 1

we can also do this by using the following script 
```python
print(pow(273246787654,65536,65537))
```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/db43a1cd-2c18-4fd2-8443-f5e1bc1723dc)

> Flag: 1


<br/>
<br/>
<br/>
<br/>


## Modular Inverting

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/03fa483a-9b9d-4ecf-a15b-36f53f98f5b1)

Here we have to solve the following problem
> 3 * d ≡ 1 mod 13
>
> or can be written as
>
> d ≡ 1/3 mod 13
>
> d ≡ 3^(-1) mod 13

to solve this we can use the follwing script
```python
# by using pycryptodome library
from Crypto.Util.number import inverse
print(inverse(3,13))
# by using simple pow function
print(pow(3,-1,13))
```
we can do so by both of the methods.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/65a63cc8-8931-477a-af2a-49ca252356fd)

> Flag: 9






