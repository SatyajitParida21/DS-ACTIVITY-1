# DS-ACTIVITY-1
# DSA Activity CA1 – Postfix Expression Evaluation Using Stack

**JAIN (Deemed-to-be University)**  
**Programme:** Master of Computer Applications (MCA)  
**Semester:** I  
**Academic Year:** 2026–2027  
**Subject:** Data Structures and Algorithms (DSA)  
**Assignment:** Continuous Assessment 1 (CA1)  
**Submitted by:** Satyajit Parida  

---

## 1. Problem Statement

An embedded computing device receives arithmetic instructions in postfix notation from a sensor-processing module. The device must evaluate these expressions efficiently while using limited memory.

**Given Postfix Expression:**

```text
8 3 - 2 4 * + 6 /
```

The objective is to implement postfix expression evaluation using a stack, display the stack operations, explain operand order for subtraction and division, handle invalid expressions, and compare array-based and linked-list-based stack implementations.

## 2. Approach Used

This project implements an **array-based stack in C** to evaluate postfix expressions.

A stack follows the **LIFO (Last In, First Out)** principle. In postfix notation, operands are pushed onto the stack. When an operator is encountered, the required operands are popped, the operation is performed, and the result is pushed back onto the stack.

### Algorithm

1. Read the postfix expression from the user.
2. Split the expression into tokens using whitespace.
3. If a token is a number, push it onto the stack.
4. If a token is an operator:
   - Check whether at least two operands are available.
   - Pop the second operand (`b`).
   - Pop the first operand (`a`).
   - Calculate `a operator b`.
   - Push the result onto the stack.
5. Check for division by zero and invalid tokens.
6. After processing all tokens, ensure exactly one value remains.
7. Display the final result.

## 3. Stack Operations and Visualization

For the expression:

```text
8 3 - 2 4 * + 6 /
```

The stack changes after every token as follows. The bottom of the stack is shown on the left.

| Step | Token | Operation | Stack (bottom → top) |
|---:|:---:|---|---|
| 1 | `8` | Push 8 | `[8]` |
| 2 | `3` | Push 3 | `[8, 3]` |
| 3 | `-` | 8 − 3 = 5 | `[5]` |
| 4 | `2` | Push 2 | `[5, 2]` |
| 5 | `4` | Push 4 | `[5, 2, 4]` |
| 6 | `*` | 2 × 4 = 8 | `[5, 8]` |
| 7 | `+` | 5 + 8 = 13 | `[13]` |
| 8 | `6` | Push 6 | `[13, 6]` |
| 9 | `/` | 13 ÷ 6 | `[2.166667]` |

**Final result:**

```text
Result = 2.166667
```

The result uses floating-point division.

## 4. Operand Order for Subtraction and Division

Operand order is important for non-commutative operations such as subtraction and division.

When an operator is encountered:

```c
pop(&b);
pop(&a);
```

The first popped value is the right operand (`b`), and the second popped value is the left operand (`a`).

The operation must be performed as:

```text
a - b
a / b
```

**Example:**

For `8 3 -`:

- Pop `3` into `b`.
- Pop `8` into `a`.
- Calculate `8 - 3 = 5`.

For `13 6 /`:

- Pop `6` into `b`.
- Pop `13` into `a`.
- Calculate `13 / 6 = 2.166667`.

Reversing the operands would produce incorrect results for subtraction and division.

## 5. Error Handling

The program includes basic validation to handle common errors.

| Error | Example | Expected behavior |
|---|---|---|
| Insufficient operands | `5 +` | Displays an insufficient-operands error |
| Division by zero | `8 0 /` | Displays a division-by-zero error |
| Invalid token | `8 abc +` | Displays an invalid-token error |
| Invalid expression | `2 3` | Displays an invalid-expression error |
| Stack overflow | More than 100 simultaneous stack values | Displays a stack-overflow error |

These checks help prevent invalid operations and ensure that a valid postfix expression leaves exactly one result on the stack.

## 6. Array-Based vs. Linked-List-Based Stack

| Feature | Array-Based Stack | Linked-List-Based Stack |
|---|---|---|
| Memory allocation | Fixed-size array | Dynamic node allocation |
| Memory usage | Contiguous memory | Node memory plus pointer overhead |
| Push operation | O(1) | O(1) |
| Pop operation | O(1) | O(1) |
| Capacity | Limited by array size | Limited by available memory |
| Overflow | When the array is full | When memory allocation fails |
| Implementation | Simple | Requires pointer management |
| Memory locality | Generally better | Generally poorer |
| Suitability | Predictable, bounded workloads | Workloads with variable stack size |

Both implementations have **O(n) time complexity** for evaluating an expression containing `n` tokens, assuming constant-time arithmetic operations.

The array-based implementation uses **O(MAX)** allocated stack storage in this program, where `MAX = 100`. A linked-list-based stack uses **O(k)** memory for `k` simultaneously stored operands, including per-node pointer overhead.

### Which implementation is suitable?

For this assignment, the array-based stack is suitable because the expression is small, the maximum capacity is known, and the implementation is simple and efficient. A linked-list-based stack is preferable when the number of operands is unpredictable and dynamic memory allocation is appropriate.

## 7. Technologies Used

- **Programming Language:** C
- **Data Structure:** Stack
- **Implementation:** Array-based stack
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`, `math.h`
- **Tools:** GCC / MinGW / Visual Studio Code

## 8. How to Compile and Run

Save the source code as `postfix.c`.

### Compile

```bash
gcc postfix.c -o postfix -lm
```

The `-lm` option links the mathematics library required for the `pow()` function.

### Run on Windows

```bash
postfix.exe
```

### Run on Linux or macOS

```bash
./postfix
```

Enter the expression with spaces between tokens:

```text
8 3 - 2 4 * + 6 /
```

Expected output:

```text
Enter postfix expression (spaces between tokens): 8 3 - 2 4 * + 6 /
Result = 2.166667
```

## 9. Limitations

- The stack has a fixed capacity of 100 elements.
- Tokens must be separated by spaces or tabs.
- The program supports the operators `+`, `-`, `*`, `/`, and `^`.
- It does not print the stack after each operation during execution; the operation-by-operation visualization is provided in this README.
- Floating-point arithmetic may introduce small precision differences.

## 10. Conclusion

This project demonstrates how a stack can evaluate postfix expressions efficiently without requiring parentheses or operator-precedence parsing. The array-based implementation provides constant-time push and pop operations, uses predictable memory, and includes basic validation for invalid expressions and division by zero.

The assignment also illustrates why operand order matters in subtraction and division and compares the memory and performance characteristics of array-based and linked-list-based stacks.

---

**Repository:** DSA Activity CA1 – Postfix Expression Evaluation  
**Submitted by:** Satyajit Parida  
**University:** JAIN (Deemed-to-be University)
