# Week-3: The World of Web

### Quick Links
- [1.1 Web Gauntlet](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#11-web-gauntlet)
- [1.2 Web Gauntlet 2](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#12-web-gauntlet-2)
- [1.3 Web Gauntlet 3](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#13-web-gauntlet-3)
- [2.1-Irish-Name-Repo 1](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#21-irish-name-repo-1)
- [2.2-Irish-Name-Repo 2](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#22-irish-name-repo-2)
- [2.3-Irish-Name-Repo 3](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#22-irish-name-repo-2)
- [3-JaWT Scratchpad](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#3-jawt-scratchpad)
- [4-Secrets](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#4-secrets)
- [5-Client-side-again](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#5-client-side-again)
- [6-Who are you?](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#6-who-are-you)
- [7-IntroToBurp](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#7-IntroToBurp)
- [8.1-Java Script Kiddie](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#81-java-script-kiddie)
- [8.2-Java Script Kiddie 2](https://github.com/nikunjagarwal17/CSOC-IITBHU/blob/main/CSOC-Week3/picoCTF-WEB.md#82-java-script-kiddie-2)


<br/><br/><br/><br/>



## 1.1 Web Gauntlet

[link](https://play.picoctf.org/practice/challenge/88)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/c187153a-0b0d-4b63-a3cb-6b8196bbeaeb)

Here we are provided with two links let try to open both one by one.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/c0d6658c-4bee-4b00-ae02-4bf992197722)

here is a login portal 
and on the filter page 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/58e3463e-068a-4b45-bbf3-4249772f9dd2)


so basically we have to perform SQL injection on the login portal keeping in mind that we have not to use the filtered words that means we cannot use the words in filter in our injection.

for the first round the filters are "or"

using SQL injection as ```username=admin'-- password=pass```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/670d46a9-d8cb-4a2e-8a35-f1037c64bca5)

Now we are on the second round we can check the new filters for the round in the filters.php page.

filters for second round "or and like = --" 
using ```username=admin'/* password=pass```

now we can't use the -- for commenting out the rest of the query but we can use /* */ for commenting out the query.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6fcb16f1-ff5b-4ff6-88de-52cff0b9514c)

filters for third round "or and = like > < --" 

using SQL injection as ```username=admin'/* password=pass```

we can still use /* for the comments.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6ed69f50-7bd2-4350-b7f0-795550ab37ec)


filters for fourth round "or and = like > < -- admin" 

using SQL injection as ```username=a'||'dmin'/* password=pass```

now we cannot use the admin word full at once so we have to figure out new way to put the admin word without using it actually
to do this we can use the concatination operator **(||)** to join the different string that fully makes up the word admin.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/378b756d-1e7f-430f-80ec-3c44803b0ca3)

filters for fifth round "or and = like > < -- union admin" 

using SQL injection as ```username=a'||'dmin'/* password=pass``` 

we can use the same logic that of the last one.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6d4f06dd-ad78-493d-acf6-f4f8e17cadab)

we can now checkout filter.php to get our flag

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/37dc7b84-d83a-4dc4-9024-7df57f4ead27)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/887240a7-e9e3-4030-b768-db4402550e00)

> Flag: picoCTF{y0u_m4d3_1t_275cea1159781d5b3ef3f57e70be664a}


## 1.2 Web Gauntlet 2

[link](https://play.picoctf.org/practice/challenge/174)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/331c7c08-91f5-4795-bf5f-51637cd96c29)

Now in this challenge we are provided with new filters and we have to perform the sqli injection

Filters are "or and true false union like = > < ; -- /* */ admin"

we can use ```username=a'||'dmin``` to get the admin username but we cannot use any of the commenting caracters to comment out the remaining query so now to have to figure out a way to bypass the password check.

to bypass the password check we can use the wildcard to match the patterns using **glob** with **'*'** as wildcard patters to get the any password for any user with username as admin.

```username=a'||'dmin password=' glob '*```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/3b1bced0-8191-416f-8d0f-7e1a0f8556a9)

this makes the final query as 
```sql
SELECT username, password FROM users WHERE username='a'||'dmin' AND password='' glob '*'
```
which means any user with username admin and with any password.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/afd469e2-ee71-4e10-b3d2-b09b14f8d0dc)

here is out flag

> Flag: picoCTF{0n3_m0r3_t1m3_d5a91d8c2ae4ce567c2e8b8453305565}



## 1.3 Web Gauntlet 3

[link](https://play.picoctf.org/practice/challenge/128)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/21da835b-f991-4d85-9224-9ddbceec6847)

Now we are given with some more strict filters lets checkout the filters first on the filters.php page.

Filters are: "or and true false union like = > < ; -- /* */ admin"

luckiely we can use the glob keyword here also since it is not filtered out.
so using the same injection as of the previos challenge we can get out flag.

```username=a'||'dmin password=' glob '*```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/c7b559a0-2421-4ccc-850a-cf086687c43b)

and it works 

here is out flag.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/5627eee6-2999-4411-aec0-7903e4bf502b)

> Flag: picoCTF{k3ep_1t_sh0rt_fc8788aa1604881093434ba00ba5b9cd}


## 2.1-Irish-Name-Repo 1
[link](https://play.picoctf.org/practice/challenge/80?page=1&search=irish)


![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/78ba1fb6-4bfe-49ae-8cbb-023683fbefa2)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/c5cd368e-d3f7-40e3-a0d0-9468e2185572)

going to the website provided looking around we can find a login system in the side menu now firstly we can try some SQl injection to get into this using the simple username **'or'1'='1'--** as payload
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/4caa93f4-7015-45d8-964d-bfc54ac6c832)

and we got it 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/35bab7aa-0664-4dd9-afd8-0a594448306a)

we can also solve the following challenge using **curl**
like this.
here is the login page that we get we can check this using the command 
```shell
curl https://jupiter.challenges.picoctf.org/problem/39720/login.html
```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/3a7a398c-c64f-4646-9311-a276d8bc535d)

now we can send username and password also debug parameters to login.php page using the following command
```shell
curl https://jupiter.challenges.picoctf.org/problem/39720/login.php --data "username='+or+1=1--&password=pass&debug=1"
```
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/2cdae11a-5c91-4f4b-bb2a-2e379c640fde)
here we got out flag.

we can set the debug parameter to 1 to also get the sql query used in the result.


> Flag: picoCTF{s0m3_SQL_c218b685}
<br/>

## 2.2-Irish-Name-Repo 2
[link](https://play.picoctf.org/practice/challenge/59)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/63bf00ce-2717-42a8-8d2c-982159e19599)

Again we are given with the same website and we have to perform a sqli injection to login into the admin panel,
trying the solution of the last question didn't work obviously.
lets try something new.

we have to login with the username as **admin** as it is the most common username used for the admin user

lets do the following injection username **admin'--** password **pass**.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/47ab5148-06d7-4dfc-9ecd-be0ae3d0a8bd)

and we are done

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/e06769b8-f0b0-4966-95de-4a80c21434df)

we can also solve the following challenge using **curl**
like this.


Simillarly we can also solve this using the **curl**

firslty here is the page used for the loging portal.
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/45b372aa-fc50-42bb-b89a-fe127b1d550e)

lets perform sql injection on the same parameters,
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/fe9928db-8b50-4d47-99f1-a1b1a5702790)

> Flag: picoCTF{m0R3_SQL_plz_fa983901}

## 2.3-Irish-Name-Repo 3

[link](https://play.picoctf.org/practice/challenge/8)

here is the page used for the login portal.
![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/ec6b5ed2-4892-4e3a-b6c1-1c93f69d1055)

here we only have to enter the password lets try to perform dummy password to get whats actually is happening.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/5ba8bab8-2d9a-4d1e-ad17-3a52f0c4c4ef)

we can clearly get taht we entered out password as **pass** but it is interpreted in the query as **cnff** it looks like it is shift cipher and shifted
- p to c , a to n , and so on....

so in order to break the shift cipher we can use out injection as reversed shifted so that when it shift automatically in the server the query get breaks.

we can use the following injection "**' be 1=1--**" to login into the pertal

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/7a72bb4d-b13e-4c88-8b41-b0eb47611088)

here we got our flag.

> Flag: picoCTF{3v3n_m0r3_SQL_06a9db19}


## 3-JaWT Scratchpad
[link](https://play.picoctf.org/practice/challenge/25)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/e26c07e0-fad7-40e2-9171-44c7dc1db179)

Opening the link in the browser 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6135ea09-b5c9-42f5-8cd7-f41f09a5c6ea)

lets try to connect to the website.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/cfa497ac-0022-4f1a-86ad-4fb56b3e13aa)

