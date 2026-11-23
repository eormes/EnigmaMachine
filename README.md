# Enigma Machine

A C++ simulation of the Enigma cipher machine, built as the final project for **CSCI 200 (Foundations of Computer Science) at Colorado School of Mines**. You configure the machine's rotors, plugboard, and reflector, then encode or decode messages from text files.

## Features

- **Configurable rotors:** use 1 to 6 rotors, each chosen from 6 presets, with a custom starting notch position (0–25, wraps around)
- **Plugboard:** swap up to 10 pairs of letters before and after the rotors, with checks that a letter can't be plugged in twice
- **Reflector presets:** choose from 3 reflector wirings
- **File-based I/O:** reads a message from an input file and writes the result to an output file
- **Reversible:** as with the original Enigma, running the encoded output back through a machine with the same settings recovers the original message
- **Input validation:** every prompt rejects bad input (non-numbers, out-of-range values, extra characters) and asks again
- **Multiple messages:** encode several messages in one session with the same machine

## How It Works

A letter passes through the machine in this order:

1. **Plugboard:** swaps the letter with its connected partner, if it has one
2. **Rotors:** each rotor substitutes the letter, and the rotors step forward as letters are processed
3. **Reflector:** sends the signal back through the rotors in reverse
4. **Plugboard again:** one more swap on the way out

Because the reflector makes the substitution symmetric, encoding and decoding use the exact same settings.

## Project Structure

| File | Purpose |
| --- | --- |
| `main.cpp` | Program entry point: prompts for settings and runs the encode loop |
| `Machine.h` / `Machine.cpp` | The machine itself: holds the rotors, plugboard, and reflector, and encodes letters |
| `Rotor.h` / `Rotor.cpp` | A single rotor with preset wirings and a notch position |
| `PlugBoard.h` / `PlugBoard.cpp` | Letter-pair swapping, also used to build the reflector presets |
| `Exchangeable.h` | Shared interface for components that transform a letter |
| `InputProcessor.h` / `.cpp` | Opens and reads the input message file |
| `OutputProcessor.h` / `.cpp` | Opens and writes the output file |
| `Makefile` | Build instructions |

## Building

You'll need a C++ compiler (such as `g++`) and `make`.

```bash
make
```

This produces the `EnigmaMachine` executable.

## Usage

Run the program and follow the prompts:

```bash
./EnigmaMachine
```

1. Enter how many rotors to use (1–6).
2. For each rotor, choose a preset (1–6) and a starting notch position.
3. Enter how many plugboard pairs to connect (0–10), then the two letters for each pair (A–Z).
4. Choose a reflector preset (1–3).
5. Provide the input file to read, then the output file to write.
6. Choose whether to encode another message.

To decode a message, run the program again with **identical settings** and use the encoded file as the input.

## Notes

- Only uppercase letters A–Z are used for plugboard connections.
- Settings are chosen once per run and reused for every message in that session.

## Author

**Ethan Ormes**, Electrical Engineering, Colorado School of Mines
[LinkedIn](https://www.linkedin.com/in/ethan-ormes/) · [GitHub](https://github.com/eormes)
