## Right Shift  

```
int a  = 9;

// ceil_division(a / 2^y) where y is '1' -- i.e., 9 / 2 = 4
// therefore the answer is 4
int c = a >> 1;
```  

## Left Shift  

```
int a  = 9; 

// multiplication (a * 2^y) where y is '1' -- i.e., 9 * 2 = 18
// therefore the answer is 18

int c = a << 1;
```


*y* is '1' in this example; however, *y* is whichever number you use after the shift. E.g., `16 >> 4` in this case 4 is *y* -- this means `2^4` which equals 16. The final answer of `16 >> 4` is 1.  
