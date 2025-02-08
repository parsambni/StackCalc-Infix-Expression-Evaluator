
# StackCalc Infix Expression Evaluator

## Overview
StackCalc Infix Expression Evaluator is a C++ project that converts infix mathematical expressions (the way we normally write them) into postfix notation, and then evaluates the expression. This tool supports a variety of operations including basic arithmetic, exponentiation, factorials, and trigonometric functions. Whether you're a student exploring data structures or a hobbyist interested in custom calculators, this project offers a practical insight into how expressions are parsed and computed.

## Features
- **Infix to Postfix Conversion:**  
  Converts standard infix expressions (e.g., `3+4*(2-1)`) to postfix notation, which simplifies the evaluation process.
- **Rich Operator Support:**  
  - **Arithmetic Operators:** Addition (`+`), subtraction (`-`), multiplication (`*`), division (`/`), and exponentiation (`^`).
  - **Factorial:** Use `!` to compute factorials.
  - **Trigonometric Functions:** Supports `sin` and `cos`. The evaluator converts degree input to radians for accurate computation.
- **Negative Number Handling:**  
  Recognizes and correctly processes negative numbers in expressions.
- **Interactive Variable Input:**  
  Prompts the user to provide values for any variables encountered in the expression.
- **Custom Stack Implementation:**  
  Built with C++ templates, the stack supports various data types, demonstrating modern C++ practices.

## How It Works
1. **Preprocessing:**  
   The input infix expression is scanned to:
   - Convert functions like `sin` and `cos` into single-character tokens.
   - Distinguish between subtraction and negative signs.
2. **Conversion to Postfix:**  
   A custom stack is used to convert the preprocessed infix expression into postfix notation. This step respects the order of operations.
3. **Evaluation:**  
   The postfix expression is then evaluated using another stack, processing operations sequentially to produce the final result.

## Getting Started

### Prerequisites
- A C++ compiler that supports C++11 or later (e.g., GCC or MSVC).
- Standard C++ libraries (`<iostream>`, `<cmath>`, `<cstring>`) available on your system.

### Usage Instructions
1. **Compile the Code:**  
   Open a terminal in the directory containing the source file and run.

2. **Run the Program:**  
   Execute the program by running.

3. **Enter Your Expression:**  
   For example:
   ```
   Enter infix expression: (5+3)*2
   ```
   The program will display the postfix expression and the evaluated result.

## Example Scenarios

### Basic Arithmetic
- **Input:**
  ```cpp
  Enter infix expression: 3+4*2
  ```
- **Output:**
  ```
  Postfix expression: 342*+
  Answer of the expression: 11
  ```

### Incorporating Functions and Factorials
- **Input:**
  ```cpp
  Enter infix expression: sin(30) + 4!
  ```
- **Output:**
  ```
  Postfix expression: 30$4!+
  Answer of the expression: (calculated value)
  ```
  *Note: `sin(30)` is computed after converting 30 degrees to radians.*

### Handling Negative Numbers
- **Input:**
  ```cpp
  Enter infix expression: -5+3
  ```
- **Output:**
  ```
  Postfix expression: 5_3+
  Answer of the expression: -2
  ```

## Why Use This Project?
StackCalc Infix Expression Evaluator is more than just a calculator—it’s a practical demonstration of data structures and algorithms in action. By exploring the conversion and evaluation process, you gain insights into how compilers and interpreters handle mathematical expressions. It’s a fantastic resource for both learning and expanding your programming skills.

## Contributions and Feedback
Your feedback is important! If you have suggestions, find bugs, or want to contribute new features (like additional functions or improved error handling), feel free to fork the repository and submit pull requests. Join the discussion and help make this tool even better.

## License
This project is open source and available under the MIT License. You are free to use, modify, and distribute the code as long as you include the original license notice.

## Connect with the Community
We hope StackCalc Infix Expression Evaluator inspires you to delve deeper into C++ programming and the fascinating world of compilers. If you have any questions or ideas, please reach out via our project repository or community channels.

Happy coding!

