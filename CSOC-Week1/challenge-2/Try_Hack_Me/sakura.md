# Sakura

## INTRODUCTION
---


![Screenshot from 2024-06-04 13-47-57](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/bbd3463e-007d-4910-a92f-4b5a7b922224)


> INTRODUCTION:Let's Go

##TIP-OFF

So as by reading instruction given to us, It hints us to read the meta data of the image [here](https://raw.githubusercontent.com/OsintDojo/public/3f178408909bc1aae7ea2f51126984a8813b0901/sakurapwnedletter.svg). So let us try to get the meta data of the image, Here I am using the command **exiftool** to do so.

![Screenshot from 2024-06-04 13-49-17](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/d29ce377-c0f7-4c9d-8b1a-c61fe0fc6b5e)


![Screenshot from 2024-06-04 13-56-07](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/9df56e9d-02ef-4ee7-9bfd-9f571eb4e943)

Here in the Export-Filename field we are given a directory location. 
as we know that by defalult the directory is as follows **/home/$username/path/to/file** so considering it in the same format we can say that the username for the Hacker is **SakuraSnowAngleAiko**\

> TIP-OFF: **SakuraSnowAngelAiko**

---

## RECONNAISSANCE

![Screenshot from 2024-06-04 13-59-36](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/21c23e1a-b22c-4346-9f72-af9e07ac95d8)

Reading the instruction we gets a hint that out attacker may have used the same username with different social media accounts. So let us try to find out here I am using **sherlock** to do so we cal also use othrt tools or try by directly searching the web.


![Screenshot from 2024-06-04 14-25-47](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/319ed04c-dd3d-4a09-bd9f-b8c2b739defb)

We know there are amny False/Positive results so let us try to visit the site one by one.
Doing this I find the github page of the attacker. 


![Screenshot from 2024-06-04 14-28-51](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/7a09f867-b6c3-478e-99e9-cbb73552966f)


going through the repositories I found something named **PGP**. We know PGP keys aur used to sign messages and encrypt messages.

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/c4cb0a02-bbe8-4204-99ff-01c8bad1a3bc)

Now, after searching online for couple of minutes I get to know how to extract user information from the **PGP** keys
Here is the screen show of the video where hi is using a software named **kleopatra**


![Screenshot from 2024-06-04 14-42-39](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/e4b22ca4-cfdf-416d-9a56-3debb41e1724)

using the same thing. I got this with the publick key I got from the repository.

![Screenshot from 2024-06-04 14-44-02](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/bbfc69a4-00d9-45b8-a26a-ed551bb55c0f)

> Email used: SakuraSnowAngel83@protonmail.com


Now let us try to search for the username on the web We got some results about a Twitter Account. with approximately same username or we can say a drived username also the first name is same so most probably we are on the correct profile 
Reading his posts I found something that He is introducing himself.

![Screenshot from 2024-06-04 15-41-01](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/f2c80398-9129-45a9-a224-37b2c3205b03)

![Screenshot from 2024-06-04 15-41-20](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/56f472a9-1aa1-4807-9a2c-8d65c7e7cf9a)

> Full name: Aiko Abe

---

## UNVEIL

![Screenshot from 2024-06-04 15-44-59](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/6da05852-6d43-460b-b03a-9a3c4575e62c)


Reading the instruction we got some hint that something important by which we can trace cryptocurrecy transections is deleted by the attacker.

So lets try to search over the repositories.

Looking over I found a repository named **ETH** with a single file

![Screenshot from 2024-06-04 16-01-30](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/975d66a9-d27b-4475-8f92-2c63b7f26d34)

![Screenshot from 2024-06-04 16-01-52](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/b709787e-95ee-4523-ae83-cc0d464472ac)

this lookis like some address aur token or something may be this is helpful for us but this is a proxy one so lets check for the commits


![Screenshot from 2024-06-04 16-29-56](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/262f71a1-bbcc-4921-9b0d-c0a384eae7b6)

here we got this id.

let us see whether we can track using this id or not.

![Screenshot from 2024-06-04 16-31-31](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/e8194902-cccb-4e47-adcc-c5fa6a58463e)

here i found a website lets head on to tha website hai check for the address we got

![Screenshot from 2024-06-04 16-31-45](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/e56066a8-0cc7-4bab-ae5b-8459031cb1d5)

