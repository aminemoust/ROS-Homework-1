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
  Una volta eseguito il launcher si dovrebbe ottenere una schermata di questo tipo:
  ![Esecuzione](img/example_run.png)

## Grafo di esecuzione:
![grafo del package](img/graph.png)

### Talker
Genera le informazioni e le invia nel topic "info"

### Menu_select:
Stampa a video un menu di selezione e invia l'opzione selezionata dall'utente nel topic "menu"

### Printer:
Si occupa di stampare a video le informazioni ricevuto dal talker in base all'opzione selezionata dall'utente


## Scelta progettuale:
Il tipo di messaggio è un messaggio custom, con 3 campi:
```
  -name:  di tipo string che contiene un nome;
  -age: di tipo uint8 che contiene un'età;
  -degree:  di tipo string che contiene un corso di laurea;
```
La scelta di usare tre campi, invece di un std_msgs, è dovuta dal fatto di semplificare la ricezione dei dati.
Un parsing della stringa sarebbe stato inutilemente complicato e meno efficiente in termini di prestazioni.

Il campo **"age"** è di tipo uint8, in quanto si suppone che l'età di una persona non superi i 255 anni.

Si è scelto di mettere il controllo dell'opzione scelta dall'utente nel modulo **printer** per rendere al modulo **talker**, un invio dei dati "veloce".<br>
N.B.: Mettere il controllo dell'opzione direttamente nel **talker** può essere una soluzione plausibile e probabilmente renderebbe la stampa al **printer** quasi in "real-time". Dall'altro canto questa soluzione potrebbe rendere meno efficiente il **talker** se riceve molte informazioni dal **menu_select**.


First assignment of cyber-physical laboratory<br>
For any suggestion/bugs/typos report to <br>
amine.moustaghfir@studenti.univr.it