lets first try to login as **admin** 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/80e7238d-2e7a-49f5-82ec-bd77532e4522)

we can't login with the username as admin lets try something different.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/499b30d7-0ec2-4e61-b3cc-a83944ead5da)


we are getting a [JWT TOKEN](https://en.wikipedia.org/wiki/JSON_Web_Token) lets try to decode it using [this tool](https://jwt.io/)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/8ee887fe-adf3-414d-97b8-b3432c6d626d)

JSON Web Token
```eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJ1c2VyIjoiZDRya200NzczciJ9.tDxUhvFeGEy_AvMAOTBTibmaE5aV4Nm08Pd1-JYB7cs```

we can't directly modify the data : user to admin as it didn't works here coz of the signature verification.
we cannot directly guess the signature but can use different techniques to bruteforce the signature key 
I am using [jwt_tool](https://github.com/ticarpi/jwt_tool?tab=readme-ov-file) and reffering this [video](https://www.youtube.com/watch?v=2RKCDhH6dyA) it has a pretty well explaination of the same case.

lets try to bruteforce the webtoken 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/5ad1d5ec-c102-4f92-9e5a-349b327f921a)

here we got our secret key ```ilovepico``` 
now lets try to modify out JSON Web Token as we already know our key 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/169eaa57-4d07-4eb1-94ef-1e980095967c)

New JSON Web Token

```eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJ1c2VyIjoiYWRtaW4ifQ.gtqDl4jVDvNbEe_JYEZTN19Vx6X9NNZtRVbKPBkhO-s```

lets try to send this newly generated JSON Web Token in our request 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/b4b81f40-f37f-4fe4-8cc4-acc2aeaaac59)

here we got our flag.
> Flag: picoCTF{jawt_was_just_what_you_thought_1ca14548}





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


## 5-Client-side-again
[link](https://play.picoctf.org/practice/challenge/69)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/99906af7-824a-45a7-8441-4217bb7fa2d5)

taking look into the website we got a login function.
checking for the basic sql injection it doesnt reults anything.
let us take a look back to the challenge name **Client Side** this hints us like something is hidden on out own side so lets first check for the source code of the site here we got a java script used for checking the password.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/430d6e23-ce88-4896-9b15-3e2e8492584c)

let us read the script and reverse it to get the required password

So the script is as follows:

initialize a array to be used in the program
```js
var _0x5a46 = ['f49bf}', '_again_e', 'this', 'Password\x20Verified', 'Incorrect\x20password', 'getElementById', 'value', 'substring', 'picoCTF{', 'not_this'];
```
then the array is rotated to make it harder to read 
```js
(function(_0x4bd822, _0x2bd6f7) {
    var _0xb4bdb3 = function(_0x1d68f6) {
        while (--_0x1d68f6) {
            _0x4bd822['push'](_0x4bd822['shift']());
        }
    };
    _0xb4bdb3(++_0x2bd6f7);
}(_0x5a46, 0x1b3));
```
it is rotated 0x1b3 i.e. 435 times wich is equivalent to 435 % 10 = 5 times since the length of array is 10.
so the resultant array will be
```js
['getElementById', 'value', 'substring', 'picoCTF{', 'not_this', 'f49bf}', '_again_e', 'this', 'Password\x20Verified', 'Incorrect\x20password']
```
now this function is used to get the values at the particular index
```js
var _0x4b5b = function(_0x2d8f05, _0x4b81bb) {
    _0x2d8f05 = _0x2d8f05 - 0x0;
    var _0x4d74cb = _0x5a46[_0x2d8f05];
    return _0x4d74cb;
};
```
and finally the veryfy function check the values like this 

- first 8 characters are picoCTF{.
- characters from position 7 to 9 are {n.
- characters from position 8 to 16 are not_this.
- characters from position 3 to 6 are oCT.
- characters from position 24 to 32 are not_this.
- characters from position 6 to 11 are F{not.
- characters from position 16 to 24 are again_e.
- characters from position 12 to 16 are f49bf}.

so the required string that we got is 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/73f81810-e024-417b-ab06-4c5a69da6523)

> Flag: picoCTF{not_this_again_ef49bf}





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



## 7-IntroToBurp
[link](https://play.picoctf.org/practice/challenge/419)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/0baaae41-6e1e-409b-8990-111eead83aa0)

as mentioned lets try to open the website in burp suit
we are given a registration portal in which we have to fill the details and then we are asked for a otp.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/7614380d-57f7-44bb-87fe-53e992e52734)

trying for the random number and checking for the request in the burpsuit

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/851d1008-33d1-49a5-8bc0-051ec585512d)

lets send this request to the repeter to modify the request

on trying for different attaks like sql injection, bruteforcing didn't get the result 
on trying get a silly idea to rename the paremets to anything other 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/e93a5f7e-6d03-4b19-bf28-4164479ead34)

and we got our flag, 
Silly idea but that it is. :)

> Flag: picoCTF{#0TP_Bypvss_SuCc3$S_e1eb16ed}


## 8.1-Java Script Kiddie

[link](https://play.picoctf.org/practice/challenge/29)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/fcb53ee5-e110-41fa-9d3c-01e06f15364b)

Going to the site, it provides us with a text box and a button only. on entering any value to it and submitting it gives us a broken image.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/ed9d04b2-29b2-4a94-ba89-b328db12d7fb)

On checking for the source code we get a java script in it which is intended to accept a 16 digit key and then use this key to decrypt the image data preent in form of bytes on the /bytes page 

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/1e4f4ccf-6305-4feb-8243-18bc927ec331)

we have to find out a way to get a key by reversing the code or by bruteforcing.
Obviously bruteforcing is not really a good choise is it leads to 16^10 combinations which is not fisible so lets try to understand the script and reverse it


