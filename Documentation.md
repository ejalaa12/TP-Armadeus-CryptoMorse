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

__Note__: _the `make` command needs to download files, so it might not work on the school connection because of the proxy_

### (Optional) Python Dev

[Tutorial](http://www.armadeus.org/wiki/index.php?title=Python_development)

## Communicating with board using TFTP

### Installing TFTP

[Tutorial](http://www.armadeus.org/wiki/index.php?title=Communicate_with_your_board_from_a_Linux_Host_(Basics))

 1. Install and create the folder for exchanging tftp files

	```bash
	# install tftp
	> sudo apt-get install tftpd xinetd
	# create the folder for exchange
	> sudo mkdir /tftpboot
	> sudo chmod 777 /tftpboot
	```

 2. Edit or create the configuration file /etc/xinetd.d/tftp and modify/add it the following lines:

	```
	# default: off
	# description: The tftp server serves files using the trivial file transfer
	#       protocol.  The tftp protocol is often used to boot diskless
	#       workstations, download configuration files to network-aware printers,
	#       and to start the installation process for some operating systems.
	service tftp
	{
	       socket_type             = dgram
	       protocol                = udp
	       wait                    = yes
	       user                    = root
	       server                  = /usr/sbin/in.tftpd
	       server_args             = -s /tftpboot
	#       disable                 = yes
	}
	```
  	
 3. Restart xinetd service

	```bash
	> sudo killall -HUP xinetd
	```

### Connect to the board

<!-- ![Board Connection](http://www.armadeus.org/wiki/index.php?title=File:BoardConnection.png) -->

#### Configure minicom

[Tutorial](https://help.ubuntu.com/community/SerialConsoleHowto)

#### Access BIOS

1. Connect to the board using `minicom`
2. Reset the board (button RESET)
3. Cancel the boot by pressing any key... 

#### Configure IP addresses

```bash
> setenv ipaddr <ip found with dhcp>
> setenv serverip <PC/host ip>	# 172.20.5.2 works well
> saveenv
```

Restart

### Flashing the kernel

[Tutorial](http://www.armadeus.org/wiki/index.php?title=Target_Software_Installation)

Copy the images to tftp and

```bash
> cp buildroot/output/images/* /tftpboot
> run update_kernel
> run update_rootfs
```
  	
#### Troubleshooting

How to reset everything

```bash
BIOS> run update_uboot
BIOS> reset
BIOS> run flash_reset_env
...
BIOS> run update_kernel
BIOS> run update_rootfs
```

### Sending a binary to the board

[Tutorial](http://www.armadeus.org/wiki/index.php?title=HelloWorld)

Use `arm-linux-gcc` in (`armadeus/buildroot/output/host/usr/bin/`) to compile and generate the binary of your code for the armadeus

## Using autotools to compile the project

[Tutorial](http://markuskimius.wikidot.com/programming:tut:autotools/)