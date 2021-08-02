# DESIGN DECISIONS MADE

--PABLO CÉSAR JIMÉNEZ VILLEDA A01703517

    During the construction of this program several challenges and problems were found along the way,
which tested my ability to solve problems through the use of the learnt programming concepts. Some of
which were composition, constructors and methods. First, composition really helped me build complex objects
which consisted of other objects, this was used to code a solution to the problem of having a 3 dimensional 
board with each board having its own methods. By using composition I was able to program a vector that contained
the boards that would make up the cube that held every position, in doing so I was able to cycle through each 
board to search for win patterns by using the method checkBoardforWin that I created for the board class, which 
checked every possible win pattern to confirm the existence of a win in that specific board. I coded the solution to
said problem in this way so that I could cover more win cases in less code, thus optimizing the program. Additionally,
I had to program a way to insert new symbols into the vector that held char vectors and a way to display said 
changes in the game. In order to solve said challenge, I had to decide between coding a method for the Board class 
in order to display each Board individually or create a method that cycled through the Boards vector in the cube class
displaying the cube in a stylized manner. At the end I chose to use the latter due to the fact that it would be
clearer for the user how the dimensions related with each other, because if I had chosen to use the first option the boards 
would have been displayed in a vertical way, thus making it difficult for the user to keep track of what was happening.
Furthermore, I chose to introduce a Player object as an argument to the function placeSymbolInCube so that I could 
use said object down the pipeline and make it simpler to pass down the symbol that corresponded to the player in 
that turn. To achieve this I used a ternary operator to selectively pass the player object of the person´s turn so that 
inside the function I could use the getSymbol function to get the symbol of said player and then pass it to the addSymbolToBoard,
for which I used the first int argument to select the board from the Cube vector. In doing so I was able to use 
the methods of the objects contained inside other objects to manipulate them and display their content in the case of the
displayBoards method for the Cube class. The reason I did this was because I would optimize the code inside the while cycle 
inside of the init method in the game class, because if I had implemented a solution in which I would program the two turns
inside of an iteration I would just be repeating myself, nonetheless, because I used a ternary operator I reduced the code inside 
the init function and optimized it. Overall, during the construction of this project I was able to use several instances of 
some objects in order to create a functional game that consisted of the same parts(boards) structured in a way that made the original
one dimensional tic tac toe a 3D game, additionally, I used Classes and their constructors to create unique objects (player class) 
that would be useful to represent certain aspects of a real game. Encapsulation also proved to be key during the construction of
this game due to the fact of how often I had to manipulate the data within the object through methods. In conclusion, the use 
of nested vectors proved to be key because this data type was used to create cycles that would check every win possibility that
followed a certain pattern so that I did not have to individually code an if statement for every single win case.


