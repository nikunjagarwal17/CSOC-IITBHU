
#### hideme
[link for ctf](https://play.picoctf.org/practice/challenge/130?category=4&page=1)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6068aaf6-4cee-4b92-98f9-057dc3ce3fe8)


Description suggest that something is hidden in the file.
So let us use **binwalk** as this is a great tool to extract hidden files.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/f7485f02-38ed-4f9d-9abb-dd20e092b1ab)

We got too many files in this.

Lets search into the file content  
listing all the files with **la -alR**, **-R** flag is used to list recursively 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/e693f9bb-43a6-4268-aacf-7b25590245da)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/ae9aa8f1-500f-4a3b-81b1-1eb95ed19d9b)

looking into the file we find some strange file named **hidden**

let see this file

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/9bb07050-8f75-41e7-a7dd-669789b2e0b2)

this file contains some space sepetared data.
let remove all the spaced first 
the resulting sring looks like this 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/f16a3dba-edf9-40e7-8136-bc475fc7be4b)


this seems to be base64 data trying to decrypt this 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/295a71ac-9819-4358-9eb6-2ffd7f3c8856)

- here we got our flag: **picoCTF{D1d_u_kn0w_ppts_r_z1p5}**

- 