the page source is as follows.
```html
<html>
	<head>    
		<script src="jquery-3.3.1.min.js"></script>
		<script>
			var bytes = [];
			$.get("bytes", function(resp) {
				bytes = Array.from(resp.split(" "), x => Number(x));
			});

			function assemble_png(u_in){
				var LEN = 16;
				var key = "0000000000000000";
				var shifter;
				if(u_in.length == LEN){
					key = u_in;
				}
				var result = [];
				for(var i = 0; i < LEN; i++){
					shifter = key.charCodeAt(i) - 48;
					for(var j = 0; j < (bytes.length / LEN); j ++){
						result[(j * LEN) + i] = bytes[(((j + shifter) * LEN) % bytes.length) + i]
					}
				}
				while(result[result.length-1] == 0){
					result = result.slice(0,result.length-1);
				}
				document.getElementById("Area").src = "data:image/png;base64," + btoa(String.fromCharCode.apply(null, new Uint8Array(result)));
				return false;
			}
		</script>
	</head>
	<body>

		<center>
			<form action="#" onsubmit="assemble_png(document.getElementById('user_in').value)">
				<input type="text" id="user_in">
				<input type="submit" value="Submit">
			</form>
			<img id="Area" src=""/>
		</center>

	</body>
</html>
```

and the bytes are: (checkout on /bytes page)
```
87 130 78 188 0 84 26 157 143 239 249 82 248 212 239 82 195 80 1 207 13 6 1 0 119 243 73 193 78 36 133 108 85 0 0 14 0 186 68 0 0 222 0 243 0 24 174 163 126 0 133 252 137 177 121 10 0 0 0 237 73 63 0 100 96 20 3 224 59 171 16 114 0 0 0 69 0 68 68 147 137 179 110 112 74 121 238 65 1 0 156 0 155 0 95 120 0 233 226 40 78 194 248 44 84 0 208 13 41 72 138 59 164 98 71 0 209 0 99 176 97 120 202 0 135 192 54 101 64 252 81 71 205 10 243 133 30 22 125 237 3 93 90 42 73 221 25 114 243 0 116 22 4 3 59 75 188 119 169 221 161 184 178 2 73 73 231 45 14 99 102 153 166 178 206 54 127 84 240 191 220 10 163 81 64 206 128 132 102 197 72 127 239 253 78 93 8 22 239 207 146 111 143 239 27 243 28 0 173 159 196 48 247 28 84 98 63 52 171 214 214 26 233 254 65 106 111 59 73 255 148 111 103 91 20 206 222 70 252 199 161 124 245 188 102 81 159 119 174 51 190 243 55 243 156 249 124 125 2 143 191 27 119 139 126 88 18 247 171 227 72 66 54 251 0 80 171 146 113 173 4 79 211 216 214 122 119 115 225 45 24 54 44 76 43 253 5 235 104 248 96 8 229 200 75 64 233 217 23 87 40 254 187 107 181 200 181 233 181 81 231 171 165 82 254 196 239 51 43 114 170 73 249 50 114 201 138 64 11 203 155 192 249 226 35 188 156 223 40 217 67 75 100 45 93 102 169 13 34 197 80 175 210 128 137 201 167 45 140 82 171 56 212 17 126 113 139 229 127 223 181 15 0 116 221 186 219 230 56 233 31 15 249 74 119 152 44 41 226 60 35 253 172 97 32 137 233 165 35 181 104 80 217 56 186 205 212 15 64 81 230 230 153 62 251 251 47 151 141 108 32 25 65 11 253 119 201 147 243 11 31 247 233 54 126 217 136 141 191 226 137 213 131 239 100 145 151 150 119 124 159 203 190 63 18 170 210 175 122 223 223 114 124 59 93 245 177 100 15 57 63 239 165 144 13 149 32 198 39 52 53 113 97 91 186 76 91 74 207 133 208 0 245 241 245 73 122 193 223 159 82 175 241 159 231 205 24 92 75 11 247 77 55 170 7 95 127 143 96 207 242 142 153 226 242 93 163 110 185 26 188 4 178 102 159 97 53 58 186 172 239 6 78 215 65 156 90 150 112 205 73 76 149 163 159 242 45 147 16 210 49 254 82 126 200 30 62 190 230 2 86 171 181 197 185 132 170 153 82 191 154 235 147 55 57 92 252 48 207 118 191 170 253 53 127 94 143 122 230 254 154 151 186 55 160 132 126 57 183 217 129 181 95 255 35 223 50 70 77 107 100 203 17 61 163 17 227 147 182 184 79 126 239 28 115 159 254 111 90 250 14 206 185 137 187 141 231 211 241 249 39 99 131 95 210 50 147 241 95 127 103 239 113 165 223 164 245 35 231 132 166 220 241 207 67 178 148 29 156 94 194 74 222 110 0 243 107 158 173 214 210 249 84 66 107 40 0 203 138 164 0 241 9 109 147 207 85 29 204 0
```
lets try to understand the code:

so basically

- the script wanted us to enter a valid 16 digit key to decode the image correctly elce it will be broken.
- the function is as follows it takes the first value of the key entered convert it into ascii code apply some functions and then stores into a result array again applying some basic manupulation.
- and then finally converts that result array into png data.
- if the key entered is wrong it configures the result array in wrong way hence giving us a broken or corrupted image.


one more hint is given to us that the image is of png format 

```js

...
document.getElementById("Area").src = "data:image/png;base64," + btoa(String.fromCharCode.apply(null, new Uint8Array(result)));
...

```

already knowing that we ahve teh image format as png to we can use this to get our key as we already know that the some begining bytes of a png image remains constant all over

