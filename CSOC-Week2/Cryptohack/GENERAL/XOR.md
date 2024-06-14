# XOR
<br/>
<br/>
<br/>
 
## XOR Starter

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/cded4501-3690-4c38-a6f9-ffaefadad2a6)

So here we have to apply xor on each byte of our string **label** we can do so by using the following script.

```python
string='label'
newstring=''.join([chr(ord(char) ^ 13) for char in string])
print(newstring)
```
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/934654b3-2027-496c-bef3-579a7a624702)

> Flag: crypto{aloha}


<br/>
<br/>
<br/>


## XOR Properties

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6521a319-798f-4192-a68c-79450a65d775)

To solve this challenge we can use the follwing script.
```python
# KEY1 = a6c8b6733c9b22de7bc0253266a3867df55acde8635e19c73313
# KEY2 ^ KEY1 = 37dcb292030faa90d07eec17e3b1c6d8daf94c35d4c9191a5e1e
# KEY2 ^ KEY3 = c1545756687e7573db23aa1c3452a098b71a7fbf0fddddde5fc1
# FLAG ^ KEY1 ^ KEY3 ^ KEY2 = 04ee9855208a2cd59091d04767ae47963170d1660df7f56f5faf

from pwn import xor

k1=bytes.fromhex('a6c8b6733c9b22de7bc0253266a3867df55acde8635e19c73313')
k2xork1=bytes.fromhex('37dcb292030faa90d07eec17e3b1c6d8daf94c35d4c9191a5e1e')
k2xork3=bytes.fromhex('c1545756687e7573db23aa1c3452a098b71a7fbf0fddddde5fc1')
flagxork1xork3xork2=bytes.fromhex('04ee9855208a2cd59091d04767ae47963170d1660df7f56f5faf')

k2=xor(k2xork1,k1)
k3=xor(k2xork3,k2)
flag=xor(xor(xor(flagxork1xork3xork2,k2),k3),k1)
print(flag)
```
**Explainantion:** firstly we are converting all the hex values to the bytes and then by using the properties of the **XOR** 
> a ^ b ^ c = a ^ (b ^ c)
>
> a ^ b ^ b = a ^ (b ^ b) = a ^ (0) = a
i.e XORing the value with itself gives us Idintity element

so we can find k2 by xoring the k2 ^ k1 with k1 and so on to fing k3 and ultimately the flag.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/bc8dfc21-cd01-44d2-8181-9ebc7d71ebd1)

> Flag: crypto{x0r_i5_ass0c1at1v3}
<br/>
<br/>
<br/>

## Favourite byte

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/64b83f9a-10ee-49f0-8aa0-011f27940c4d)

Since we know that our data is encryped only using one byte we can get our key i.e. used to encrypt the flag by XORing the text with the letter 'c' as we know the flag format and the first byte is 'c' (Flag fomat: crypto{....}) 
after getting the key we can use this key to decrypt for flag by XORing all the bytes with the key we get 

I have written this script to do so.

```python
ct=bytes.fromhex('73626960647f6b206821204f21254f7d694f7624662065622127234f726927756d')
key = ct[0] ^ ord('c')
print("".join(chr(char ^ key ) for char in ct))
```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/5a9210f1-7fc2-4ebd-9edc-96200e644928)

> Flag: crypto{0x10_15_my_f4v0ur173_by7e}











