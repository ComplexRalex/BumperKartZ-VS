# BumperKartZ-VS
A mini-game about bumper karts (cars). Originally created by me and my friends for a final project on the Computer Graphics course in the college. Now I've added some new stuff!

![Logotype of the game 'Bumper KartZ'](https://user-images.githubusercontent.com/47804156/120940456-034a2a00-c6e3-11eb-9a3d-e135d39ae921.png)

[![GitHub release (latest by date)](https://img.shields.io/github/v/release/ComplexRalex/BumperKartZ-VS)](https://github.com/ComplexRalex/BumperKartZ-VS/releases/latest) [![GitHub Release Date](https://img.shields.io/github/release-date/ComplexRalex/BumperKartZ-VS)](https://github.com/ComplexRalex/BumperKartZ-VS/releases/latest) [![GitHub last commit](https://img.shields.io/github/last-commit/ComplexRalex/BumperKartZ-VS)](https://github.com/ComplexRalex/BumperKartZ-VS/commit/master) [![GitHub](https://img.shields.io/github/license/ComplexRalex/BumperKartZ-VS)](https://github.com/ComplexRalex/BumperKartZ-VS/blob/master/LICENSE)

## Description
This is a mini-game made in C++ with OpenGL (freeglut) about bumper karts (cars)!

## Gameplay
You're a kart, and you want to clash into another kart (is it necessary to explain this?). The view is just above of the kart and the controls (for player 1) are the following:
* Go forward: ``W``
* Go backward: ``S``
* Turn right: ``D``
* Turn left: ``A``

For player 2, the controls are the next ones:
* Go forward: ``I``
* Go backward: ``K``
* Turn right: ``L``
* Turn left: ``J``

By the way, to navigate on the menu you must use ``W`` and ``S``, and to select an option you must press the ``SPACE`` bar. To exit the current game, just press ``ESCAPE``. There are some other special keys as well. You can check them out in the game menu!

## How to run
There are two ways to play this.
* The first one, is downloading (or cloning) this repository and follow the instructions inside the ``Release/`` or ``Debug/`` folders. The instructions are the following:
  * Copy the "res/" folder in the same folder as the runnable.
  * Download "freeglut 3.0.0 MSVC Package" from here [https://www.transmissionzero.co.uk/software/freeglut-devel/](https://www.transmissionzero.co.uk/software/freeglut-devel/), uncompress it and copy "freeglut.dll" file inside freeglut/bin/ (not x64) into the same folder as the runnable.
  * Double-click the runnable (or .exe).
* The second one requires nothing but literally download the release of the game in the [**Releases**](https://github.com/ComplexRalex/BumperKartZ-VS/releases) section, uncompress it, and run the ``.exe`` file! Note that your system will probably be triggered because of the runnable, but just skip it and play.

Right now, this game only runs on Windows.

## Screenshots
![MainMenu1](https://user-images.githubusercontent.com/47804156/120941083-64273180-c6e6-11eb-91e3-74d7c6e364ae.png)
![Gameplay1](https://user-images.githubusercontent.com/47804156/120941085-65f0f500-c6e6-11eb-865e-46b765c8fc63.png)
![Gameplay2](https://user-images.githubusercontent.com/47804156/120941086-67222200-c6e6-11eb-9a6f-493a2ab3bc0a.png)
![Gameplay3](https://user-images.githubusercontent.com/47804156/120941089-68534f00-c6e6-11eb-9bad-8184a51bd751.png)
![MainMenu2](https://user-images.githubusercontent.com/47804156/120941091-69847c00-c6e6-11eb-879e-02c29eb3d212.png)

## Report issues!
BUGS?! BUT WHY! Nah, it's ok. There will always be bugs somewhere. You can report them [here](https://github.com/ComplexRalex/BumperKartZ-VS/issues/new/choose)! Also, you can request features (but depends on the complexity and time to add these though).

## Credits
* This game was designed by @ComplexRalex, @DannyMannn, and @Mokkuman.
* This was coded in C++ with OpenGL (with [freeglut](http://freeglut.sourceforge.net/)).
* In order to load images, there were used functions from [RgbImage library](https://www.math.ucsd.edu/~sbuss/MathCG2/OpenGLsoft/RgbImage/index.html) by Sam Buss.
