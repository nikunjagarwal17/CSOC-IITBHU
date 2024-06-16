# Challenge 1

[Here](https://github.com/JustAnAverageGuy/literate-octo-fiesta/tree/main/challenge_1) we are given with two different files 

source.enc
```enc
d2l0aCBvcGVuKCdmbGFnLnR4dCcsICdyJykgYXMgZjoKICAgIGZsYWcgPSBmLnJlYWQoKQoKcyA9ICcnLmpvaW4oZm9ybWF0KG9yZChpKSwgJzAyeCcpIGZvciBpIGluIGZsYWcpCmUgPSAiIgoKZm9yIGkgaW4gcmFuZ2UoMCxsZW4ocyksNCk6CiAgICBlICs9IGZvcm1hdChpbnQoc1tpOmkrMl0sMTYpXmludChzW2k6aSs0XSwxNiksICcwMngnKQoKd2l0aCBvcGVuKCdvdXRwdXQudHh0JywgJ3cnKSBhcyBmOgogICAgZi53cml0ZShlKQ==
```
<br/>

output.txt
```txt
43104f0c32017b48340179266203350636025f6b6e0a5f2730423f42
```


on looking at the source.enc file we can clearly get that the source.enc file is encoded in base64 format so lets try to decode it from base64 to normal ASCII so on doing the same we get 


![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/110031ad-1c3a-4ea3-8636-e2526c6e4f89)
<br/>
<br/>
<br/>
<br/>
decodedsource.enc
```python
with open('flag.txt', 'r') as f:
    flag = f.read()

s = ''.join(format(ord(i), '02x') for i in flag)
e = ""

for i in range(0,len(s),4):
    e += format(int(s[i:i+2],16)^int(s[i:i+4],16), '02x')

with open('output.txt', 'w') as f:
    f.write(e)
```


So firstly we have to understand out encoding source 
- it is taking our flag and converting it into hexadecimal value
- then it is iterating over the hexadecimal string
- for iteration i=0
- lets taking s="1a2b3c4d"
- s[0:2] is "1a" (hexadecimal).
- s[0:4] is "1a2b" (hexadecimal).
- Convert "1a" to integer: int("1a", 16) is 26.
- Convert "1a2b" to integer: int("1a2b", 16) is 6699.
- XOR operation: 26 ^ 6699 is 6705.
- convert 6705 to hex: "1a31"
- second iteration i=4,8.... and so on

so to revert back this we have to xor it again (using properties of XOR) 

- XORing "1a31" again with "1a" gives us "1a2b" which is our original hex string

so lets implement the same using the python also lets convert this hex to bytes 
here is the script to do so

```python
# encoded string that we get from output.txt file
encoded = '43104f0c32017b48340179266203350636025f6b6e0a5f2730423f42'

# empty string to store decoded hex string
decoded = ""

# reverting the hex 
for i in range(0,len(encoded),4):
    decoded += format(int(encoded[i:i+2],16)^int(encoded[i:i+4],16), '02x')

# hex to bytes
flag = bytes.fromhex(decoded)

print(flag)
```


running the script

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/25c9dc99-31d7-4d3f-8aaf-7672e80847c3)


> Flag: CSOC23{345y_ba5364_4nd_x0r?}





























