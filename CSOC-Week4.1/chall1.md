# Reversing chall-1

[link]()

Find the password.

So lets try to run the ELF executable file.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/2ae9349e-cc33-41fa-bb1e-cb21565be029)

firstly before going into the reversing lets try to run basi commands like strings, ltrace, strace.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/d8273a10-a898-4ae1-a938-d6f712f39308)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/ae865c6c-8723-42b6-9a63-f75adf9a34fc)

now lets try to decompile our program using [**binaryninja**](https://binary.ninja/) 

the interface will be like this here i have set it to higher lvl language to view the higher level code that will be easy for us to understand

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/e3a6dfc6-962d-4c48-9e5c-dc85f68ab887)


![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/2d9b347e-a00b-4d64-855e-c2278dc67703)

we can find the functions listed on the side page reading into the main function we can understand that it is firstly printing the string "What is the password",```printf(format: "What is the password:")```

then it is defining a buffer variable named "buf" ```void buf```

then it accepts a string entered by the user ```fgets(buf: &buf, n: 0x100, fp: __TMC_END__)```

now it is replacing the value in the buf variable at the offset stored in variable```data_201a``` to 0 ```*(&buf + strcspn(&buf, &data_201a)) = 0```

we can check for the value of ```data_201a``` by simple double clicking on it.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/c3303694-a65d-4abd-a40e-7bd380c2effb)

value is 0a it integer 10.

so basically it is changing the value of ```buf``` varibale at index 10 to value ```binary 0```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/97df2381-c716-40bf-87c4-b8ff9adf5210)

now here it is checking for the buf variable in a check function.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/015226da-3088-4a98-83f9-778e5b967466)

if the value is one it is correct alse it will be false.

firstly it is defing a varibale ```rax_1``` and storing the value of the length of the string and also defining a empty variable ```rax_7```

now 
```if (rax_1 != 0xa || (rax_1 == 0xa && *arg1 != 0x31) || (rax_1 == 0xa && *arg1 == 0x31 && arg1[4] != 0x39))```

now it is checking for three conditions if the value of ```rax_1`== 0xa (0xa=10)``` OR ```rax_1 == 10 && *arg1 != 0x31 (0x31 = 49 or (chr)'1')``` OR ```rax_1 == 10 && *arg1 != '1' && arg[4] != 0x39 (0x39 = 49 or (chr)'9')```
if any of the condition satisfies it gives us value of ```rax_7 = 0``` and thus check function returns the value of 0 hence incorrect password.

the another check function checks for the value of

```rax_1 == 10 && *agr1 == '1' && arg1[4]=='9'```

if it is true it returen to the value of the rax_7 to be 1 hence correct password.

so the length of or passoword is 10 of the scheme ```1---9-----``` where - can be any character.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/05aa99be-cda1-4a53-951e-6ef80f44e5e7)

> Password: 1---9----- where - can be any character.