Clearly it says that it is **Ethereum Address** so We get to know whats the name of cryptocurreny is 

> Cryptocurrency: **Ethereum**

also the address for the cryptocurrency is

> Address: **0xa102397dbeeBeFD8cD2F73A89122fCdB53abB6ef**

On the same site checking below for the transections
We need to find the transections for 23 Jan,2021 UTC
which will be 24 Jan,2021 in aur time belt as which is displaying over the website.

![Screenshot from 2024-06-04 16-39-06](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/86148895-5340-441f-8f80-b843ed2fb5f9)

looking around i found this transection from **Ethermine** to the attacker.

> Attacker recieved payment from: **Ethermine**

Checking more into the transection history I also find some transections to other crypto currency also i.e. **Tether USDT**


![Screenshot from 2024-06-04 16-42-46](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/cf90b223-8aca-4440-844c-765ff4601600)


> Other cryptocurrency: **Tether**

---

## TAUNT


![Screenshot from 2024-06-04 16-47-12](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/5376ca2a-4a93-4078-b7fe-ccfe1b84c079)


So we already know the twitter handle of attacker

> Twitter handle: **SakuraLoverAiko**

Now for the next question 

lets check the outhe twitter posts

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/d20fc07e-a55b-4fa3-b9a5-24cfc893925d)

On observing we see that DEEP and PASTE words are capatilised and the attacker is also discussing about the dark web So its hints about the **DEEPPASTE** on the darkweb


on searching about it i get to know the site no londer exists to we can't solve this further.

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/c49f970c-8a44-4868-8a03-428233c74c40)

but here the string provided is a md5 string so we have to search this string, which we have to search on DEEPPASTE where we can find wifi ssid


![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/455465dc-b507-48f4-94b3-77358570b666)

after getting the ssid we can use this site to find bssid.


---

## HOMEBOUND

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/6365cab2-5390-44fd-8fdb-ada7dc015862)

The photo uploaded by the attacker prior getting his flight is on his twitter handle

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/41f29475-8a64-480e-adf1-35d6cd0a72a8)

on zooming into the image we can see a large obelisk monument at the center of the image.
which is located in 
![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/3f2002eb-bf4d-4032-a683-77759a8a3da9)

further more looking in the image we can see that there is a train trak and water body in the right side of the image

so locating the similar kind of place using google maps 

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/fcce3bb9-8ece-4041-940d-761bd22d7a50)

marked sites are the possible location

zooming further it down 

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/dec6fb59-1337-4888-929c-310e7ca18a26)


this area have warter body , railway track and most importantly if we face towards the washington monument the railway track will appear to the right as that in tha image.

the name of this place is long bridge park 

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/9a04e58d-993a-4c05-b8d1-81788fce4577)



so let us try to search nearby airports to it
nearest airport is this 

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/8f7c542e-6e9f-4dba-bf57-b82035a49eb9)

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/e777cfc3-dda8-4d19-8cf5-d3929435488f)
> Code name: **DCA**



![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/c5725bc0-0a91-4756-86cf-6d6b4f3e3580)

trying to reversearch the image 

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/8b5e3325-bb26-4c33-815d-2c33d51a2b08)


the highlited link seems to be very similar with the logo with similar kind of foreground while other are bit different
opening the link and scrolling i found
![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/dbd21c61-0ca6-454a-a44d-973fc1811386)

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/8ebc8f07-7975-4f37-a563-f857ed093fef)

this proves that this logo is of Japan Airlines First Class Lounge in Tokyo HND

> Attacker have their last layover in launge at: **HND**


image shared by the Attacker

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/f0541012-970a-4cb7-a1da-54af9b4dad60)

looking for the flight route we found that the image shared by the attacker is of japan itself

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/6640916b-f49e-4d96-b92b-de59dbb222ed)

in the image shared by attacker we can easily spot a big lake like this

![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/b37c00ed-2267-400f-b59e-001ddf618394)

> name of the lake: Lake Inawashiro



reading the hint given
![image](https://github.com/nikunjagarwal17/BanditOverTheWire/assets/144536875/f0fa791b-46c3-4012-b2f6-ef9d1ef88089)

maybe this question be related to the question that we left earlier of wifi 

> City does the attacker likely consider "home": 
