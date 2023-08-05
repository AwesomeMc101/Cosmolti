# Cosmolti
Interpreted language


Small lang I wrote for fun and sometimes update :)

Current syntax:
print: "Hello World!"

Documentation:

Printing:
To print, just use the print command followed by what you'd like to print

print: "Hello World!"


Variables:
Variables as of rn can't be redefined sadly I need to overhaul them

var: x 5


Mathematics:
Can be used anywhere, symbols +-*/^ (add,sub,mul,div,pow)

print: 5 + 6 * 4 - 5 / 2 ^ 5


String concat:
You can also concat strings

var: z "Hello" + " " + "World!"
or
print: 'Hello' - 'lo' -> Hel

Functions:
Rand: 1 arg, generates random number with max of arg1
print: rand 50

Strlen: 1 arg, returns length of string
print: strlen "Hello" + "World" -> 10

Gettype: 1 arg, returns type of arg
print: gettype 5 -> NUMBER
