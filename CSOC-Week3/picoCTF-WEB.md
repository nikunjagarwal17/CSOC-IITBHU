![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/2feffc42-9100-4e0c-95e2-a6f351860568)# Week-3: The World of Web

## 4-Secrets
[link](https://play.picoctf.org/practice/challenge/296?page=1&search=secrets)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/644c17c7-9178-482b-a37e-71ec67e6863b)

We are given with a site let go to the given website and look around 
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/f8f4b4be-1498-4692-a77e-5c2ca1c85e07)

lets try to check for the source code for the site.

Checking into the source code we got some strange looking directory in which the file is stored let try to wisit that directory
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/182a553d-e012-4afd-b34a-a6ad598f09d9)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/09dca6cb-726a-44cc-816a-1ae32e183016)

going into the parent one. here we foud something looks like are close to our flag.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/cd295223-cd9f-4dbf-ba00-8eddcbf4a88c)

checking for the source code again we once more found something strange directory lets check it out once more.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/fb9ce079-fe6d-4f3b-b2dd-85f923212da9)

moving to parent directory.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/f6b74d24-0331-4ac3-86a0-b2b30e41a042)

repeting the same once more got one more directory lets check it out

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/218684ee-1144-48d5-8faa-26506d5b68bf)

finally got our flag.

> Flag: picoCTF{succ3ss_@h3n1c@10n_790d2615}

## 6-Who are you?
[link](https://play.picoctf.org/practice/challenge/142)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/29ed070b-6877-422c-a61b-bd72dad85506)

opening the given website it gives us 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/bda70e02-25f0-48eb-acbd-95ee0e4e6ba1)

We already know that we can change the browser in the request using the burpsuit so lets fing out the request in the burpsuit in the **Proxy>HTTP history** section and move the request to the repeter.
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/ce2dff32-5258-4723-84da-cb2196f5c2ca)

now **Right Click and Send to Repeter** of press **Ctrl+R** to move the request to the repeter.

Now let modify the request accordingly. I am changing the User-Agent to the value of PicoBrowse

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/a4c25a12-9e68-4fa3-a9eb-0e48c2913cf4)

now it gives us 
> I don't trust users visiting from another site.

To fix this i am using the [Referer](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Referer) header and changing its value to [http://mercury.picoctf.net:34588/](http://mercury.picoctf.net:34588/) 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6b3e9728-a1e2-411b-ab63-b15c6894c04b)

now to said that 
> Sorry, this site only worked in 2018.

now lets overrite the date using [Date](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Date) Header lets say **14 feb 2018**

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/1cb9632b-4d67-4b60-949a-6e0be00e8aff)


now it said that 
> I don't trust users who can be tracked.

here we can use [DNT](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/DNT) header to make it "do not track"

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/a085be1b-a8c8-493b-bd66-963bec7a38e8)

now it said 
> This website is only for people from Sweden.

let fix ut the location using the [X-Forwarded-For](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/X-Forwarded-For) header with and [random sweden IP-Address](https://lite.ip2location.com/sweden-ip-address-ranges) like: **102.177.146.0** 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/b7ec4915-7de0-410d-bbe6-b25cd4c7396f)

> You're in Sweden but you don't speak Swedish?

to fix up the language I used [Accept-Language](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Accept-Language) header with the value "sv" for swedish language.


![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/148f505f-0e21-40ac-bf1b-c40070f7fb86)

and finally we got our flag

>Flag: picoCTF{http_h34d3rs_v3ry_c0Ol_much_w0w_79e451a7}






























