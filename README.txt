1. **Title:**
   Bloxorz

2. **Details: Name:**
   Ahmad Alyan

3. **General Explanation of the Exercise:**
   This project is similar to the Bloxorz game found online but in a two-dimensional format. The goal is to move the shape, which constantly changes between a square and a rectangle, across the tiles and reach a specific location without falling into holes.

4. **Design Explanation:**
   The objects in this game include movable and immovable simulations. Each object has its own properties that are activated when it collides with the player.

5. **List of Created Files with Brief Descriptions:**
   - **main.cpp**: The main file.
   - **Controller.cpp**: The file where the game is managed.
   - **Controller.h**: The file where we defined the functions and objects for the main file.
   - **Character.h**: The file where we defined the common properties for the characters.
   - **Hole.cpp**: The file where we implemented the properties and collision with the hole.
   - **Hole.h**: The file where we defined the properties of the hole.
   - **Information.cpp**: The file where we implemented the information and printed it to the screen.
   - **Information.h**: The file where we defined the properties of the information.
   - **Level.cpp**: The file where we implemented reading the levels from the file.
   - **Level.h**: The file where we defined the properties of the levels.
   - **Menu.cpp**: The file where we implemented the menu and printed it.
   - **Menu.h**: The file where we defined the properties of the menu.
   - **Player.cpp**: The file where we implemented the player and its movement.
   - **Player.h**: The file where we defined the properties of the player.
   - **SpecialTiles.cpp**: The file where we implemented the special tiles.
   - **SpecialTiles.h**: The file where we defined the properties of the special tiles.
   - **StaticChar.h**: The file from which the non-moving characters inherit.
   - **Tiles.cpp**: The file where we implemented the tiles.
   - **Tiles.h**: The file where we defined the properties of the tiles.
   - **Win.cpp**: The file where we implemented the win tile.
   - **Win.h**: The file where we defined the properties of the win tile.

6. **Main Data Structures and Their Roles:**
   - **vector**: To store the information.
   - **SFML Library**
   - **unique_ptr**

7. **Notable Algorithms:**
   Each shape of the player has its own properties; for example, you cannot win if it is not a square, and even if half of the rectangle touches the holes, you lose.

8. **Known Bugs:**

9. **Other Notes:**
   When creating the levels, first write the number of rows and columns. If it's the first level, also write the total number of levels you will create. Then, build the game: '*' represents the player, '=' represents a regular tile, '+' represents a special tile, 'x' represents the win location, and ' ' represents a hole. It is recommended that the size of the level does not exceed 10 rows and 15 columns.