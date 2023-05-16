# Simple Shell Project

This is the documentation for the Simple Shell project, developed as part of the curriculum at [Holberton School](https://www.holbertonschool.com/).

## Description

The Simple Shell project aims to build a basic shell program that can interpret and execute commands entered by the user. It provides a command-line interface where users can interact with the shell by entering commands, and the shell executes those commands accordingly.

## Project Goals

The main goals of this project are as follows:

1. Develop a functional shell program capable of executing basic commands.
2. Implement support for built-in commands such as `cd`, `exit`, and `env`.
3. Handle command execution by creating child processes and using system calls such as `execve` and `wait`.
4. Parse and tokenize user input to extract command and argument information.
5. Implement features to support input/output redirection and piping of commands.
6. Handle error scenarios gracefully and display meaningful error messages.

## Project Usage

To use the Simple Shell, follow these steps:

1. Clone the repository to your local machine.
2. Compile the shell program using the provided Makefile.
3. Run the shell program by executing the generated executable file.
4. Enter commands at the prompt and press Enter to execute them.
5. Enjoy the functionality of the shell, including built-in commands, input/output redirection, and command piping.

## Project Contributors

This Simple Shell project was developed by Alexander Agwuncha and Favour Favour. We worked together to design, implement, and test the various features of the shell.

## Project Flowchart

![Flowchart](./flowchart.png)

The flowchart above illustrates the execution flow and decision-making process within the Simple Shell program.

## Conclusion

The Simple Shell project provided an opportunity to gain a deeper understanding of operating system concepts, system calls, and process management. Through this project, we learned how to design and develop a basic shell program, handling user input, executing commands, and supporting advanced features. This project enhanced our knowledge of C programming, system calls, and the Unix/Linux environment.

We hope you find this Simple Shell project informative and useful. Feel free to explore the source code and try out the shell for yourself!

