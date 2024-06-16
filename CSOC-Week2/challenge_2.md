# Challenge 2

[Here](https://github.com/JustAnAverageGuy/literate-octo-fiesta/tree/main/challenge_2) is the challenge file

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/9ef1b643-087b-4a01-bd3e-916d27e63ff7)

Since we can clearly see that the output text is made up of different strings some in binary format, hexadecimal format , base64 format and octal format to decode the above text we have to convert all of them to bytes and join them in the given order to do so we can use the following script.

```python
import base64

def binary_to_bytes(binary_str):
    binary_values = binary_str.split()
    byte_array = bytearray()
    for binary in binary_values:
        byte_array.append(int(binary, 2))
    return bytes(byte_array)

def hex_to_bytes(hex_str):
    hex_values = hex_str.split()
    byte_array = bytearray()
    for hex_value in hex_values:
        byte_array.append(int(hex_value, 16))
    return bytes(byte_array)

def base64_to_bytes(base64_str):
    return base64.b64decode(base64_str)

def octal_to_bytes(octal_str):
    octal_values = octal_str.split()
    byte_array = bytearray()
    for octal_value in octal_values:
        byte_array.append(int(octal_value,8))
    return bytes(byte_array)

binary_str = "01000011 01010011 01001111 01000011 00110010"
hex_str = "33 7b 6a 75 35 37 5f"
base64_str = "ZDFmZjNyM243XzNuYw=="
octal_str = "60 144 61 156 66 65 137 154 60 154 175"

binary_bytes = binary_to_bytes(binary_str)
hex_bytes = hex_to_bytes(hex_str)
base64_bytes = base64_to_bytes(base64_str)
octal_bytes = octal_to_bytes(octal_str)

combined_bytes = binary_bytes + hex_bytes + base64_bytes + octal_bytes
print(combined_bytes)
```

**Explaination:** here in the code we have created different function to convert binary, hex, base64, octal to bytes respectively and combine all of them in the end.

Runnning the script we get.

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/00071a53-0ffb-4ed0-8269-7f331ec55943)

> Flag: CSOC23{ju57_d1ff3r3n7_3nc0d1n65_l0l}








