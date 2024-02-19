# miniRT
project made with --> ple-lez "https://github.com/ple-lez"

This project focuses on implementing a ray tracing engine using the minilibX library. The engine is capable of rendering scenes containing geometric objects such as planes, spheres, and cylinders with realistic lighting effects.

## Features

- Implementation of a ray tracing engine using the minilibX library.
- Rendering of basic geometric objects including planes, spheres, and cylinders.
- Proper handling of window management for smooth user interaction.
- Support for changing window resolution without distorting scene content.
- Application of transformations to objects, lights, and cameras including translation and rotation.
- Management of light sources with ambient and diffuse lighting.
- Reading scene descriptions from `.rt` files, specifying elements such as ambient light, camera position, light sources, and geometric objects.
- Handling of potential configuration errors with informative error messages.

## Additional Features

In addition to the core features, the ray tracing engine supports the following advanced functionalities:

- Specular reflection for a complete Phong reflection model.
- Color perturbations such as checkerboard patterns.
- Support for colored lights and multi-spotlights.
- Introduction of second-degree objects such as cones, hyperboloids, and paraboloids.
- Texture mapping with bump maps for realistic surface details.

## Scene Description Format

The scene description file (`.rt`) follows a specific format:

- Each element type is separated by one or more newline characters.
- Information for each element type can be separated by one or more spaces.
- Elements can be declared in any order in the file.
- Elements starting with an uppercase letter can only be declared once in the scene.
- Each element begins with a type identifier (one or two characters), followed by specific information for that element.

Example of a minimalistic scene description:
```css
A 0.2 255,255,255
C -50,0,20 0,0,0 70
L -40,0,30 0.7 255,255,255
pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,0
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
```

## Usage

To run the program, provide the scene description file as the first argument:

```bash
./miniRT scene.rt
```

##Dependencies
  minilibX library


![Texte alternatif](./gallery/sphere_texture.png)
![Texte alternatif](./gallery/spheres_texture.png)

![Texte alternatif](./gallery/mult_shapes.png)
![Texte alternatif](./gallery/mult_shapes2.png)

![Texte alternatif](./gallery/mult_shapes_light.png)

![Texte alternatif](./gallery/mult_triangles.png)


Once the triangles are created, we can have some fun.


![Texte alternatif](./gallery/fox2.png)
![Texte alternatif](./gallery/dragon.png)


We can retrieve objects created in Blender, then by triangulating them, we can obtain the coordinates of the triangles in an STL file.


![Texte alternatif](./gallery/gutsBlender.png)
![Texte alternatif](./gallery/guts.png)







