# My Radar - Air Traffic Control Simulation

"My Radar" is a graphical program developed in C, designed to simulate and visualize air traffic including aircraft and control towers. This project is part of the B-MUL-100 module, focusing on C graphical programming with the CSFML library.

## Features

- **Simulation of Air Traffic:** Displays moving aircraft and stationary control towers on a 2D panel.
- **Collision Handling:** Aircraft collide and are destroyed unless within a control tower's area.
- **Control Areas:** Defined by control towers, these areas prevent aircraft collisions.
- **Flexible Scripting:** Entities and their behaviors are defined in an external script, allowing for dynamic simulations.

### Command-line Options

- **-h:** Displays usage information.

### User Interactions

- **'L' Key:** Toggles the visibility of hitboxes and control areas.
- **'S' Key:** Toggles the visibility of entity sprites.

## Getting Started

### Prerequisites

- Linux or macOS operating system
- GCC compiler
- CSFML library

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/my_radar.git
   ```
2. Navigate to the project directory:
```bash
cd my_radar
   ```
3. Compile with Makefile:
```bash
make
   ```
## Usage
Run the program with a script file as an argument:

```bash
./my_radar path_to_script
   ```
For help and options:

```bash
./my_radar -h
   ```
## Script File Format
The simulation script defines aircraft and control towers with the following format:

Aircraft (A): A [departure x] [departure y] [arrival x] [arrival y] [speed] [takeoff delay]
Control Tower (T): T [x coordinate] [y coordinate] [control radius]
Entities should be separated by a newline, with attributes separated by tabs or spaces.

Example script content:

```css
A 815 321 1484 166 5 0
A 1589 836 811 936 2 0
A 202 894 103 34 3 0
T 93 47 19
T 49 56 25
   ```  

## Authorized Functions
This project is limited to specific functions from the C Standard Library, CSFML library, and math library. Unspecified functions are not allowed.  
