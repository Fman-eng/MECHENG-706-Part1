***************************************************************
* MECHENG 706 Project One - Group 2
* by Jake Olliff joll113@aucklanduni.ac.nz
* and Lachlan Barnes lbar461@aucklanduni.ac.nz
* and Freeman Porten fpor552@aucklanduni.ac.nz
* and Calvin Lee clee822@aucklanduni.ac.nz
*
***************************************************************
RUNNING THE CODE:
1) Before you can run any code you may need to install all the 
required libaries namely;
    - Servo V1.1.6
You can install the Servo libary and potentially the PID libary using 
Arduino's libary manager in Tools-> Manage Libaries - > Then using the 
search bar.

2) To open the files in an Arduino IDE, double click the main.ino file. 
Alternatively, inside of the Arduino IDE, you can go File->Open and then
from there select to open the main.ino file. Doing so will automatically
open the other files.

3) Building and uploading the files is the same for other arduino files. Just
select 'Verify' to compile all the files or 'Upload' to compiles and upload
the files to the selected port/board. 

CHANGING THE PINS:
If the board or pin arrangement is changed, the code can be changed from
the main.ino file where all the different object's are instantiated.
For example, when the 'SonarSenor' object is instantiated it is done with
the pins of the sonar sensor, if you want to change the pins this is done
during instantiation in main.ino.