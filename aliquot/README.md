# Aliquot Sequence Homework

## Author
Your Name / Your Username

---

## Description

This program calculates the **Aliquot sequence** for any positive integer.  

- The sequence starts with a user-provided number `n`.
- Each next number is the **sum of proper divisors** of the previous number.
- The sequence stops either:
  1. When it reaches 0.
  2. When it detects a **cycle** (perfect, amicable, or sociable numbers).
  3. When it reaches a user-defined **maximum length**.

The program is written in **C** with a fun **Souvlaki-themed naming convention** for variables and functions.

---

## Features

- Reads **three inputs** from the user:
  1. Starting number (`unsigned long long`)  
  2. Maximum sequence length (0 for unlimited)  
  3. Print mode: `'f'` for full sequence, `'l'` for length only
- Handles **numbers up to 10¹⁵**.  
- Detects **cycles** in sequences (perfect numbers like 6, amicable numbers like 220/284, or longer cycles).  
- Provides **friendly error messages and jokes** in outputs.
- Stops gracefully if the number exceeds maximum allowed integer or memory limit for cycle detection.

---

## Usage

### Compile

```bash
gcc -O0 -m32 -Wall -Wextra -Werror -pedantic -o aliquot aliquot.c