opening any of the random png image data in the hex we can fing out that the first 16 bytes of a PNG image are:

```
First 16 bytes: 0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x0, 0x0, 0x0, 0x0d, 0x49, 0x48, 0x44, 0x52

```

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/c57ab5ab-2b61-423a-8b05-5d635ee6f3a5)

so now we have got our starting bytes now lets try to reverse the script to get the correct key.

here is a script that i have used to get our right key and get the flag.

```html
<!DOCTYPE html>
<html>
<head>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/lodash.js/4.17.15/lodash.min.js"></script>
  </head>
  <body id="space">
    <script>
      var bytes = Array.from(('87 130 78 188 0 84 26 157 143 239 249 82 248 212 239 82 195 80 1 207 13 6 1 0 119 243 73 193 78 36 133 108 85 0 0 14 0 186 68 0 0 222 0 243 0 24 174 163 126 0 133 252 137 177 121 10 0 0 0 237 73 63 0 100 96 20 3 224 59 171 16 114 0 0 0 69 0 68 68 147 137 179 110 112 74 121 238 65 1 0 156 0 155 0 95 120 0 233 226 40 78 194 248 44 84 0 208 13 41 72 138 59 164 98 71 0 209 0 99 176 97 120 202 0 135 192 54 101 64 252 81 71 205 10 243 133 30 22 125 237 3 93 90 42 73 221 25 114 243 0 116 22 4 3 59 75 188 119 169 221 161 184 178 2 73 73 231 45 14 99 102 153 166 178 206 54 127 84 240 191 220 10 163 81 64 206 128 132 102 197 72 127 239 253 78 93 8 22 239 207 146 111 143 239 27 243 28 0 173 159 196 48 247 28 84 98 63 52 171 214 214 26 233 254 65 106 111 59 73 255 148 111 103 91 20 206 222 70 252 199 161 124 245 188 102 81 159 119 174 51 190 243 55 243 156 249 124 125 2 143 191 27 119 139 126 88 18 247 171 227 72 66 54 251 0 80 171 146 113 173 4 79 211 216 214 122 119 115 225 45 24 54 44 76 43 253 5 235 104 248 96 8 229 200 75 64 233 217 23 87 40 254 187 107 181 200 181 233 181 81 231 171 165 82 254 196 239 51 43 114 170 73 249 50 114 201 138 64 11 203 155 192 249 226 35 188 156 223 40 217 67 75 100 45 93 102 169 13 34 197 80 175 210 128 137 201 167 45 140 82 171 56 212 17 126 113 139 229 127 223 181 15 0 116 221 186 219 230 56 233 31 15 249 74 119 152 44 41 226 60 35 253 172 97 32 137 233 165 35 181 104 80 217 56 186 205 212 15 64 81 230 230 153 62 251 251 47 151 141 108 32 25 65 11 253 119 201 147 243 11 31 247 233 54 126 217 136 141 191 226 137 213 131 239 100 145 151 150 119 124 159 203 190 63 18 170 210 175 122 223 223 114 124 59 93 245 177 100 15 57 63 239 165 144 13 149 32 198 39 52 53 113 97 91 186 76 91 74 207 133 208 0 245 241 245 73 122 193 223 159 82 175 241 159 231 205 24 92 75 11 247 77 55 170 7 95 127 143 96 207 242 142 153 226 242 93 163 110 185 26 188 4 178 102 159 97 53 58 186 172 239 6 78 215 65 156 90 150 112 205 73 76 149 163 159 242 45 147 16 210 49 254 82 126 200 30 62 190 230 2 86 171 181 197 185 132 170 153 82 191 154 235 147 55 57 92 252 48 207 118 191 170 253 53 127 94 143 122 230 254 154 151 186 55 160 132 126 57 183 217 129 181 95 255 35 223 50 70 77 107 100 203 17 61 163 17 227 147 182 184 79 126 239 28 115 159 254 111 90 250 14 206 185 137 187 141 231 211 241 249 39 99 131 95 210 50 147 241 95 127 103 239 113 165 223 164 245 35 231 132 166 220 241 207 67 178 148 29 156 94 194 74 222 110 0 243 107 158 173 214 210 249 84 66 107 40 0 203 138 164 0 241 9 109 147 207 85 29 204 0'.split(' ')), x => Number(x));
      


      var pngHeader = [0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x0, 0x0, 0x0, 0x0d, 0x49, 0x48, 0x44, 0x52];
      var bytesOccurrences = _.countBy(bytes);
      var decodedKey = [];
      var multipleBlocks = [];

      for (var i = 0; i < pngHeader.length; i++) {
        const bt = pngHeader[i];
        const btCount = bytesOccurrences[bt];
        var btIdx = bytes.indexOf(bt);
        var validBlocks = 0;

        // Multiple occurrences, find valid (% 16 = 0) item
        for (var j = 0; j < btCount; j++) {
          if ((btIdx - i) % 16 === 0 && ((btIdx - i) / 16) < 10) {
            decodedKey[i] = ((btIdx - i) / 16).toString();
            validBlocks++;

            if (!multipleBlocks[i]) multipleBlocks[i] = [];
            multipleBlocks[i].push(decodedKey[i]);
          }

          btIdx = bytes.indexOf(bt, btIdx + 1);
        }

        if (validBlocks > 1) {
          console.log(`More than one valid block for: ${bt} at ${i} with count of ${validBlocks}`)
        }

      }


      function generate_keys(arg) {
        var r = [], max = arg.length-1;
        function helper(arr, i) {
            for (var j=0, l=arg[i].length; j<l; j++) {
                var a = arr.slice(0);
                a.push(arg[i][j]);
                if (i==max)
                    r.push(a);
                else
                    helper(a, i+1);
            }
        }
        helper([], 0);
        return r;
      }

      var keys = generate_keys(multipleBlocks);

      console.log(`Generating images`)

      keys.forEach(key => {
        document.write(key.join('') + ': ');
        assemble_png(key.join(''));
      });

      decodedKey = decodedKey.join('');

      function addImage(glob, result) {
        var fragment = document.createDocumentFragment();
        var img = document.createElement('img');
        img.src = "data:image/png;base64," + btoa(String.fromCharCode.apply(null, new Uint8Array(result)));
        fragment.appendChild(img);

        return glob.appendChild(fragment);
      }

      // Original function
      function assemble_png(u_in){
        var LEN = 16;
        var key = "0000000000000000";
        var shifter;
        if(u_in.length == LEN){
          key = u_in;
        }

        var result = [];
        for(var i = 0; i < LEN; i++){
          shifter = key.charCodeAt(i) - 48;
          for(var j = 0; j < (bytes.length / LEN); j++){
            result[(j * LEN) + i] = bytes[(((j + shifter) * LEN) % bytes.length) + i]
          }
        }
        while(result[result.length-1] == 0){
          result = result.slice(0,result.length-1);
        }

        addImage(document.getElementById('space'), result);
      }
    </script>
  </body>
</html>

```

