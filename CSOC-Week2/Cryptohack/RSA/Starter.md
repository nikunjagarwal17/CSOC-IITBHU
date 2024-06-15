# STARTER

## RSA Starter 1
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/57a4be49-d5f5-4b71-a7d0-4148891d43f7)

Here in this challenge we have to compute the given expression using the pow() function present in python 

write the foowing script in python 
```python
base = 101
exponent = 17 
modulus = 22663

print(pow(base,exponent,modulus))
```
or 

```python
print(101,17,22663)
```

running the script and getting the answer
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/c0ab5277-f579-4615-b406-264ff6a4f3c1)

> Flag: 19906

<br/>
<br/>
<br/>
<br/>

## RSA Starter 2

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/86599eb4-5092-48b6-9a34-40892356f4c9)

here in this challenge we have given two primes (i.e. p and q) with exponent (i.e. e) and the message (i.e. number that we have to encrypt) using RSA encryption we have to encrypt the message 
we can do so using this script
```python
# Primes
p = 17
q = 23

# Exponent
e = 65537

# Calculating N (Modulus)
N = p*q

# Text to encrypt
m = 12

# Encrypted text (Cipher Text)
# ciphertext=pow(message,exponent,Modulus)
ciphertext=pow(m,e,N)

print(ciphertext)
```
**Explaination:** firstly we have to calculate the value of N and then using this N we have to find our cipher text (i.e. encrypted text)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/e7f38954-0226-40fd-ae08-0d3cd5b121e0)

> Flag: 301

<br/>
<br/>
<br/>
<br/>

## RSA Starter 3

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/59f543f4-638e-4426-ae68-7a1622bb2191)

Here in the challenge we are given with two prime and we have to find teh **Totient** of that numbers.
Here is a article related to what **Euler totient** is

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/f9084672-84a8-45c5-8025-43e7d7cee517)

So using the Euler's theorem we can use this script to calculate the same 

```python
# Primes
p = 857504083339712752489993810777
q = 1029224947942998075080348647219
# Euler totient
phi = (p-1)*(q-1)

print(phi)
```
Runnig the script we got 
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/b3615832-54ea-4e41-a90a-1d78102e6c44)

> Flag: 882564595536224140639625987657529300394956519977044270821168



<br/>
<br/>
<br/>
<br/>

## RSA Starter 4

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/d1d8ebf2-cae2-4840-97b2-89623cc9c0aa)

Here in the challenge we have to calculate the private key (i.e. d) we can calculate this using the [inverse modular arithmatics](https://en.wikipedia.org/wiki/Modular_multiplicative_inverse) by applying the following we get this script to get the value of d

```python
# Primes
p = 857504083339712752489993810777
q = 1029224947942998075080348647219

N = p*q

# Exponent
e = 65537

# Totient
phi = (p-1)*(q-1)

# Private key
d = pow(e,-1,phi)

print(d)
```

Running the script and getting the output

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/dbcfb672-befc-4862-bc4e-8dcc868df6f5)
> Flag: 121832886702415731577073962957377780195510499965398469843281

<br/>
<br/>
<br/>
<br/>

## RSA Starter 5

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/e5445a11-c07d-4e5d-ae3e-a03d6af7ad4f)

Here we have to decrypt the ciphertext given
also we are given thet we have to use the value of d as we get in the previous challenge 
so its quite obvious that the value to p and q are the prime used to get the value of N.
on getting the values we can simply calculate the value of the decrypted cipher text

we can use the following script
```python
# Primes
p = 857504083339712752489993810777
q = 1029224947942998075080348647219

N = 882564595536224140639625987659416029426239230804614613279163
assert p*q == N

# Exponent
e = 65537

# Totient
phi = (p-1)*(q-1)

# Private key
d = pow(e,-1,phi)

# Cipher Text
c = 77578995801157823671636298847186723593814843845525223303932

# Decrypted Text
m = pow(c, d, N)

print(m)
```
**Explaination:** we have used assert to verify the values of p and q, after verifying we can find the value of phi and then the value of d that are needed to find the flag easiely 
since we know that we can reverse the encryption easiely using the d as:
> message = pow(ciphertext, privatekey, modulus)

running the script we got 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/88df22cb-f1c9-4118-983b-e6c951442bc8)

> Flag: 13371337


<br/>
<br/>
<br/>
<br/>

## RSA Starter 6

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6e8171ef-07e8-43f9-9381-c6c46b13136e)

Here we are given with the details of private key of a RSA encryption system and we have sign the message 
by reading about the signing of the message in the decription of the challenge we get to know that the signing of message is simple we have to just encrypt our message using our private key 

here is the script we can use to sign a message with sha256 and then with private key
```python
from Crypto.Util.number import bytes_to_long
from hashlib import sha256

# Message Text
text = "crypto{Immut4ble_m3ssag1ng}"
shtext = sha256(text.encode()).digest()

# Message Long
m = bytes_to_long(shtext)

# Private Key 
N = 15216583654836731327639981224133918855895948374072384050848479908982286890731769486609085918857664046075375253168955058743185664390273058074450390236774324903305663479046566232967297765731625328029814055635316002591227570271271445226094919864475407884459980489638001092788574811554149774028950310695112688723853763743238753349782508121985338746755237819373178699343135091783992299561827389745132880022259873387524273298850340648779897909381979714026837172003953221052431217940632552930880000919436507245150726543040714721553361063311954285289857582079880295199632757829525723874753306371990452491305564061051059885803
d = 11175901210643014262548222473449533091378848269490518850474399681690547281665059317155831692300453197335735728459259392366823302405685389586883670043744683993709123180805154631088513521456979317628012721881537154107239389466063136007337120599915456659758559300673444689263854921332185562706707573660658164991098457874495054854491474065039621922972671588299315846306069845169959451250821044417886630346229021305410340100401530146135418806544340908355106582089082980533651095594192031411679866134256418292249592135441145384466261279428795408721990564658703903787956958168449841491667690491585550160457893350536334242689

# Signed Message [ciphertext = pow(message, d, N)]
signedmessage = pow(m, d, N)

print(signedmessage)


```

**Explaination:** we are using pycryptodome library for the bytes_to_long function to get the bytes convert into the long interger so that we can apply the excryption on it.
So firstly we have to hash our message using SHA265 hash function and then encrypt the hashed message using privete key d as our exponent and the modulus that is given to us.

Runnning the script.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/07a9e46a-f5d9-4c74-824e-39544923294b)


> Flag: 13480738404590090803339831649238454376183189744970683129909766078877706583282422686710545217275797376709672358894231550335007974983458408620258478729775647818876610072903021235573923300070103666940534047644900475773318682585772698155617451477448441198150710420818995347235921111812068656782998168064960965451719491072569057636701190429760047193261886092862024118487826452766513533860734724124228305158914225250488399673645732882077575252662461860972889771112594906884441454355959482925283992539925713424132009768721389828848907099772040836383856524605008942907083490383109757406940540866978237471686296661685839083475

























