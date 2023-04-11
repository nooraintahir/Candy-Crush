# Candy-Crush
This project is a working version of candy crush written in assembly code, where the user can use the mouse to swap two candies. The goal is to reach a certain target score in a certain number of moves. 

## How it is implemented:
This implementation of the project uses an array as a base for all decision making. Each candy has been assigned a number and according to that the array has been randomly filled. Next this array has been used to fill the board with the corresponding candies at the start of the game. The user can now select any two candies and perform a swap, but if the candies don’t match, nothing will happen. If they do match the user gets points and if the user manages to get enough points in the given number of moves a screen will pop up showing whether or not they will win or lose.

What happens on the back end of the swap is that the mouse clicks provide two sets of coordinates which are then checked to find the corresponding indexes of the array and swapped there. The two points are checked for their adjacent candies and if they are the same the swap is kept, otherwise it is reversed. The candies that are a part of the combo disappear and more drop down to take their place. The spaces left on top and filled with randomly generated candies. The game continues until either the score is met or the moves run out, after which these two screens are shown based on if you win or loose.

### Candies
![image](https://user-images.githubusercontent.com/110716479/231222784-593eb789-4da6-47ad-a595-d175fdc47135.png)


