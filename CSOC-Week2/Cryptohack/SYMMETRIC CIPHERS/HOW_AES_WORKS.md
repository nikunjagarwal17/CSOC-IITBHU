# HOW AES WORKS

## Keyed Permutations

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/1b57ec51-46fe-4432-a196-0bacd892cbe1)

the term used for one-to-one correspondence is **bijection**

> Flag: crypto{bijection}

<br/>
<br/>
<br/>
<br/>

## Resisting Bruteforce
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/f66b87b3-34f0-4759-a88c-b2d718bfdb38)

the name of the best single-key attack against AES is **biclique**

> Flag: crypto{biclique}

<br/>
<br/>
<br/>
<br/> 

## Structure of AES

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/76c39def-f99c-4fa7-acc0-ca981e2247e6)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/0030ebde-b4b4-42b8-9427-2516624225ee)

here in this challenge we are given about the AES encryption technique and we have to complete teh function that is to convert matrix to bytes back we are already provided with half of the file and we have to complete it 

file provided is as follows 
```python
 def bytes2matrix(text):
    """ Converts a 16-byte array into a 4x4 matrix.  """
    return [list(text[i:i+4]) for i in range(0, len(text), 4)]

def matrix2bytes(matrix):
    """ Converts a 4x4 matrix into a 16-byte array.  """
    ????

matrix = [
    [99, 114, 121, 112],
    [116, 111, 123, 105],
    [110, 109, 97, 116],
    [114, 105, 120, 125],
]

print(matrix2bytes(matrix))
```

Here we have to complete the matrix2bytes function.

we can complete the function as follows 
```python
def matrix2bytes(matrix):
    text="".join(chr(i) for j in matrix for i in j)
    return text
```

after making the such edits the final file will be 

```python
def bytes2matrix(text):
    """ Converts a 16-byte array into a 4x4 matrix.  """
    return [list(text[i:i+4]) for i in range(0, len(text), 4)]

def matrix2bytes(matrix):
    text="".join(chr(i) for j in matrix for i in j)
    return text

matrix = [
    [99, 114, 121, 112],
    [116, 111, 123, 105],
    [110, 109, 97, 116],
    [114, 105, 120, 125],
]

print(matrix2bytes(matrix))
```
running the file we got out flag 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/332c1c96-ccd5-471e-a0dc-fe4c32f2b890)

> Flag: crypto{inmatrix}
