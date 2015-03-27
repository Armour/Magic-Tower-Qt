# Magic-Tower-Qt
---

## Use：Qt creator 

---

Here are several main step to run the game:

1. Download [Qt creator](https://www.qt.io/download-open-source/#section-6)
2. Open the MagicTower.pro
3. Use the default configure option, after open it, right click the project "MagicTower" choose "qmake", then again choose "build"
4. **Do not run** (if run you will see a white screen with nothing), you should **copy all the files in "file" directory** into the place where you build it
	(Windows: In my computer is "{where you put your project}\build-MagicTower-Desktop_Qt_5_3_MSVC2012_OpenGL_32bit-Debug")
	(Ubuntu: In my computer is "{where you put your project}\build-MagicTower-Desktop-Debug")
	(Mac: In your MagicTower.app folder)
5. Run it and enjoy it~

#### Ps:	
   1. **In windows**, maybe happen some QMYSQL error, then you should:
	copy the two .dll file in "mysql" directory into "{where you install your Qt}\5.3\msvc2012_opengl\bin" and then rebuild.
      
      **In ubuntu** , just run "sudo apt-get install libqt5sql5-mysql" and then rebuild.
	
   2. If you meet "Unknown module(s) in QT: multimedia" error in ubuntu, just run "sudo apt-get install qtmultimedia5-dev" and then rebuild
   3. During save and load, it will need a little bit of time, so please wait 1-2 seconds.


<br>


## Feature:

---
* ##### GUI 			
		mainly use QGraphicsview.
* ##### Databese: 		
		connect to my digitalocean server in USA, so it will need a little time to save and load. 	
		(Why I choose database online is because in the future I want to make this a multiplayer online game :D)
* ##### Cheat: 			
		you can choose cheat option in the "cheat!" menu and do whatever you want. XD
		(GodMode => fight with monster do not decrease your HP but increase it!)
* ##### Sex:			
		there are two different sex, each have its advantages and disadvantages.
* ##### Shop: 			
		you can buy something like hp, attack, different keys ,etc.
* ##### Book: 			
		you can look up it and know monster more in this floor, "expected damage" is very helpful.
* ##### Miss + Bow: 	
		there will be some random miss or critical damage during fight, so there is no absolute best result.
* ##### BGM: 			
		use QSound (not completely finished, so I just use a example BGM).
* ##### NPC:	
		they will give you some advices.
* ##### Level up:
		if you kill enough monsters, you will level up, so be brave!
* ##### Help:
		after start game, you can press "h" key for help.
* ##### Different ending:	
		there are three differnt ending, wish you have a good one.

* ##### REMEMER! You task is to save the pricess in the top of the tower.</p>


<br>

---

## Time

* This game may need 2-3 hours to end (without cheat!), enjoy it in your free time ~

	(In the future, floors will increase to 20 or more, so it will be more fun.)

<br>

---

<br>

## Imformation

* ##### Made by Armour 

* ##### QQ:		497052684

* ##### Email: 	gc497052684@gamil.com
