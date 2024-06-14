# Base64

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/2727396d-86e6-4801-b4cc-df3b9d00e3da)


```python
import base64
a='72bca9b68fc16ac7beeb8f849dca1d8a783e8acf9679bf9269f7bf'

print(base64.b64encode(bytes.fromhex(a)))
```

As mentioned in the challenge firstly we have to convert the hex string in the bytes format and then convert it further to base64 format.

**Explaination:** Here I am using base64 libary to convet the bytes to base64 format and **bytes.fromhex()** to convert the hexstring to bytes format. We can also use this format to convert to bytes in previours challenge.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/715bd291-1f0f-4a03-919a-06b097f77af6)

> Flag: crypto/Base+64+Encoding+is+Web+Safe/
