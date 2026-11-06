*This project has been created as part of the 42 curriculum by maumonte, saalexan.*

# cub3D

## Description

cub3D is a 42 project focused on creating a first-person 3D game using raycasting.

The project takes a maze described in a `.cub` configuration file and transforms it into a navigable 3D environment. The player can move through the map, rotate the camera, and explore the environment from a first-person perspective.

The program parses and validates the map configuration, loads the required wall textures, applies the configured floor and ceiling colors, and renders the scene in real time using raycasting.

The project is developed in C and uses MiniLibX to create the game window, render the scene, load images, and handle user input and window events.

### Bonus
* The bonus part extends the game with additional features such as:
* Minimap to display the map and the player's position.
* Wall collision detection.
* Doors that can open and close.
* Sprites and animated elements.## Description

cub3D is a 42 project focused on creating a first-person 3D game using raycasting.

The project takes a maze described in a `.cub` configuration file and transforms it into a navigable 3D environment. The player can move through the map, rotate the camera, and explore the environment from a first-person perspective.

The program parses and validates the map configuration, loads the required wall textures, applies the configured floor and ceiling colors, and renders the scene in real time using raycasting.

The project is developed in C and uses MiniLibX to create the game window, render the scene, load images, and handle user input and window events.

* Mouse-controlled camera rotation.

## Instructions

### Compilation

```text
make
```

### Bonus

```text
make bonus
```

### Execution

```text
./cub3D maps/map.cub
```

### Cleaning

```text
make clean
make fclean
make re
```

### Controls

| Key | Action        |
| --- | ------------- |
| W   | Move forward  |
| S   | Move backward |
| A   | Move left     |
| D   | Move right    |
| ←   | Rotate left   |
| →   | Rotate right  |
| ESC | Exit the game |

## Key Features

* First-person 3D rendering using raycasting.
* Parsing and validation of `.cub` map files.
* Four wall textures based on orientation.
* Floor and ceiling color configuration.
* Player movement and camera rotation.
* Collision detection with walls.
* Map validation and error handling.
* Bonus features such as a minimap, doors, sprites, or mouse controls, when implemented.

## Technologies Used

* **C** — Main programming language.
* **MiniLibX** — Graphics, window management, images, and events.
* **Makefile** — Project compilation and dependency management.
* **libft** — C utility functions, when used by the project.

## Resources

* 42 School — cub3D subject and project requirements.
* MiniLibX documentation and examples.
* Lode's Computer Graphics Tutorial — Raycasting: https://lodev.org/cgtutor/raycasting.html
* C documentation and Linux man pages.
* Git documentation.

## Usage of AI

AI tools were used as a learning and development aid throughout the project.

They helped with:

* Understanding raycasting concepts and mathematical calculations.
* Understanding C and MiniLibX concepts.
* Identifying bugs and compilation errors.
* Improving code structure and debugging techniques.
* Understanding memory management.

All AI-generated suggestions were reviewed, tested, and adapted to the project's requirements. The final implementation and understanding of the code remain the responsibility of the project authors.
