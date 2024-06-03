#### hideme
[link for ctf](https://play.picoctf.org/practice/challenge/350?category=4&page=2)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/e16b0df1-2252-4a11-b064-ace4a281b182)

So as the title suggest **hideme** lets think in the direction if the image is hiding something.
So first check for the details of the image here I found some Warning about trailing data chunks 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/fa5919a8-8232-4b8a-ae87-aaf28b83439d)

So let's use **binwalk -e** to extract the data after extracting looking into data here I found a **secret** directory and a file **flag.png**
opening the file we get the flag 


![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/a5924e3d-b845-4873-bd4f-13cdca23a188)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/ba2f3b60-efe0-4288-a222-69bab3a226bc)

simply on opening the file we got this 
- So the flag is **picoCTF{Hiddinng_An_imag3_within_@n_ima9e_82101824}**
