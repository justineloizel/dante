# Dante

C program to generate and solve mazes

### Prerequisites

- gcc
- make
- libc

### Compilation

```
make
```

### Usage

```
./generator x y [perfect]
```
Size : x and y.<br />
As the perfect argument is optional, the default generation will be an imperfect maze.<br />
You can also redirect the result to solve it afterwards.<br />
```
./generator x y > test.txt
```
