Based on [this tutorial](https://justinmeiners.github.io/lc3-vm/)  

# Virtual Machine  

This is a virtual machine. * This is still in progress *  

Assembly language that the VM uses: LC-3  

This only works for  \*unix-like systems -- i.e., MacOS, Linux, and FreeBSD  
## Programmed in C  

**Compile with either, CLANG or GCC**  

Steps:  
```bash
git clone git@github.com:arcelioeperez/virtmachine.git && cd virtmachine
chmod +x run.sh clear.sh
./run.sh
```

## Operating System  
Tested on MacOS, Linux (Ubuntu & Manjaro)

Should work on FreeBSD without any problems.  

## References
Based on - [Tutorial](https://justinmeiners.github.io/lc3-vm/)  
Binary arithmetic and negative numbers - [Arithmetic](https://www.tutorialspoint.com/computer_logical_organization/binary_arithmetic.htm) & [Negative Numbers](https://www.electronics-tutorials.ws/binary/signed-binary-numbers.html#:~:text=In%20two's%20complement%20form%2C%20a,complement%20is%20one's%20complement%20%2B%201)  

More instructions and random thoughts [here/README](./README).
