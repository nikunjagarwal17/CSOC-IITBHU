#### Matryoshka doll
[link for ctf](https://play.picoctf.org/practice/challenge/129?category=4&page=1)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/46290569-a87f-4a8e-8e29-62e4a961624b)

So, when we look at the title of the CTF **Matryoshka doll** so what is this,
**Matryoshka doll** also known as **stacking dolls**, **nesting dolls**, **Russian tea dolls**, or **Russian dolls**, are a set of wooden dolls of decreasing size placed one inside another.
Also looking at the hint given 
**Wait, you can hide files inside files? But how do you find them?** 
So its like something is hidden the the file.

So lets firstly check for the details of the image here we found some **Trailer data after PNG IEND chunk** using **exiftool**

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/9b2994e2-b866-49a9-a0fa-709cdf4ee6a5)

so i am thinking like it is something hidden into the image on extracting it we find the following to do so i am using **binwalk -e**

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/67ccacee-cafd-4c6c-b046-06e10c1e4309)

checking around I found that some trailing data is again embedded in the baseimage (specifing the property of the doll i.e. one into another)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/dc2eae4d-5571-4560-af9a-262f08d3eff1)

so lets on doing this repetedly I finally found the flag after 4-5 repetetions.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/bfaf1437-697b-4158-b514-d99226208539)


- So the flag is **picoCTF{bf6acf878dcbd752f4721e41b1b1b66b}**
