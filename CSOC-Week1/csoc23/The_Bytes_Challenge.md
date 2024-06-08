# The "Bytes" Challenge

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/6cd0fa03-6f0c-4216-b62a-d87a3b0a04e9)

[challenge file](https://github.com/0xkn1gh7/CSOC23-Infosec/blob/main/Week-1-Forensics/chall1.png)

the challenge description gives us a hint about comments and we know we can add comments in the image in meta data, checking it out 
![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/f14ee75e-ac2d-401a-844c-820bbff1da11)

here is a pastebin link

while this paste requires a password so lets find out more 
the description also hints us about bits and we know that we can hide data into the bits by using LSB or MSB 
so trying to decrypt with it using **zsteg**

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/e207c032-fa3f-45a4-a4be-8dec5d1ff22f)

this string **y0u_f0uNd_m3_h4ck3r** looks like to be the password for the paste 
![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/a02781ff-baf8-4015-af4a-1dd60806f68d)

here we got it...
> Flag: CSOC23{p4rr0t_by735_4r3_d4Ng3r0u5}
