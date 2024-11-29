Conway's Game of Life - Raylib Implementation

![grafik](https://github.com/user-attachments/assets/af64f79d-b0ac-4163-810a-1212a9257d55)

A simple implementation of Conway's Game of Life using the Raylib library.

Overview

Conway's Game of Life is a cellular automaton consisting of a two-dimensional grid of cells. Each cell can be either "alive" or "dead." The state of the cells evolves over time based on a set of simple rules:

    Survival: A living cell with 2 or 3 living neighbors stays alive.
    Death by Isolation: A living cell with fewer than 2 living neighbors dies.
    Death by Overpopulation: A living cell with more than 3 living neighbors dies.
    Reproduction: A dead cell with exactly 3 living neighbors becomes alive.

Features

    Interactive grid where cells can be toggled between alive and dead.
    Real-time simulation of generations.
    Lightweight and fast implementation using Raylib.

Requirements

    Raylib 5
    CMake

Installation

    Clone the repository:

git clone https://github.com/acc0re/rlgol/.git  
cd rlgol

Make sure Raylib is installed and properly configured on your system.

compile with cmake

Usage

    Use the mouse to toggle cells between alive and dead.
    Generate random alive cells.
    Start or pause the simulation (with SPACE).

About Conway's Game of Life

Conway's Game of Life is a zero-player game developed by mathematician John Conway in 1970. It demonstrates how complex patterns and behaviors can emerge from simple rules.
