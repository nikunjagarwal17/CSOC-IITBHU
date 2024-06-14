# Hex

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/f0b9c62c-de11-43d2-adfe-b559909b132f)

Here we are given with a hex string and we have to convert it into bytes.

We can use the follwing script to do so.


```python
from Crypto.Util.number import long_to_bytes
a = 0x63727970746f7b596f755f77696c6c5f62655f776f726b696e675f776974685f6865785f737472696e67735f615f6c6f747d

print(long_to_bytes(int(a)))
```

**Explaination:** I am using **Crypto.Util.number** module form **PyCryptodome** library here. Firstly I convert the hex number to long number and then use **long_to_bytes** function to convert the generated long number in bytes format.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/4bd84190-e4e2-4d94-a744-00187cc5c931)

> Flag: crypto{You_will_be_working_with_hex_strings_a_lot}


