### Objective

Develop a 3D first-person maze exploration game using ray-casting techniques, inspired by the iconic Wolfenstein 3D. The project involves creating a dynamic, realistic 3D representation of a maze, with a focus on C programming and graphic rendering using the miniLibX library.

### Project Requirements

- **Language**: C
- **Libraries**: miniLibX, Math Library (-lm)
- **Functions Used**: open, close, read, write, printf, malloc, free, perror, strerror, exit, gettimeofday
- **Map Input**: A .cub file defining the maze structure and textures.

### Core Features

- **3D Rendering**: Realistic 3D visualization of a maze using ray-casting principles.
- **Texture Mapping**: Display of different textures on maze walls based on orientation (North, South, East, West).
- **User Interaction**: Movement within the maze using keyboard inputs (W, A, S, D) and view adjustment using arrow keys.
- **Window Management**: Smooth transitions between different window states, including resizing and minimizing.
- **Customizable Colors**: Floor and ceiling colors are adjustable for a personalized visual experience.
- **Clean Exit**: Program exits cleanly with ESC key or window close button.

### Implementation

The program reads a scene description file in .cub format, which includes the maze layout and texture paths. Ray-casting is used to render a first-person perspective of the maze, with real-time interaction and smooth graphics handling achieved through miniLibX. Proper memory management and adherence to coding norms ensure stability and performance.
