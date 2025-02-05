# TEST.md Document
This TEST.md file contains documented test cases when you run the rod_cutting.c program. <br>
Each test case contains the program execution command, input data, and expected output.
<br> <br>


# Instuction for Running
1. Navigate to the directory containing the C source file in Bash (CMD), then compile the C file using:
```bash
gcc -o rod_cutting rod_cutting.c
```
2. Run the compiled .exe file using:
```bash
rod_cutting.exe
```
<br>

# Test Case #1  
### **Bash:**
```bash
rod_cutting.exe 45
```
### **Input:**
```C
10, 20
15, 30
5, 10 
CTRL+Z 
```
### **Expected Output:**
```C
4 @ 10 = 80
1 @ 5 = 10
Remainder: 0
Value: 90
```

<br>

# Test Case #2
### **Bash:**   
```bash
rod_cutting.exe 50
```
### **Input:**
```C
10, 15
20, 40
5, 7
CTRL+Z
```
### **Expected Output:**
```C
2 @ 20 = 80
1 @ 10 = 15
Remainder: 0
Value: 95
```

<br>


# Test Case #3 
### **Bash:**
```bash
rod_cutting.exe 37
```
### **Input:**
```C
6, 8
8, 12
12, 20
CTRL+Z
```
### **Expected Output:** 
```C
3 @ 12 = 60
1 @ 6 = 8
Remainder: 1
Value: 68 
```
<br>

# Test Case #4  
### **Bash:**  
```bash
rod_cutting.exe 28
```  
### **Input:**  
```C
5, 10
7, 15
9, 21
CTRL+Z
```  
### **Expected Output:**  
```C
3 @ 9 = 63
1 @ 7 = 15
Remainder: 2
Value: 78
```
<br>


# Test Case #5  
### **Bash:**  
```bash
rod_cutting.exe 33
```  
### **Input:**  
```C
4, 9
6, 14
8, 19
CTRL+Z
```  
### **Expected Output:**  
```C
4 @ 8 = 76
1 @ 4 = 9
Remainder: 1
Value: 85
```
<br>

# Test Case 6 
### **Bash:**  
```bash
rod_cutting.exe 55
```  
### **Input:**  
```C
10, 18
15, 30
25, 52
CTRL+Z
```  
### **Expected Output:**  
```C
2 @ 25 = 104
1 @ 5 = 10
Remainder: 5
Value: 114
```

<br>

# Test Case #7  
### **Bash:**  
```bash
rod_cutting.exe 19
```  
### **Input:**  
```C
3, 7
5, 12
7, 20
CTRL+Z
```  
### **Expected Output:**  
```C
2 @ 7 = 40
1 @ 5 = 12
Remainder: 0
Value: 52
```

<br>

# Test Case #8  
### **Bash:**  
```bash
rod_cutting.exe 42
```  
### **Input:**  
```C
6, 10
9, 19
12, 25
CTRL+Z
```  
### **Expected Output:**  
```C
3 @ 12 = 75
1 @ 6 = 10
Remainder: 0
Value: 85
```
