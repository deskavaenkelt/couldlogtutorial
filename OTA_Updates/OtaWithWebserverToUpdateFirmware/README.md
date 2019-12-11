# OTA with Web Server to update Firmware

This is an alternative if we want to access the different boards via a hostname like `otaesp.local` in your browser.

## Hostname's
Since I use 4 pcs of LOLIN32 i'll give the the hostname's:
* `LOLIN32_0`
* `LOLIN32_1`
* `LOLIN32_2`
* `LOLIN32_3`

You can change them in `auth.h` along with your wifi credentials.

## Username and password for OTA
Can be found in `webserverCode.h` on row 23:  
`"if(form.userid.value=='admin' && form.pwd.value=='pass')" //Autheticate user before OTA Update`

Change `admin` and `pass` to whatever you want, you can't upload anything without these credentials.

## Important
You have to include this code in every update you do or you will break the OTA functionality.  

#### Note
This code builds upon code from [Makerdemy/Advanced-ESP32][Makerdemy/Advanced-ESP32], `section2/2.3/Enable_OTA`  with additions and modifications.






[Makerdemy/Advanced-ESP32]: https://github.com/Makerdemy/Advanced-ESP32