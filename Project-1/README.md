# Analysing a savefile Format

We will analyse the save file format of the stardew valley game.
so to get started lets make a new game to load.

i am creating a new game with teh following data 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/1189d0db-c408-4f11-91c2-e9913a8165a2)

now lets start the game first then looks into the save file 
we can find the sav fir for this game into ```%AppData%/Roming/StardewValley/Saves```

opening the directory we find two file here 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/47c6de98-2f2a-4f75-980f-25a67e2c2d69)

lets open both of them firstly in the notepad.

opening the save file we finds something like this. 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/78cf8a87-3775-41dc-81ad-c4863b147f3e)

this is xml language so this looks a bit simpler to edit the save file of this game.

here both of the files contains so much data.
lets try to firstly change the value of money.
seaching for the money in both the file and changing its value.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/676f73d6-98bf-489b-bc9d-409e3a0aa559)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6de7d084-8748-4ee8-bc4a-63105943b8b9)

upon reopenign the game we get
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/423f0329-b25c-4afd-b987-742c27ba012e)

Note: we have to change the values in both of the file that are common in between else it will corrupt the file.

lets took more in to the sav efile and check which bytes are for what data.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/4b7e5ccf-06cf-49f8-8eb7-5077fd954ed3)

here we can see that the data is didvided into different parts in which stores information of the different aspects of the data.
like items information. name position and many more.
we can also look for the xml in a more better way using [online tools](https://jsonformatter.org/xml-viewer)
using this we can understand the xml in more better way.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/19bb6a7c-42fb-460b-8d36-d7086722dc09)

playing the game for a while we can see tahat we have some of the value changes that will reflect into the save file.

lets try to change some more value like max stamina and stamina

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6926e6a7-d98a-4f27-9b33-b231d82f0444)

on changing 
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/38c40870-1e8b-482e-913d-2256f9eb7cd7)

and thus reflected in the game.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/cf3f2ed2-6f24-4e20-ad7f-2a2fb8ebd254)

in the similar way we can  change as many values as we want

[Link for the project Demo]()











