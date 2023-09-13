# 👹🎮 So_long 🎮👹 
So_long.gif

This project is a very small 2D game.
Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements.

## Game Description

In this project the roles have changed! You will play as a little demon that has been trapped in his dungeon by little hyperactive birds.

Your goal is to collect the magical golden orbs that the birds took from you.
These orbs allow you to cast spells and open the door that leads to your freedom!
Are you mischievous enough to escape are will the kingdom finally live in peace ?

## How to play?

Clone the repository with ``git clone`` to your pc.

Enter the ``so_long`` directory, open the terminal and type ``make`` (to play the mandatory version) or ``make bonus`` (to play the bonus version).

Run the ``./so_long`` program with one of the files in the maps folder (ex:.valid_map_bigger.ber) or create your own. As long as it validates the following rules it will run:

    • The map has to be constructed with 3 components: walls, collectibles, and free space.
    • The map can be composed of only these 5 characters:
       - 0 for an empty space,
       - 1 for a wall,
       - C for a collectible,
       - E for a map exit,
       - P for the player’s starting position.
    • The map must contain 1 exit and 1 starting position to be valid and at least 1 collectible
    • The map must be rectangular.
    • The map must be closed/surrounded by walls. If it’s not, the program must returnan error.
    • You have to check if there’s a valid path in the map.
In order to move, use the WASD or the up (↑), down (↓), left (←), right (→) arrow keys. If you fail to capture the orbs and want to end the game press the ESC key or press the X in the window with the mouse.

## Key take aways

With this project I learned how to work with the miniLibX library to create graphic environments with interactive features, as well as increase my coding knowledge and problem solving, 
since I used several approach and needed to create different strategies to overcome obstacles.
In the future I would like to revisit this project and further develop it by adding menus, level selectors and other features.
