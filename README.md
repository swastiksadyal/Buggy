# Buggy
Control your Arduino through your mobile phone and PC via a Wi-Fi socket and android app.

I`ve uploaded most of the files here except some gradle builds and stuff which you can do yourself.

## Required Stuff
- Arduino (I used Arduino UNO but you can use any one you want to use, Be sure to check for vendor ID and change so in the "/device filter" and other places where vendor ID is used, like in "main java file"
- OTG : I used the OTG to connect my android to the arduino so otg was a must have. But if you can/want to use something else do so.
- Android Studio
- Python ( I used python to create the client/server system. because I`m good with python than any other lanuage.

## what are we acthually doing?
I connected arduino to my old android and created a socket system bitween arduino and android and same with android to pc. So that just i can controll my arduino with my PC.
also android acts as a separate brain to the microcontroller which can be used to deploy ML and faster path finding algorithms in the robot you are creating.

// entire code is free to use but it`ll be nice you can give me some credit :) 
