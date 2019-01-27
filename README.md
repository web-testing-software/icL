# Wellcome to icL

icL is a modern and powerfull web driver. If you want to participate in your
project please read the standard for language icL. Now the standard is in 
developement. Please wait for details. 

The documentation of icL code can be found 
[here](https://web.testing.gitlab.io/icL-docs/docs/).

## What icL does?

icL automates the functional testing of web-applications, it speeds up the
writing of autotests, debug and running of tests itself (it will use all
available machines to run tests parallel, 2 machines with quandcore processors
will speed up the running of test cases up to 8 times).

## Features of icL

**Cross platform** — *Develop and test anywhere*

All icL utilities are available under Windows, Linux and Mac OS X.

**Cross browser** *testing*

You can user build-in browser or test on browsers, supported by Selenium Web
Driver: Chrome, Firefox, MS Edge, MS IE, PhanthomJS.

**icL Editor** — *Work together*

Editor permit developing tests in team. Each change will be shared with your
coworkers. You can share not just the final version, but the draft too.

**icL FlyTime** — *Analising for you*

FlyTime is a hybrid code analyzer, which can detect errors in code and speak to
you, where the program can crash. The hybrid analyzer is more powerful than a
static analyzer.

**icL FlyProgramming** — *Edit code always*

FlyProgramming permits editing code on run time, just forgot about stop and run
again, just fix code and be happy.

**icL Crossfire** — *Call back*

From icL you can call JavaScript functions. And from JavaScript in web page, you
can call icL functions.

**icL Sync** — *Sync test and back-end*

The synchronization is not possible just with web page, the back-end also can be
synchronized. An ideal solution for long asynchronous processes on server side.

## Look

The application will have the next look -
![Light theme icL](images/light.png)

Already will be avialble a dark theme
![Dark theme icL](images/dark.png)

For more images see [here](layouts/).

## icL vs Selenium

icL is not an alternative for Selenium, but for a stack : Selenium + Selenium 
Grid + Ranorex Studio + Ranorex Selocity. 

For crossplatform testing Selenium use the next architecture -
![Selenium Grid Architecture](images/selenium-grid.png)

icL use a more complex, but more peformant architecture -
![icL share architecture](images/icL-share.png)

Comparation between icL share and Selenium Grid -

|Criteria              |Selenium Grid| icL share |
|----------------------|-------------|-----------|
|multithreading        |manual       |automatic  |
|trafic                |commands     |code + data|
|browsers              |same         |same + icL |
|API                   |W3C + JSWP   |W3C only   |
|crossplatform         |yes          |yes        |
|autoshare             |no           |yes        |
|optimization          |no           |yes        |
|extern IDE needed     |yes          |no         |
|safe password storange|no           |yes        |

## Contributing

You can contribute by code or translations. 
Please read [CONTRIBUTING.md](CONTRIBUTING.md)

But if you are still reading that, it means you want to contribute by money.

Tiers for you:
[![Become a patron](https://c5.patreon.com/external/logo/become_a_patron_button.png)](https://www.patreon.com/icL)

Microdonations:
[![Donate](https://liberapay.com/assets/widgets/donate.svg)](https://liberapay.com/icL/donate)

One-time transfer: [Yandex.Money](https://yasobe.ru/na/icl)

## License

![GPLv3](https://www.gnu.org/graphics/gplv3-127x51.png)

This program is licensed under GNU General Public License, Version 3.

## Third Parts

File graduation/src2pdf.sh was copied from 
[src2pdf](https://github.com/arosspope/src2pdf.git) project and modified. It
is distributed under MIT license.
