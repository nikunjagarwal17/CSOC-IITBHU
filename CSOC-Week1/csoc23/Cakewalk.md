# Cakewalk

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/476c32b9-6b32-4b9d-9ca9-00458ddb8cf3)

[Challenge File](https://github.com/0xkn1gh7/CSOC23-Infosec/blob/main/Week-1-Forensics/chall2)

reading the description we get that there is a hint to use **binwalk** in the word **cakewalk** so using it and extracting the file we found a zip folder that is password protected its a simple trask to bruteforce the password protected zip file with the help of the master password file **rockyou.txt** also mentioned as a hint in the challenge 

Here I am using **fcrackzip**, we can also use some other methods also like **john the ripper, hashcat, etc**.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6fb74a1c-b5a9-4c7e-ba26-4a71313af820)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/7beeecbe-6656-43f3-a9d7-b637b7a78990)

password we got: 1337HaX0r

> flag: CSOC23{bRu73_f0rc3_y0uR_w4y}
