# AntGate-FYP

In this repo, you will find the relevant STL files and code used to construct an automated ant size sorter system. 

<b>Integrating ant detection input from the neural network</b>
<br>The neural network for ant detection is already integrated into this project in the <a href="https://github.com/meltanrm/AntGate-FYP/tree/main/OAKD%20Operation">OAKD Operation folder</a>, and with the arduino code in the <a href="https://github.com/meltanrm/AntGate-FYP/tree/main/oakd_to_motor">oakd_to_motor</a> folder. However, to obtain the most updated version of the neural network (especially when it eventually gains weight estimation capacity!), clone the <a href="https://github.com/FabianPlum/TheStick">original repo</a> and replacing the following files with the correspondingly named files in the <a href="https://github.com/meltanrm/AntGate-FYP/tree/main/OAKD%20Operation">OAKD Operation folder</a>:
<li>tracker.py</li>
<li>THE_STICK_YOLO.py</li>

<br><b> Acknowledgements </b>
<li>Fabian Plum, who created the neural network</li>
<li>Y3 Group for their help with modifying the files in the network</li>
<li>Finn Wagner-Douglas for designing the funnel</li> <p style="color:red"> can't findit

