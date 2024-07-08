# Reversing chall-5

[Link]()

Find the password.

So lets firstly look into the disassembl of the chall5 here i am using binary ninda to disassemble it in graph mode to get a much better view.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/2f9ca33b-0dad-4ea3-a352-94f6f21777a2)


this is the disassembly code of the main function in the function it first calls to a __main function which sets somevariables that is not of our much use. then it calls a function obfuscatePassword which looks something intresting and the data returned by it is stored in the variable named ```var_58``` then some next statements is to print the string on the console then the nnext is to get the input form the user which is stored into the variable ```var_78``` then a variable ```var_19``` is defined to store a byte ```0x6d``` then two new variables are introducted ```var_a0``` and ```var_a8``` storing starting and the starting and the ending position of the entered password.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/25eca377-95bb-42d8-9e79-e87b9871f7cc)

now lets first look of the function obfuscatePassword by double clicking on it.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/f5ea8824-17c5-4fe6-9db5-6b161dedc76f)

looking on the graph we can simply get that there is somesort of looping there. looping is performed on the string ```0xJam3z``` from staring to the end of the sting by simply iterating over each character then XORing it with ```0x6d``` and then storing it at the end it returns the fully XORed string which is then stored in the variable ```var_58``` as seen in main funtion.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/66118221-2774-43a8-a05e-cf8840760295)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/06379ba2-e0e5-4833-999f-0e4ae06e23d4)

lets jump back to our main funtion the next instruction again suggests us that the password that we entered is also going under some sort of loop from starting to ending. which is again the similar loop that iterates over each characted and XOR ench charcter with ```0x6d``` then return the final string into a variable ```var_98```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6bb5fe9e-bf3d-4dec-a4f2-4b5e5e88b6ba)

then after exiting the loop the both of the XORed stings are compared to eachother if they are same we will get correct password.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/15aa241d-d0d3-4057-b9ce-475e1633a63a)

So we get our password which will be ```0xJam3z```.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/87ab82bb-861e-40c6-b148-ac6a7f2d40ab)

wait this is stored in the plain text so we can also get it by using the **strings** command but the problem is that our code has so many string for which looking into each string is not possible also we are not aware of the length of the passord which make it more difficult to guess which string is our password but now as we know whats our passoword we can look into the srings using gpep command 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/a60baa72-93bf-4ed8-b56a-9f2d057eb221)

here is our password.

> Password: 0xJam3z

















