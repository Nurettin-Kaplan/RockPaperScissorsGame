# Game Scenario: Rock-Paper-Scissors Game

In this scenario, a console application will be designed where the player plays a rock-paper-scissors game against the computer.

**Game Application - Requirements:**

1. Use of Abstract Classes:
   - `Player`: An abstract class containing the basic features and behaviors of a player.
   - `ComputerPlayer`: An abstract class containing the basic features and behaviors of the computer player.

2. Definition of Common Behaviors:
   - The `Player` and `ComputerPlayer` classes will define common behaviors, including the player's name and the selected move (rock, paper, scissors).

3. Polymorphism:
   - Players (human and computer) will have different move strategies.
   - Both types of players will implement the same abstract behaviors but will use their specific move strategies.

4. Code Sharing Among Subclasses:
   - The `HumanPlayer` class will inherit from the `Player` class, take the player's name, and implement the move strategy.
   - The `RandomComputerPlayer` class will inherit from the `ComputerPlayer` class and implement the computer's random move strategy.

5. Console Environment:
   - Options will be presented to the user, and input will be taken.
   - The moves of the players and the results will be displayed on the console.

6. Requirements:
   1. Players' names will be requested as input.
   2. The user will be presented with options for rock, paper, or scissors.
   3. The computer will make a random move.
   4. The moves of the players and the computer will be printed on the screen.
   5. The result of the move (win, lose, or draw) will be announced.
   6. The players' scores will be tracked.
   7. When a round of the game ends, the user will be asked if they want to continue.
   8. When the user wishes to end the game, the total scores will be printed on the screen.
   9. The moves made during the game will be recorded, and past moves can be viewed.
   10. Strategies for different player types within the game can be defined.

In this example, the design of an application that performs the rock-paper-scissors game in a console environment is presented. It serves as an example application showing how abstract classes, common behaviors, polymorphism, and code sharing can be used.