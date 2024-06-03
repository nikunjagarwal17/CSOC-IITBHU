# Challenge#1

#### information
[link for ctf](https://play.picoctf.org/practice/challenge/186?category=4&page=1)

![information](https://i.ibb.co/w6WW666/image.png)


[cat.jpg](https://mercury.picoctf.net/static/149ab4b27d16922142a1e8381677d76f/cat.jpg)


So, when we look at the title of the CTF **information** we got a hint to look for the details of the image we can do so with the command **exiftool** so let's get into it.

 - Firstly, let download the file.
 - Now, look for the details in the **exiftool**

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/162d956b-9f78-47f2-ac9e-c72a81db0ae0)


- We got some sort of data in License loos k like **base64** 
- So, let's decrypt it. by simply **base64 -d** . **-d** flag is used to decode base64 string and it works 
- **picoCTF{the_m3tadata_1s_modified}** we got the flag.
