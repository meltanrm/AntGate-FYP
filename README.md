# AntGate-FYP

In this repo, you will find the STL files and code used to construct an automated ant size sorter system in the <a href="https://github.com/meltanrm/AntGate-FYP/tree/main/Final%20Product">Final Product</a> folder. The relevant files and code used for prototyping and idea iteration can be found in the <a href="https://github.com/meltanrm/AntGate-FYP/tree/main/Prototypes">Prototypes</a> folder.

<b>Integrating ant detection input from the neural network</b>
<br>You will need <a href="https://github.com/FabianPlum/TheStick">TheStick</a> repo and to follow the instructions written there. Replace TheStick's tracker.py and THE_STICK_YOLO.py files with the modified files found in the <a href="https://github.com/meltanrm/AntGate-FYP/tree/main/Final%20Product/OAKD%20neural%20network">OAKD Neural Network folder</a>.

In THE_STICK_YOLO.py, make sure to change the following line to reflect the correct port:
<br><code>ser = serial.Serial("/dev/cu.usbmodem141401", 115200, timeout=None)</code>

You will also need the arduino code in the <a href="https://github.com/meltanrm/AntGate-FYP/tree/main/oakd_to_motor">oakd_to_motor</a> folder.

<b>Recording videos using the OAK-D cameras</b>
<br>This is by no means a necessary part of the AntGate system, however should you want to use record videos using the OAK-D cameras, use the <a href="https://github.com/nimirz/FilmAnts">FilmAnts</a> repo. Should there be problems in running the script, replacing the files with those in <a href="https://github.com/meltanrm/AntGate-FYP/tree/main/Prototypes/OAKD%20recording%20videos">OAKD recording videos</a> seemed to do the trick for me. 

<b><li>Finn Wagner-Douglas, who CADed the funnel</li> </b>

