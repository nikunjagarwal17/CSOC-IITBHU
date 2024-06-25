# Week-3: The World of Web

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


## Client-side-again
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






























