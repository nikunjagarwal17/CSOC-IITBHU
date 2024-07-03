# Reversing chall-4

[link]()

Write a Keygen.

So lets try to run the ELF executable file.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/a7fc370d-4108-4bd6-a78a-e98370cd3ce0)

So in order to write a key gen we have to basically reverse the ELF executable and reimplement the algorithm to generate the key.

looking into the disassembly code of the ELF.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/f8abe57b-360c-4bf3-a404-bbfe1dd380d1)

We will be using the debugger to look into the algorith more closely.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/9c1319cc-f363-4117-9b14-a61d774908ff)

till here it is just printing the intial stuff and then asking for the paassword 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/5652af45-9ef8-4bc6-948e-d4d4de1d0af1)

also it reads up 16 bytes which may means thay our password of length 16

lets enter a 16 length random password. say ```ABCDEFGHIJKLMNOP```

then a function all to ```_verify``` finction is made.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/d234923d-99de-4baa-893f-d7dd9201445d)

lets see whats this function exactly does.

the firstt part initializes some variables and sets their values, then the next part looks like a loop 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/fd17bb9a-2a00-4c21-ad86-32abae3eeb92)

the second part looks like a loop on debugging we can see that basically it iterates over the first 4 bytes of the string passed and sum us the ascii value of those and stores into a register ```r15```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/4c8a72d3-99e1-44f1-995b-0d18d59381a9)

then it is storing it back into register ```r12```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/51c303e0-2b14-4649-94c8-d0d8b95c9f4b)

now one more the _verify function is called. over the data but this time the string passed is ```IJKLMNOP``` i.e. from index 8 of the passed password,

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/e5dd0272-95aa-4a9d-abf7-1fb531349a58)

once again ```r15``` stores the sum of the ascii of the first 4 bytes then it is compared to ```r12``` then there is a _jmpwrong which jumps if the statement is wrong here in order to get the key we wanted this statement computed as to be false as to move to next computation step. which means the value of ```r15``` must be equal to ```r12``` we will edit the value of ```r15``` for debugging purpose and move further.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/f22783ec-7ff5-4e67-9520-055e5e63d57b)


simillarly this time the ascii sum of the first 4 bytes of ```EFGHIJKLMNOP``` string is calculated and stored into ```r15 which is then copied into r14``` then whhich is compared to the sum for the string ```MNOP``` which is stored in register ```r15```.
meanwhile the register ```r13``` maintains the sum of all the bytes calculated till then.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/4f9bb5bc-10d7-4b55-b91d-60a313fb854c)

We will again make an edit in value of ```r15``` to proceed further.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/16d25e63-fc4d-4390-b07d-9befaad5f2fc)

now the value of register ```r13``` is check (i.e. net sum of the ascii value of the full password passed) if it is ```0x42e```.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/29cf61bb-5afd-4d18-8584-60325e9e96c4)

again make a edit to proceed further.

here the value ```0xb``` is added to the value stored in the register ```r12``` which is the ascii sum of the values that we found at the first _verify function call. which is the compared to ```r15``` sum of ascii in last function call i.e of the password from the offset 12. we will agin edit the vlaue of r15 to proceed it further.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/35e6993c-47ab-434c-a80a-add821b1a8c2)

and thus we got "Access Granted"

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6bdcc92e-2fc3-47bc-a810-b206649824f0)

So basically what the algorithm is:

- takes a 16 length password
- split it into 4 parts each of 4 lenth
- check if the ascii sum of first and the third part is same
- check if the ascii sum of the second part and fourth part is same
- checks if the ascii sum of first part is greater than ascii sum of fourth part by 0xb
- also checks if the ascii sum of entered password is 0x42e
- if all the conditions are verified the key is correct

now lets write a program that will generates the random key will all the above mentions characteristics

here is the keygen program source code

```python
import random


def check_key1(key):
	charsum=0
	i=0
	for c in key:
		i+=1
		charsum+=ord(c)
	return charsum ,i

def genkey(key):
	part1=key
	part2=""
	check=0
	for c in key:
		if(ord(c)<111 and check==0):
			part2+=chr(ord(c)+0xb)
			check+=1
		else:
			part2+=c
	print ((part1+part2)*2)


key = ""
while True:
	key+=random.choice("qwertyuiopasdfghjklzxcvbnmASDFGHJKLQWERTYUIOPZXCVBNM1234567890")
	s,n=check_key1(key)
	if s > 0x106 and n!=4:
		key = ""
	elif s==0x106 and n==4:
		genkey(key)
```

Logic:
the key structure consist of 4 parts with part 1 and part 3 same and part 2 similar to part 4 and the total ascii sum must be 0x42e = 1070 and the second part is 0xb = 11 more then first part on applying basic maths the first part willl be of 0x106 = 262 length and second part of 0x111 = 273 length 

now generating a random string of length 4 and then creating a part2 by simply advancing any character with 11 bytes and then combining the part 1 and part 2 in the required manner.

Runnig the keygen program.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/2e07f4ad-5c23-4e4d-a3b1-32789922b02e)

it gives us many keys lets try to use some of them.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/fd9214f7-2a5c-48ab-85ec-7d70635222e5)

And it works.























