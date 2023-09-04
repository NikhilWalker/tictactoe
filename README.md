# Tic-Tac-Toe Console Game

Tic-Tac-Toe is a classic two-player game implemented in C++ and played in the console. The game allows players to compete against each other or against a computer opponent.

## Platform
###	Compilers
1. msvc22
1. MINGW
1. clang

### c++ version
standard 17 or above

### console
The project currently executes terminal or console emulators.
Most modern terminals support ANSI escape codes, but there might be some variations in support depending on the terminal software.
This line of code may cause some problem in old console software.

<code> std::cout << "\033[1;3" << WHITE << ";4" << BLACK << 'm'; </code>

## Features

- Play against another player or computer AI.
- Simple console-based interface.
- Supports two players.
- Computer opponent uses basic AI strategies.
- Released under GPLv2.0 license.

## Usage
Follow these steps to build and run the Tic-Tac-Toe project on different platforms using CMake:

### Linux/macOS (GCC or Clang)

1. Open a terminal.
2. Navigate to the project root directory.
3. Create a build directory: `mkdir build`
4. Move into the build directory: `cd build`
5. Generate build files using CMake: `cmake ..`
6. Build the project: `make`
7. Run the compiled executable: `./game`

### Windows (Visual Studio)

1. Open the project in Visual Studio
1. Configure the Build Configuration
1. Build and Run the executable

### Windows (MinGW)

1. Open a command prompt or PowerShell.
2. Navigate to the project root directory.
3. Create a build directory: `mkdir build`
4. Move into the build directory: `cd build`
5. Generate build files using CMake: `cmake .. -G "MinGW Makefiles"`
6. Build the project: `mingw32-make`
7. Run the compiled executable: `game.exe`

### Windows (Clang via MSYS2)

1. Open an MSYS2 terminal.
2. Navigate to the project root directory.
3. Create a build directory: `mkdir build`
4. Move into the build directory: `cd build`
5. Generate build files using CMake: `cmake .. -G "MSYS Makefiles"`
6. Build the project: `make`
7. Run the compiled executable: `./game.exe`


Make sure to adjust the build commands and paths as necessary for your system. If you encounter any issues, feel free to reach out for assistance.

For further information on CMake, refer to the official CMake documentation: https://cmake.org/documentation/

## License

This project is licensed under the [GNU General Public License v2.0](LICENSE.txt).

## Suggestions

If you have any suggestions, improvements, or feature requests, feel free to create an issue or a pull request in this repository. Contributions are welcome!

## Adding a GUI Interface

If you're interested in enhancing the project with a GUI interface, consider the following steps:

1. Choose a GUI framework: Select a C++ GUI framework/library such as Qt, wxWidgets, or GTKmm.
2. Design the UI: Create a graphical interface for the Tic-Tac-Toe game. Include a game board and buttons for player interaction.
3. Implement game logic: Translate your existing console-based game logic to work with the GUI elements.
4. Test thoroughly: Ensure that the GUI version behaves correctly and provides a smooth user experience.

## Contact

For any questions or inquiries, feel free to contact [nikhiljangra264@gmail.com](mailto:nikhiljangra264@gmail.com).
