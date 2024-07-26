# Rubiks-Cube-Solver

This project aims to solve the Rubik's Cube using various graph algorithms. The solver supports different methods including Depth-First Search (DFS), Breadth-First Search (BFS), and Iterative Deepening Depth-First Search (IDDFS).

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Cube Representation](#cube-representation)
- [Solvers](#solvers)
  - [DFS Solver](#dfs-solver)
  - [BFS Solver](#bfs-solver)
  - [IDDFS Solver](#iddfs-solver)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Rubik's Cube Solver project implements algorithms to solve an unsolved Rubik's Cube. The solver utilizes graph algorithms to find the solution path from an initial unsolved state to the solved state. The solution path consists of standard Rubik's Cube moves.

## Features

- **Cube Representation**: Efficiently represents the Rubik's Cube in different formats.
- **Display Cube**: Provides functionality to display the current state of the cube.
- **Perform Moves**: Supports the 12 standard Rubik's Cube operations.
- **Graph Algorithms**:
  - Depth-First Search (DFS)
  - Breadth-First Search (BFS)
  - Iterative Deepening Depth-First Search (IDDFS)
- **Solution Moves**: Displays the sequence of moves used to solve the cube.

## Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/your-username/Rubiks-Cube-Solver.git
   cd Rubiks-Cube-Solver
   ```

2. Compile the code using a C++ compiler. Make sure you have a C++17 compatible compiler.

## Usage

1. **Include the necessary headers** in your main file:

   ```cpp
   #include "Model/RubiksCube3dArray.h"
   #include "Solvers/BFSSolver3d.h"
   #include "Solvers/IDDFSSolver3d.h"
   ```

2. **Initialize and shuffle the cube**:

   ```cpp
   RubiksCube3dArray cube;
   vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
   ```

3. **Solve using BFS Solver**:

   ```cpp
   BFSSolver3d bfsSolver(cube);
   vector<RubiksCube::MOVE> solve_moves_bfs = bfsSolver.solve();
   ```

4. **Solve using IDDFS Solver**:

   ```cpp
   IDDFSSolver3d iddfsSolver(cube);
   vector<RubiksCube::MOVE> solve_moves_iddfs = iddfsSolver.solve();
   ```

5. **Display the solution moves**:

   ```cpp
   for(auto move: solve_moves_bfs) {
       cout << cube.getMove(move) << " ";
   }
   cout << "\n";
   ```

## Cube Representation

The Rubik's Cube is represented using a 3D array. Each face of the cube is a 3x3 matrix, and the entire cube is a 6x3x3 matrix. The cube supports standard moves which include rotations of its faces.

### Standard Moves

The 12 standard operations supported by the cube are:

- **U**: Up face clockwise
- **U'**: Up face counterclockwise
- **U2**: Up face 180 degrees
- **D**: Down face clockwise
- **D'**: Down face counterclockwise
- **D2**: Down face 180 degrees
- **L**: Left face clockwise
- **L'**: Left face counterclockwise
- **L2**: Left face 180 degrees
- **R**: Right face clockwise
- **R'**: Right face counterclockwise
- **R2**: Right face 180 degrees

## Solvers

### DFS Solver

Performs a depth-first search to solve the cube. It searches deeper into the state space before backtracking.

### BFS Solver

Performs a breadth-first search to solve the cube. It explores all neighbor states at the present depth prior to moving on to states at the next depth level.

### IDDFS Solver

Combines the space-efficiency of DFS with the optimality of BFS. It performs DFS with increasing depth limits until a solution is found.

## Contributing

Contributions are welcome! If you have any suggestions or improvements, feel free to create a pull request or open an issue.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

Enjoy solving the Rubik's Cube with graph algorithms! If you encounter any issues or have questions, please feel free to contact me.
