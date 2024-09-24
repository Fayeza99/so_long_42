# So Long

Welcome to `so_long_42`, a 2D map-based game developed using the MiniLibX library. This game project is part of 42 coding school curriculum designed to teach students the basics of graphic programming, game logic, and the handling of user inputs through the creation of a simple yet engaging game.

## Overview

`So Long` is a game where players navigate through a map to collect items and reach an exit. It demonstrates the application of algorithms in a graphical environment, utilizing the MiniLibX library, which is a simple X-Window (X11R6) programming API in C.

## Features

- **2D Graphics:** Utilizes MiniLibX to render the game map and sprites.
- **Map Parsing:** Reads and interprets map files (.ber format) to set game levels.
- **Game Mechanics:** Includes player movement, item collection, and enemy detection.
- **Collision Detection:** Manages interactions between the player, the map, and game entities.

## Getting Started

### Prerequisites

You'll need a C compiler and the MiniLibX library installed on your system. The game is currently configured to run on MacOS with the X11 environment.

### Installation

Clone the repository and compile the game using the provided Makefile:

```bash
git clone https://github.com/Fayeza99/so_long_42.git
cd so_long_42
make