**Explaination:** here is what this script does.

- iterates for each value present in the png header
- counts the number of occurance of that bytes in the bytes array
- gets index of the first occurance
- then check if that occurance of the particular byte at the particular index is valid
- if yes added it to the array and increase number of vaid block
- then checks if the next occurance of that byte is valid and so on...
- and so on for each byte in png header.
- storing all the data in multipleBlocks array.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/117fdf01-a84e-45f1-9d6b-80ca80e7396d)

- after getting all the possible combinations of keys the keys are generated and the image corresponding to that key is displayed

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/05e4dc33-ccdc-40f8-b36c-a749a6611092)

Running the script we get a QR code on reading which we can get our flag.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/8282e636-43a6-422d-8867-f414c0d68524)

We can also check for the data in console

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/45ae7c89-bf7e-4b9e-974c-8f0b6d83565f)

We got a total of 24 possible combinations for the keys.

Scanning the QR using [online tool](https://scanqr.org/) gives us the flag.

> Flag:  picoCTF{066cad9e69c5c7e5d2784185c0feb30b}



## 8.2-Java Script Kiddie 2

[link](https://play.picoctf.org/practice/challenge/33)

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/d45fb938-025f-46a9-84f1-fc76d26aaf7a)

We are provided with the same stuff as of the previous challenge just the key size is doubled.
and the ```js shifter = Number(key.slice((i*2),(i*2)+1));``` is also different but only takes every second byte which means even the key length is 32 but only 16 bytes are used.

the page source is as follows:
```html
<html>
	<head>    
		<script src="jquery-3.3.1.min.js"></script>
		<script>
			var bytes = [];
			$.get("bytes", function(resp) {
				bytes = Array.from(resp.split(" "), x => Number(x));
			});

			function assemble_png(u_in){
				var LEN = 16;
				var key = "00000000000000000000000000000000";
				var shifter;
				if(u_in.length == key.length){
					key = u_in;
				}
				var result = [];
				for(var i = 0; i < LEN; i++){
					shifter = Number(key.slice((i*2),(i*2)+1));
					for(var j = 0; j < (bytes.length / LEN); j ++){
						result[(j * LEN) + i] = bytes[(((j + shifter) * LEN) % bytes.length) + i]
					}
				}
				while(result[result.length-1] == 0){
					result = result.slice(0,result.length-1);
				}
				document.getElementById("Area").src = "data:image/png;base64," + btoa(String.fromCharCode.apply(null, new Uint8Array(result)));
				return false;
			}
		</script>
	</head>
	<body>

		<center>
			<form action="#" onsubmit="assemble_png(document.getElementById('user_in').value)">
				<input type="text" id="user_in">
				<input type="submit" value="Submit">
			</form>
			<img id="Area" src=""/>
		</center>

	</body>
</html>

```

the bytes values for this challenge are (check on /bytes page)

```
228 80 39 113 0 148 0 143 252 172 225 6 220 243 68 255 63 0 164 243 13 127 26 30 158 48 174 68 6 119 95 128 200 0 191 28 0 107 1 69 243 234 78 13 176 66 110 174 27 16 188 71 135 228 68 235 100 192 219 0 235 72 229 231 56 148 150 114 141 247 101 254 172 69 171 237 90 192 73 117 43 154 78 2 150 254 129 252 124 0 255 71 174 77 152 91 137 13 1 95 69 59 180 0 164 0 78 233 73 171 255 245 0 197 0 0 133 0 243 10 255 120 0 85 0 153 129 195 164 223 70 170 205 10 48 114 73 28 0 243 154 253 15 130 48 32 220 62 37 0 35 65 0 216 156 170 129 59 90 82 112 104 153 12 45 73 221 105 1 147 32 98 68 221 137 108 66 208 191 111 29 45 30 190 84 239 166 159 118 77 151 164 140 250 34 210 24 45 211 223 164 197 74 30 206 132 127 102 111 36 153 144 9 75 10 206 89 102 188 212 103 191 71 20 156 126 73 179 227 131 33 69 226 223 96 88 214 252 91 248 142 219 199 161 196 98 96 0 59 125 205 3 74 206 60 30 69 210 115 144 166 73 249 122 128 229 153 237 231 205 252 122 71 0 143 190 70 255 103 200 65 136 172 166 227 56 55 178 248 255 245 247 24 170 253 165 156 130 31 95 61 57 148 55 159 255 31 96 26 195 185 96 129 252 233 36 36 92 146 111 113 180 242 210 175 208 29 63 102 246 172 154 248 191 12 248 22 153 140 180 61 151 111 0 138 113 101 89 73 125 184 15 12 8 65 144 72 239 249 63 168 110 239 198 158 57 79 235 35 165 197 248 51 223 107 7 132 217 126 255 169 201 223 33 206 181 158 1 166 55 247 219 91 91 14 248 115 149 105 93 117 130 242 84 226 148 83 84 232 117 181 155 51 31 4 180 252 237 161 195 206 164 175 75 19 245 194 65 186 239 62 253 211 111 130 154 24 254 201 214 194 254 105 173 174 5 159 173 8 180 114 23 202 53 39 243 173 87 59 95 61 69 64 219 122 143 62 8 136 51 98 146 128 67 241 126 216 166 166 234 242 191 207 157 242 53 254 39 78 197 215 197 26 33 176 36 193 113 151 211 131 57 158 179 86 113 139 116 59 100 7 189 164 45 200 251 122 12 223 253 179 103 74 228 254 89 155 83 5 173 32 230 126 201 199 199 86 91 126 114 62 105 91 132 183 188 243 193 77 217 243 167 201 190 123 71 196 110 117 115 76 58 103 61 190 114 58 130 232 110 171 147 243 73 157 202 30 235 240 239 174 224 172 149 53 141 170 206 34 55 212 227 229 152 130 217 221 155 221 102 48 87 109 62 235 107 150 58 64 18 142 4 187 24 70 133 180 175 223 13 22 191 126 255 188 198 73 119 40 156 95 111 160 79 155 223 234 138 98 7 145 127 26 141 174 207 179 31 191 122 251 233 191 79 174 130 160 190 232 244 231 191 225 105 222 159 253 46 37 155 3 212 182 239 250 149 102 196 245 107 225 95 126 186 126 233 226 147 189 51 197 30 206 77 239 128 184 176 255 106 236 145 96 160
```

we can use the same script to decode our flag just by modifying the bytes values coz the algorithm used for endoding our image is same just using every second value of the key.

here is modified script.
```html
<!DOCTYPE html>
<head>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/lodash.js/4.17.15/lodash.min.js"></script>
  </head>
  <body id="space">
    <script>
      var bytes = Array.from(('228 80 39 113 0 148 0 143 252 172 225 6 220 243 68 255 63 0 164 243 13 127 26 30 158 48 174 68 6 119 95 128 200 0 191 28 0 107 1 69 243 234 78 13 176 66 110 174 27 16 188 71 135 228 68 235 100 192 219 0 235 72 229 231 56 148 150 114 141 247 101 254 172 69 171 237 90 192 73 117 43 154 78 2 150 254 129 252 124 0 255 71 174 77 152 91 137 13 1 95 69 59 180 0 164 0 78 233 73 171 255 245 0 197 0 0 133 0 243 10 255 120 0 85 0 153 129 195 164 223 70 170 205 10 48 114 73 28 0 243 154 253 15 130 48 32 220 62 37 0 35 65 0 216 156 170 129 59 90 82 112 104 153 12 45 73 221 105 1 147 32 98 68 221 137 108 66 208 191 111 29 45 30 190 84 239 166 159 118 77 151 164 140 250 34 210 24 45 211 223 164 197 74 30 206 132 127 102 111 36 153 144 9 75 10 206 89 102 188 212 103 191 71 20 156 126 73 179 227 131 33 69 226 223 96 88 214 252 91 248 142 219 199 161 196 98 96 0 59 125 205 3 74 206 60 30 69 210 115 144 166 73 249 122 128 229 153 237 231 205 252 122 71 0 143 190 70 255 103 200 65 136 172 166 227 56 55 178 248 255 245 247 24 170 253 165 156 130 31 95 61 57 148 55 159 255 31 96 26 195 185 96 129 252 233 36 36 92 146 111 113 180 242 210 175 208 29 63 102 246 172 154 248 191 12 248 22 153 140 180 61 151 111 0 138 113 101 89 73 125 184 15 12 8 65 144 72 239 249 63 168 110 239 198 158 57 79 235 35 165 197 248 51 223 107 7 132 217 126 255 169 201 223 33 206 181 158 1 166 55 247 219 91 91 14 248 115 149 105 93 117 130 242 84 226 148 83 84 232 117 181 155 51 31 4 180 252 237 161 195 206 164 175 75 19 245 194 65 186 239 62 253 211 111 130 154 24 254 201 214 194 254 105 173 174 5 159 173 8 180 114 23 202 53 39 243 173 87 59 95 61 69 64 219 122 143 62 8 136 51 98 146 128 67 241 126 216 166 166 234 242 191 207 157 242 53 254 39 78 197 215 197 26 33 176 36 193 113 151 211 131 57 158 179 86 113 139 116 59 100 7 189 164 45 200 251 122 12 223 253 179 103 74 228 254 89 155 83 5 173 32 230 126 201 199 199 86 91 126 114 62 105 91 132 183 188 243 193 77 217 243 167 201 190 123 71 196 110 117 115 76 58 103 61 190 114 58 130 232 110 171 147 243 73 157 202 30 235 240 239 174 224 172 149 53 141 170 206 34 55 212 227 229 152 130 217 221 155 221 102 48 87 109 62 235 107 150 58 64 18 142 4 187 24 70 133 180 175 223 13 22 191 126 255 188 198 73 119 40 156 95 111 160 79 155 223 234 138 98 7 145 127 26 141 174 207 179 31 191 122 251 233 191 79 174 130 160 190 232 244 231 191 225 105 222 159 253 46 37 155 3 212 182 239 250 149 102 196 245 107 225 95 126 186 126 233 226 147 189 51 197 30 206 77 239 128 184 176 255 106 236 145 96 160'.split(' ')), x => Number(x));

      var pngHeader = [0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x0, 0x0, 0x0, 0x0d, 0x49, 0x48, 0x44, 0x52];
      var bytesOccurrences = _.countBy(bytes);
      var decodedKey = [];
      var multipleBlocks = [];

      for (var i = 0; i < pngHeader.length; i++) {
        const bt = pngHeader[i];
        const btCount = bytesOccurrences[bt];
        var btIdx = bytes.indexOf(bt);
        var validBlocks = 0;

        // Multiple occurrences, find valid (% 16 = 0) item
        for (var j = 0; j < btCount; j++) {
          if ((btIdx - i) % 16 === 0 && ((btIdx - i) / 16) < 10) {
            decodedKey[i] = ((btIdx - i) / 16).toString();
            validBlocks++;

            if (!multipleBlocks[i]) multipleBlocks[i] = [];
            multipleBlocks[i].push(decodedKey[i]);
          }

          btIdx = bytes.indexOf(bt, btIdx + 1);
        }

        if (validBlocks > 1) {
          console.log(`More than one valid block for: ${bt} at ${i} with count of ${validBlocks}`)
        }

      }


      function generate_keys(arg) {
        var r = [], max = arg.length-1;
        function helper(arr, i) {
            for (var j=0, l=arg[i].length; j<l; j++) {
                var a = arr.slice(0);
                a.push(arg[i][j]);
                if (i==max)
                    r.push(a);
                else
                    helper(a, i+1);
            }
        }
        helper([], 0);
        return r;
      }

      var keys = generate_keys(multipleBlocks);

      console.log(`Generating images`)

      keys.forEach(key => {
        document.write(key.join('') + ': ');
        assemble_png(key.join(''));
      });

      decodedKey = decodedKey.join('');

      function addImage(glob, result) {
        var fragment = document.createDocumentFragment();
        var img = document.createElement('img');
        img.src = "data:image/png;base64," + btoa(String.fromCharCode.apply(null, new Uint8Array(result)));
        fragment.appendChild(img);

        return glob.appendChild(fragment);
      }

      // Original function
      function assemble_png(u_in){
        var LEN = 16;
        var key = "0000000000000000";
        var shifter;
        if(u_in.length == LEN){
          key = u_in;
        }

        var result = [];
        for(var i = 0; i < LEN; i++){
          shifter = key.charCodeAt(i) - 48;
          for(var j = 0; j < (bytes.length / LEN); j++){
            result[(j * LEN) + i] = bytes[(((j + shifter) * LEN) % bytes.length) + i]
          }
        }
        while(result[result.length-1] == 0){
          result = result.slice(0,result.length-1);
        }

        addImage(document.getElementById('space'), result);
      }
    </script>
  </body>
</html>
```

running the script we got our image .

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/8bacf682-9da5-40fe-b9c7-60ba4adfd00b)

and flag from scanning the QR.

> Flag: picoCTF{59d5db659865190a07120652e6c77f84}



