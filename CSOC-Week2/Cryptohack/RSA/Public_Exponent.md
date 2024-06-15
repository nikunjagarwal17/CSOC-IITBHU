# PUBLIC EXPONENT

## Salty

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/049ae814-9859-4139-a99a-0f8d92981d43)

We are given with two files 

salty.py
```python
#!/usr/bin/env python3

from Crypto.Util.number import getPrime, inverse, bytes_to_long, long_to_bytes

e = 1
d = -1

while d == -1:
    p = getPrime(512)
    q = getPrime(512)
    phi = (p - 1) * (q - 1)
    d = inverse(e, phi)

n = p * q

flag = b"XXXXXXXXXXXXXXXXXXXXXXX"
pt = bytes_to_long(flag)
ct = pow(pt, e, n)

print(f"n = {n}")
print(f"e = {e}")
print(f"ct = {ct}")

pt = pow(ct, d, n)
decrypted = long_to_bytes(pt)
assert decrypted == flag
```


output.txt
```txt
n = 110581795715958566206600392161360212579669637391437097703685154237017351570464767725324182051199901920318211290404777259728923614917211291562555864753005179326101890427669819834642007924406862482343614488768256951616086287044725034412802176312273081322195866046098595306261781788276570920467840172004530873767                                                                  
e = 1
ct = 44981230718212183604274785925793145442655465025264554046028251311164494127485
```

So on reading the staly.py file we get to know that out flag is encrypted using RSA encryption.
On reading the description of the challlenge it gets out focus on the value of the exponent (i.e. e) given in the salty.py file which is very small.

considering the value of cipher text
> ciphertext = message^e % n

since the value of n >> cipher text and value of e is very small we can say that the

> ciphertext = message^e

so simply the value of the message is equals to the e'th root of the cipher text

here we can use the belp python script to calculate the i'th root of a number

```python
def iroot(x, n):

    if x == 0:
        return x, True  

    # initial guess 
    k = (x.bit_length() - 1) // n
    y = 1 << k 

    # result manupulation
    for i in range(k - 1, -1, -1):
        z = y | (1 << i)
        if z ** n <= x:
            y = z
    
    # return the result
    return y, x == y ** n
```

using this function to calculate the ith root we can implement the python script as given below
```python
from Crypto.Util.number import long_to_bytes
# i'th root 
def iroot(x, n):

    if x == 0:
        return x, True  

    # initial guess 
    k = (x.bit_length() - 1) // n
    y = 1 << k 

    # result manupulation
    for i in range(k - 1, -1, -1):
        z = y | (1 << i)
        if z ** n <= x:
            y = z
    
    # return the result
    return y, x == y ** n

# Values
n = 110581795715958566206600392161360212579669637391437097703685154237017351570464767725324182051199901920318211290404777259728923614917211291562555864753005179326101890427669819834642007924406862482343614488768256951616086287044725034412802176312273081322195866046098595306261781788276570920467840172004530873767                                                                  
e = 1
ct = 44981230718212183604274785925793145442655465025264554046028251311164494127485

message, exact = iroot(ct,e)

print(long_to_bytes(message))
```
**Explaination:** here we got our message as we discussed above using the i'th root of the cipher text after getting the message in the long values we can convert it back into the bytes using the pycryptodome libraries long_to_bytes function.

Running the script.
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/8079ff52-45de-4860-b65b-881364dc08f0)

> Flag: crypto{saltstack_fell_for_this!}
