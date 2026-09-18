# Spacewar

A two-player console-based space battle game developed in **C**.

## Features

* **Two-player local gameplay** with real-time keyboard controls
* **User account system**

  * Sign up / Sign in
  * Password recovery
  * Username, email, and password management
* **Three different game maps**
* **Multiple rounds and scoring system**
* **Game history** with wins, losses, round results, and player statistics
* **Save & continue** functionality
* **Persistent file-based data storage**
* **Multiple gameplay abilities and weapons:**

  * Health items
  * Weapon upgrades
  * Ghost ability
  * Grenades
  * Bombs with timed activation
  * Laser
* **Interactive map elements:**

  * Walls
  * Black holes
  * Teleporters
  * Mirrors with bullet reflection
  * Special map items
* **Collision detection and health management**
* **Real-time shooting based on player movement direction**

## Controls

### Player 1

```text
W → Up       A → Left
S → Down     D → Right
C → Shoot    X → Bomb
```

### Player 2

```text
I → Up       J → Left
K → Down     L → Right
N → Shoot    M → Bomb
```

## Environment

```text
Language:     C
Platform:     Windows
Interface:    Console / Terminal

Main Libraries:
windows.h
conio.h
stdio.h
stdlib.h
string.h
time.h
```

## Project Structure

```text
Spacewar/
│
├── Spacewar.c
└── README.md
```

## Running the Project

```text
1. Compile Spacewar.c using a C compiler on Windows.
2. Run the generated executable.
3. Create an account or sign in.
4. Start a game with another player.
```
