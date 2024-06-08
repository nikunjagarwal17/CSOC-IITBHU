# Baby Shark

[Challenge File](https://github.com/0xkn1gh7/CSOC23-Infosec/raw/main/Week-1-Forensics/chall6)

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/ebbeef28-6027-4139-ae2a-1326365e28d8)

the file we get is a **pcapng** file which is used to store network data.
the name **baby shark** itself hints us to use the wireshark software by which we can read this data looking into data and reading it we found a string in it

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/88534a94-5d27-4ad0-8af1-3380a0f1836c)

> r$~rabL3c3J0D9cC<N

there is one more term **gROoTh47er's** this term hints us for **ROT47** may be the data is encrypted using the same we can try to decrypt this using [online tool](https://www.dcode.fr/rot-47-cipher) and we got our flag...

> Flag: CSOC23{b4by_sh4rk}
