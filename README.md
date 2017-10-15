# Magic-Tower-Qt

## Screenshots

![choose role](https://user-images.githubusercontent.com/5276065/31418837-25e8d16e-aded-11e7-9f52-b1d504cb79e8.jpg)

![1st floor](https://user-images.githubusercontent.com/5276065/31418838-26002062-aded-11e7-8d38-49ed9972c757.jpg)

![fight](https://user-images.githubusercontent.com/5276065/31418839-262e4c3a-aded-11e7-8656-be1253a34eb0.jpg)

![ice floor](https://user-images.githubusercontent.com/5276065/31418840-26457d56-aded-11e7-8e85-40989a3a6fde.jpg)

![trick floor](https://user-images.githubusercontent.com/5276065/31418841-265c9c20-aded-11e7-9c80-f2122c8722f8.jpg)

![final floor](https://user-images.githubusercontent.com/5276065/31418842-2677e728-aded-11e7-8f7f-b33eb412ec6b.jpg)

## How to use

**NEWS: This game is DEPRECATED due to map data lost 😢]**

To run this game:

1. Download [Qt creator](https://www.qt.io/download-open-source/#section-6)
1. Open `MagicTower.pro` using Qt creator
1. Use the default configure option, after open it, right click the project `"MagicTower"` choose `"qmake"`, then again choose `"build"`
1. **Do not run** (if run you will see a white screen with nothing), you should **copy all the files in "file" directory** into the place where you build it.

	(Windows: In my computer is "{where you put your project}\build-MagicTower-Desktop_Qt_5_3_MSVC2012_OpenGL_32bit-Debug")
	
	(Ubuntu: In my computer is "{where you put your project}\build-MagicTower-Desktop-Debug")
	
	(Mac: In your MagicTower.app/Contents/MacOS folder)

1. Run and enjoy it~

### Ps:

1. If you see error like "Unknown module(s) in QT: multimedia" error in ubuntu, just run "sudo apt-get install qtmultimedia5-dev" and then rebuild
1. It may takes some time during saving and loading, so please wait 1-2 seconds :)

## Features

### GUI
	mainly use QGraphicsview.
### Databese: 		
	connect to my digitalocean server in USA, so it will need a little time to save and load. (currently under maintenance)
	(Why I choose database online is because in the future I want to make this a multiplayer online game :D)
### Cheat: 			
	you can choose cheat option in the "cheat!" menu and do whatever you want. XD
	(GodMode => fight with monster do not decrease your HP but increase it!)
### Gender:			
	different gender has different advantages and disadvantages.
### Shop: 			
	you can buy something like hp, attack, different keys here.
### Book: 			
	you can look up it and know monster more in this floor, "expected damage" is very helpful.
### Miss + Bow: 	
	there will be some random miss or critical damage during fight, so there is no absolute best result.
### BGM: 			
	use QSound (not completely finished, so I just use a example BGM).
### NPC:	
	they will give you some advices.
### Level up:
	kill enough monsters and you will level up, so be brave!
### Help:
	after start game, you can press "h" key for help.
### Different ending:	
	there are three differnt endings, wish you find a nice one :)

### REMEMER! You task is to **save the pricess in the top of the tower.**

## Time

* This game may need 2-3 hours to finish (without cheat!), enjoy it in your free time~ (In the future, floors will increase to 20 or more, so it will be more fun.)

## Credits

* Code by [Armour](http://www.github.com/armour)

* QQ: 497052684

* Email: armourcy@gmail.com

## License

MIT
