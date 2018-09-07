unix {
    OS = unix
}

linux {
    OS = linux
}

macx {
    OS = mac
}  

win32 {
    OS = windows
}

!unix:!win32 {
    OS = other
}
