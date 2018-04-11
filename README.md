# ROS-Homework-1

This file is part of ROS-Homework-1 and it is distributed under the terms of the
GNU Lesser General Public License (Lesser GPL)

Laboratorio Ciberfisico<br>
[Robot Programming with ROS](http://profs.scienze.univr.it/~bloisi/corsi/ciberfisico.html)<br>
A.Y. 2017/2018<br>
University of Verona (Italy)

![laboratorio ciberfisico](img/cyberphysical-lab.jpg)

Il compito ha l'obiettivo di realizzare un menu che in base alla selezione dell'utente, un nodo ROS stampa le informazioni ricevuto dal nodo talker, presentandole in base all'opzione scelta.

## Installazione:
  ### Prerequisiti:
  Cosa serve prima dell'installazione:
  ```
  -ROS Kinetic
  -Ubuntu 16.04
  ```
  Come clonare il package:
  ```
  -aprire il terminale
  -cd ~/catkin_ws
  -cd src/
  -git clone URL_DA_CLONARE
  ```
  Per installare il package:
  ```
  -aprire il terminale
  -cd ~/catkin_ws
  -catkin_make install
  ```
## Eseguire il launcher:
   Per eseguire il launcher:
   ```
  -aprire il terminale
  -cd ~/catkin_ws
  -roslaunch PACKAGE_NAME PACKAGE_NAME.launch   (In questo caso PACKAGE_NAME è ROS_Homework_1)
  ```

First assignment of cyber-physical laboratory
