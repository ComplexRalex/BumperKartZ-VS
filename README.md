# Bumper KartZ: VisualStudio version

A mini-game about bumper karts (cars). Originally created by me and my friends for a final project on the Computer Graphics course in the college. Now I've added some new stuff!

<p align="center">
    <img src="https://user-images.githubusercontent.com/47804156/120940456-034a2a00-c6e3-11eb-9a3d-e135d39ae921.png" title="Logotype of Bumper KartZ VS game" alt="Bumper KartZ VS">
</p>

<p align="center">
    <a href="https://github.com/ComplexRalex/BumperKartZ-VS/releases/latest"><img src="https://img.shields.io/github/v/release/ComplexRalex/BumperKartZ-VS" alt="GitHub release (latest by date)"/></a>
    <a href="https://github.com/ComplexRalex/BumperKartZ-VS/releases/latest"><img src="https://img.shields.io/github/release-date/ComplexRalex/BumperKartZ-VS" alt="GitHub Release Date"/></a>
    <a href="https://github.com/ComplexRalex/BumperKartZ-VS/commit/main"><img src="https://img.shields.io/github/last-commit/ComplexRalex/BumperKartZ-VS" alt="GitHub last commit"/></a>
    <a href="https://github.com/ComplexRalex/BumperKartZ-VS/blob/master/LICENSE"><img src="https://img.shields.io/github/license/ComplexRalex/BumperKartZ-VS" alt="GitHub License"/></a>
</p>

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

![MainMenu1](https://github.com/user-attachments/assets/a2f3d435-d184-4558-b9b4-e8072c5b20f5)
![Gameplay3](https://github.com/user-attachments/assets/aaa2914b-3bf6-42f2-9514-5b400e87395b)
![Gameplay2](https://github.com/user-attachments/assets/12c15879-5d8f-4a5e-9bbc-83ff8fc1b4c7)
![Gameplay1](https://github.com/user-attachments/assets/efd44a4d-3c49-4489-a20d-f760e1eee153)
![MainMenu2](https://github.com/user-attachments/assets/27e361e3-1eb2-4aff-a66e-b8ce33d74dd2)

## Report issues!

BUGS?! BUT WHY! Nah, it's ok. There will always be bugs somewhere. You can report them [here](https://github.com/ComplexRalex/BumperKartZ-VS/issues/new/choose)! Also, you can request features (but depends on the complexity and time to add these though).

## Credits

* This game was designed by [@ComplexRalex (me)](https://github.com/ComplexRalex), [@DannyMannn](https://github.com/DannyMannn), and [@Mokkuman](https://github.com/Mokkuman).
* This was coded in C++ with OpenGL (with [freeglut](http://freeglut.sourceforge.net/)).
* In order to load images, there were used functions from [RgbImage library](https://www.math.ucsd.edu/~sbuss/MathCG2/OpenGLsoft/RgbImage/index.html) by Sam Buss.
