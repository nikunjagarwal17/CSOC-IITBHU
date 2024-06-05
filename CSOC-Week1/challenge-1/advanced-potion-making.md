# advanced-potion-making

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/fcc22042-46fc-492a-87ef-712c1d5a869e)

after downlowing the file
lets see what the file is
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/c265e022-4d1e-46ad-98cd-00cf8866361a)

it shows the data. By reading the description of the challenge it is clear that the file is corrupted and we have to fix it 
but for this we have to check what is the original type og the file 

so lets check for the hexdata of the file.
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/4d633c50-3023-4304-8de9-13222a78841c)

or we can also see

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/b6562a08-c0a7-4042-ab59-f8786741ed94)

it contains IHDR, sRGB tags which means it will be some PNG image type data
fixing its header back using **hexedit**

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/65d97a4a-c1b7-492e-8a65-2d8aa06d606f)

opening the image we found nothig but the red screen .
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/7545244b-15c1-4f27-9642-1c4aadc03584)

trying to look around with metadata, strings, but nothing found...
but got something with **stegsolve**

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/45992d80-d3e3-4f20-b88d-b736be59d3fb)

- flag: picoCTF{w1z4rdry}
