# TP-Armadeus-CryptoMorse
This repository contains a Embedded System group project. 

The goal of the project is to create a software for the Armadeus board that receives messages, crypt them, convert them to morse, and send them through GPIOs.

## How to compile the armadeus BSP
- __gcc version__: 4.8.4
- __g++ version__: 4.8.4

```bash
> git clone https://github.com/pblottiere/armadeus.git
> cd armadeus
> make apf28_defconfig
# make sure you have g++
> make all
```

### (Optional) Python Dev

[Tutorial](http://www.armadeus.org/wiki/index.php?title=Python_development)

## Communicating with board using TFTP

[Tutorial](http://www.armadeus.org/wiki/index.php?title=Communicate_with_your_board_from_a_Linux_Host_(Basics))

## Flashing the built kernel

[Tutorial](http://www.armadeus.org/wiki/index.php?title=Target_Software_Installation)


## Compiling code and pushing to board

[Tutorial](http://www.armadeus.org/wiki/index.php?title=HelloWorld)


## Using autotools

[Tutorial](http://markuskimius.wikidot.com/programming:tut:autotools/)