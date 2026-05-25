# sharedpTR

A lightweight custom implementation of a reference-counted smart pointer in C++, built to explore manual memory management, RAII, copy semantics, and ownership handling.

---

# Features

- Reference-counted shared ownership model
- Automatic memory cleanup using RAII
- Copy constructor support
- Copy assignment operator support
- Pointer dereference operators (`*` and `->`)
- Reference count tracking
- Demonstration using a sample `Person` class

---

# Concepts Explored

- Dynamic memory management
- RAII (Resource Acquisition Is Initialization)
- Smart pointers
- Reference counting
- Copy semantics
- Operator overloading
- Destructor behavior
- Ownership management

---

# Project Structure

```bash
sharedpTR/
├── Implement.cpp
└── README.md
```

---

# Example

```cpp
SharedPtr<Person> p1(new Person("Uday", 19));

SharedPtr<Person> p2 = p1;
SharedPtr<Person> p3 = p1;

std::cout << p1.no_of_references() << std::endl;
```

Output:

```text
Person object with name: Uday was created!
HI I am Uday ,I am 19 years old!
Count after creating additional pointers : 3
A person object was destroyed
```

---

# Build & Run

## Compile

```bash
g++ -std=c++17 main.cpp -o sharedptr
```

## Run

```bash
./sharedptr
```

---

# Current Limitations

This implementation is intentionally minimal and does not yet include:

- Thread safety
- Move semantics
- Weak pointers
- Custom deleters
- Atomic reference counting
- Exception safety guarantees

---

# Learning Goals

This project was built to better understand how smart pointers work internally in C++ and how modern C++ manages resource ownership safely.

---

# Future Improvements

- Add move constructor and move assignment
- Implement `WeakPtr`
- Add thread-safe atomic counters
- Support custom deleters
- Improve exception safety

---

# License

MIT License
