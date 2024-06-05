# File Types

[link](https://play.picoctf.org/practice/challenge/268?category=4&page=2)


![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/5650d3b5-2c9b-4873-a56a-51383726d028)

checking the file type
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/7ecc8ade-5678-43e4-9314-264dfc07128d)

lets run the script directly in the terminal
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/8e0f5554-1110-444e-9737-b31002e0157f)

this gives us an error searching online for this and I found out that I have to install **sharutils**
> sudo apt install sharutils

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/ced9e718-d528-47b4-b8eb-4761418a14ca)

lets check the file type again
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/5d328d7b-13bc-4b7f-9c5e-883d82d6ec72)

lets uncompress this also
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/59e43d2e-8eea-471d-a6d8-14769a5f7953)

checking the file type again it is cpio archive 
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/1f849743-7bd8-4a1f-81df-f764fee8f158)

doing this repetedly by checking the file type and decompressing it 



![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/0fbc7b66-e95d-4582-9dc7-53b5cd88a335)
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/9e0e96a7-702f-47a1-9163-2bcf11fc409b)
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/53f70ab9-5595-482a-9c65-d5dac7e5d36c)
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/aaefc899-a7b9-4075-ad30-bf5b764f8d22)


finally we found some ASCII Text, this text looks like to be hexadecimal string 
converting back to bytes 
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/7448451c-15ae-4c3d-8da5-596efb5d9a63)

joining the both string will give out out flag 
- Flag: picoCTF{f1len@m3_m@n1pul@t10n_f0r_0b2cur17y_79b01c26}


