# TPE Arquitectura de las computadoras

## Description

Kernel based in x64barebones. Arquitectura de las Computadoras subject @ ITBA.

## Instalation

### Enviroment setup

1. Install the following packages
..* nasm
..* qemu
..* gcc
..* make

2. Build the toolchain

  Execute the following commands on the root project directory:

  ```
  user@linux:$ cd Toolchain
  user@linux:$ make all
  ```

3. Build the Kernel

  From the root project directory run:

  ```
  user@linux:$ make all
  ```

4. Run the Kernel

  From the root project directory run:

  ```
  user@linux:$ ./run.sh
  ```

### Authors

Castaño, De Lucca, Soncini

Based on [x64BareBones](https://bitbucket.org/RowDaBoat/x64barebones/wiki/Home) by Rodrigo Rearden (RowDaBoat) and Augusto Nizzo McIntosh.
