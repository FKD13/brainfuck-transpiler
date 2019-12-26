# Brainfuck Transpiler

Convert all your brainfuck code to c++ code.

# Building the transpiler

First of all clone the project and then execute `cmake . && make` in the newly created folder.

# Using the transpiler

The Transpiler takes as argument a file containing the brainfuck source code. Using it to transpile [cat.txt](example/cat.txt) looks like this:

```shell script
./bfuck example/cat.txt
```

which generates `out.cpp`.

The complete flow looks like this:

```shell script
./bfuck example/cat.txt
g++ out.cpp
./a.out
```

Or a one liner:

```shell script
./bfuck example/cat.txt && g++ out.cpp && ./a.out
```
---
Feel free to contribute by opening issues or creating PR's.

---
Enjoy converting your BF code!

