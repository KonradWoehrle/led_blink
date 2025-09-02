Project in VisualStudio Code

Board: stm32nucleo L452RE

Extention: PlatformIO

Just to verify board-connection

UART per TTL-234X-5V

Note für Tests auf dem Host:
    mit #include "gtest/gtest.h" holt der Test sich den google test, auch wenn VS das rot markiert.
    wo der Compiler überall nach dem Verzeichnis sucht ist in irgendeiner CMakeList angegeben.

    der Ordner wo der wogtest liegt wurde umbenannt, damit er mit #include "gtest/gtest.h" nicht eingebunden wird...
