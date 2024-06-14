# Bytes and Big Integers

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/ce822d70-117a-45c0-b47f-cee2c73bce2e)

Here we have to convert the long integer to bytes format we can do so with the help of this script.

```python
from Crypto.Util.number import long_to_bytes
a=11515195063862318899931685488813747395775516287289682636499965282714637259206269
print(long_to_bytes(a))
```
**Explaination:** Using **Crypto.Util.number** to convert long inter to bytes format.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/4fac3d0f-8729-4c8c-be06-cb75335a3d94)

>Flag: crypto{3nc0d1n6_4ll_7h3_w4y_d0wn}
