# inspirobot-hue

## Installation

Install from source

```
$ git clone https://github.com/huenique/inspirobot-hue.git
```

Download dependencies usings [conan](https://pypi.org/project/conan/)

```
$ mkdir build
$ cd build
$ conan install ../ --build=missing
```

Build the project

```
$ cmake ../
$ cmake --build .
```

## Usage

Run the generated executable

```
$ ./inspirobot-hue
```
