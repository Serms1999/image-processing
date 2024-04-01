# Image Processing, Analysis and Classification

Personal repository for Image Processing, Analysis and Classification course 2023/24

## Dependencies

### C++

- [OpenCV](https://opencv.org/)

### Python

The dependencies for Python are listed in the [`requirements.txt`](requirements.txt) file. To install them execute:

```{sh}
pip install -r requirements.txt
```

## Build

To build the code execute:

```{sh}
cmake . -Bbuild && cmake --build build
```

`build` and `bin` directories should have been created.

## Repository explanation

The executables of all exercises are located in `bin` directory.

Every exercise source code is located under [`src`](src) directory. However,
there are some functionalities that are commonly repeated, so libraries have
been created to avoid that. The list of libraries is:

- [`Erosion`](lib/Erosion)
- [`Dilation`](lib/Dilation)
- [`Opening`](lib/Opening)
- [`Closing`](lib/Closing)
- [`Neighbors`](lib/Neighbors)
- [`Flatzone`](lib/Flatzone)
- [`Infimum`](lib/Infimum)
- [`Supremum`](lib/Supremum)
- [`Compare`](lib/Compare)

Under [`doc`](doc) directory it can be found the [solution](doc/Theoretical_exercises.pdf) to the theoretical
exercises ([Exercise 2d](src/exercise2/Exercises_02d_1.pdf), [Exercise 8a](src/exercise8/Exercises_08a_1.pdf), [Exercise 9a](src/exercise9/Exercises_09a_1.pdf))

Comparative exercises ([Exercise 5](src/exercise5), [Exercise 7](src/exercise7)) do not have code themselves. They check
some properties, so few shell scripts have been created to solve the exercises.

Classification exercises are located under [`classification`](src/classification) directory. They are implemented using
Jupyter Notebooks. They are also exported as PDF files to be easily read.
