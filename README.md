ofxMSATimer
===========

Memo Atken's precise timer class from MSALibs but with Windows support

Uses Windows API QueryPerformanceCounter: 
http://msdn.microsoft.com/en-us/library/windows/desktop/ms644905(v=vs.85).aspx

QueryPerformanceCounter retrieves the frequency of the high-resolution performance counter, if one exists. If the installed hardware supports a high-resolution performance counter, the return value is nonzero.