# Tic-Tac-Toe Console Game

Tic-Tac-Toe is a classic two-player game implemented in C++ and played in the console. The game allows players to compete against each other or against a computer opponent.

## Platform
###	Compilers
1. msvc22
1. MINGW

### c++ version
standard 11 or above

### console
The project currently executes terminal or console emulators.
Most modern terminals support ANSI escape codes, but there might be some variations in support depending on the terminal software.
GUI game is in work. This line of code may cause some problem in old console software.

<code>
std::cout << "\033[1;3" << WHITE << ";4" << BLACK << 'm';
</code>

## Features

- Play against another player or computer AI.
- Simple console-based interface.
- Supports two players.
- Computer opponent uses basic AI strategies.
- Released under GPLv2.0 license.

## Usage

1. Compile the project using a C++ compiler.
1. Run the compiled executable to start the game.
1. Follow the on-screen prompts to play the game.
1. When playing against a computer, choose your moves using the specified format.

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
