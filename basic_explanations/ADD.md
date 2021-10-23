ADD instruction  

Register mode (bits 3 and 4 are unsused):  
```assembly
ADD R2 R0 R1 ;add the contents of R0 to R1 and store in R2
```

Immediate assembly (usually used as a counter -- biggest int 2^5 == 32):  
```assembly
ADD R0 R0 1 ;add 1 to R0 and store back in R0
```  

Encodings (ADD):  
![image](./images/add.png)  

> source: [IMAGE](https://justinmeiners.github.io/lc3-vm/)  

Explanation of the encoding:  
`0001` first 4 bits -- opcode for the ADD instruction'  
`DR`(3 bits) destination register -- where the added sum will be stored  
`SR1` (3 bits) -- contains first number to ADD  
Register mode: bit[5] == 0   
`SR2` (3 bits, 4 and 3 are unused) -- contains the second number  
Immediate mode: bit[5] == 1  
`imm5` -- second value embedded into the instruction  


signExtend() function:  
```c
uint16_t signExtend(uint16_t x, int bitCount){
    if((x >> (bitCount - 1)) & 1){
        x |= (0xFFFF << bitCount);
    }
    return x;
}
```
`uint16_t` == unsigned 16-bit integer (max value 65,535)  
- 65,535 in hexadecimal is `0xFFFF`  

Negative numbers in binary have a 1 at the left-most position. Meanwhile, positive  
numbers have leading 0's.  

Example:   
- -1 is `1 1111` in binary  
- 7 is `0b111` in binary  
- 7 is `0x7` in hexadecimal    
