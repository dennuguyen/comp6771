# Tutorial 5

## Question 1

Look at `source/subscript.cpp`

* Make this code const-correct so it can compile and run sucessfully
* In what cases would we need to overload an operator for its const or non-const version?

## Question 2

Why is prefix increment/decrement usually preferred to postfix increment/decrement? When would we use postfix?

* Prefix is generally preferred (when no copy is needed) due to one less step (a copy and return) being completed. Therefore at scale this operation will yield finite performance improvements
* Postfix is used when you want to receive a copy of the object's current state prior to the increment/decrement occuring.

## Question 3

What is *stack unwinding*?

What happens during stuck unwinding?

What issue can this potentially cause? How can we fix this?

## Question 4

What are the 4 exception safety levels and what does each mean?

## Question 5

Look at `source/rethrow.cpp`

This program currently catches the exception fine within the make_connection function. However, we want the client (the main function) to also log it's own error message "Could not establish connection". How can we use rethrow to achieve this?

## Question 6

In what cases would we want to have two catch statements for a thrown exception?

## Question 7

In what case would we want to define our own exception? Give an example, and explain why we would.

Are there ways to define our own exception without reinvesting the wheel?

## Question 8

Look at `source/catch.cpp`

What is wrong with this code?
