# FSM Vending Machine (C++)

This repository contains a **C++ implementation of a vending machine modeled as a Finite State Machine (FSM)**.
The project was originally developed as part of an academic exploration of state machines, formal languages, and system modeling.

Alongside the implementation, the repository includes:
- A formal grammar definition
- Regular expressions describing valid input sequences
- A state machine diagram illustrating system behavior

---

## 🧠 Concept Overview

A **Finite State Machine (FSM)** is a computational model defined by:
- A finite set of states
- Transitions between states based on inputs
- One or more accepting or terminal states

In this project, the vending machine is modeled as an FSM where:
- Each state represents a machine condition (e.g., idle, waiting for money, dispensing)
- Inputs represent user actions (e.g., inserting coins, selecting items)
- Transitions define valid sequences of actions

---

## 📁 Repository Structure
- src/main.cpp # C++ implementation of the vending machine FSM  
- grammar.txt # Formal grammar describing valid input sequences  
- regularexpression.txt # Regular expressions for accepted patterns  
- state_machine_diagram.jpg # FSM diagram (visual representation)  
- example_results folder for different executions  


---

## ⚙️ Implementation Details

- Language: **C++**
- Design approach: **Explicit state transitions**
- FSM behavior is implemented using conditional logic to simulate state changes
- Input validation follows the defined grammar and regular expressions

> Note: This project reflects an early-stage implementation focused on clarity and correctness rather than advanced design patterns.

---

## 📐 Formal Definitions

### Grammar
The `grammar.txt` file defines the valid sequences of inputs accepted by the vending machine.

### Regular Expressions
The `regularexpression.txt` file provides a regex-based abstraction of the same behavior, useful for theoretical validation.

### State Machine Diagram
The diagram visually represents:
- States
- Transitions
- Accepted and invalid paths

---

## 🎯 Learning Goals

This project was created to:
- Understand FSM concepts in practice
- Connect theory (grammar & regex) with implementation
- Model real-world systems using formal methods
- Practice structured programming in C++

---

## 🚀 Possible Improvements

Some potential extensions:
- Refactor using the State design pattern
- Separate FSM logic from I/O
- Add unit tests for transitions
- Support configuration-driven FSM definitions
