# Reversing chall-2

[link]()

Find the password.

So lets try to run the ELF executable file.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/097020a5-74bb-4c6f-85b9-d019e5bf746b)

firstly on trying with some commands like strings, ltarce, strace we didin't find nothing.

so lets look into disassembled code for the ELF. We can take use of multiple sofware to disassemple code to get more understand as different disassembles may produce slightly different outputs.we 
Note: We may not need to understand each and every line of the disassembled code may due to is is guessable or not of much use.


lets firstlt take a look into the main function, 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/f972ee92-c3e9-47cb-93f5-edce99ec77d0)

It prints ```Enter the password:``` statement ```std::ostream::operator<<(std::operator<<<std::char_traits<char> >(&std::cout, "Enter the password:"), std::endl<char>);```

then defines a variable ```var_38``` and takes the input of the password that we enter.

a function ```if (checkPassword(&var_38, r12) == 0)``` call is done to check the password based on whinch it return us ```Login failed``` or ```Login successsful``` 



![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/0ff14da8-fc88-44ff-8765-06a4bb65740a)

now lets check into the checkpassword function. simply by double clicking on it be can move to the function.

a variable ```var_48``` is defined and the data of the varible ```data_2005``` is stored into it. i.e. ```data_2005 = dec```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/bcad882d-222d-418e-a6b4-e5e2db2b8743)

then a ```var_20``` is defined   with a value of ```0xfffffff9 i.e. -7 in integer``` the a variable ```rax``` is defined to store the length of the dta in ```var_48 i.e. 3 in our case``` then the variable ```rax_5``` that stores the bool value if the length of the ```arg1``` matches with the value of negative int value of the ```var_20 i.e 7``` ```std::string::length(arg1) == ((int64_t)-(var_20));``` 

if the value of ```rax_5``` is true or 1 a loop is run that iterates 3 times and build a string into ```var_68```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/3dc5ff14-fb4f-4b2c-85bc-645440104477)

here the ```std::string::operator+=(&var_68);``` statment is not much clear we can also look for the disaccembly code in different softwares like **ghidra**.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/2207cdc7-b2d6-4bc8-9c34-b0b562e4db25)

here is implementaion of the function is bit different but the logic will be same.

over the iteration the ```var_68``` value will be ```dekcarc``` 

now the 
```
0000136f          std::string::iterator rax_13 = std::string::end(arg1);
00001389          std::reverse<__normal_iterator<char*, std::string> >(std::string::begin(arg1), rax_13);
```
these statement simple reverses the order of ```arg1```
then ```_ZSteqIcEN9__gnu_cxx11__...gIS3_St11char_traitsIS3_ESaIS3_EEESE_(arg1, &var_68) == 0``` simple checks if the both string i.e. the reversed ```arg1``` and the ```var_68``` is same or not.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6d7093f0-6776-40f2-b0bf-c96cd316a836)

if the strings are same it returns 1 else 0

then if the strings matches the checkpassword function also returns the value 1 and thus giving us ```Login successful```
so the password will be the reversed string of ```dekcarc``` i.e. ```cracked```

> Password: carcked

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/5d438f59-bbec-412f-9cf2-e40d90d9586b)
























