# Question 2 Explanation

## Command 1
Command:
```bash
mkdir -p ~/CLI-and-Scripting-Lab/Question2
cd ~/CLI-and-Scripting-Lab/Question2
```

Observation:
The Question2 directory was created (if it did not already exist) and the terminal moved into it.

Explanation:
This command prepares a separate folder for Question 2 and sets it as the current working directory.

---

## Command 2
Command:
```bash
nano process_manager.c
```

Observation:
The Nano text editor opened and a new C source file was created.

Explanation:
Nano was used to write the C program that demonstrates process creation and management.

---

## Command 3
Command:
```bash
gcc process_manager.c -o process_manager
```

Observation:
The C program compiled successfully without errors.

Explanation:
The GCC compiler converted the source code into an executable file named `process_manager`.

---

## Command 4
Command:
```bash
./process_manager
```

Observation:
The parent process created a child process, monitored it, terminated it using a signal, and prevented a zombie process by calling `wait()`.

Explanation:
The program demonstrates process management in Linux using `fork()`, `kill()`, `SIGTERM`, and `wait()`.
