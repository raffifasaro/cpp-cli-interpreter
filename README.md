# cpp-cli-interpreter

## Goal:
Simple command line based interpreter written in c++

## Motivation:
This is a pure learning project, no AI, not too much internet help, mostly just failing -> experimenting -> learning

## Current progress:

### Math eval:
First goal is to be able to eval all kinds of math expressions with support for user defined variables
- Lexer working with rough token categories
- Math parser working for fully‑parenthesized or operator‑separated positive expressions with no leading/trailing operators
- Math evaluator working for all operators supported by parser for now
- Support for identifiers/variables, which are saved for the current CLI session and can be used in calcs or overwritten after being declared
- Support for ";" -> leads to seperated expressions being printed in additional lines

