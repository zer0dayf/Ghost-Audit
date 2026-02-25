# 👻 Ghost-Audit

![Platform](https://img.shields.io/badge/Platform-Windows-blue)
![Device](https://img.shields.io/badge/Device-Flipper%20Zero%20%7C%20Digispark%20%7C%20Rubber%20Ducky-orange)
![License](https://img.shields.io/badge/License-MIT-green)

**Ghost-Audit** is an advanced post-exploitation and reconnaissance tool designed for BadUSB devices (Flipper Zero, USB Rubber Ducky, Digispark Attiny85). It targets Windows systems to gather comprehensive system, network, hardware, and Wi-Fi information in seconds using optimized command chains.

---

## ⚠️ Legal Disclaimer / Yasal Uyarı

> **EN:** This project is intended for **educational purposes** and **authorized security auditing** only. Usage of these scripts on systems without prior mutual consent is illegal. The author assumes no liability and is not responsible for any misuse or damage caused by this program.
>
> **TR:** Bu proje yalnızca **eğitim amaçlı** ve **yetkili güvenlik denetimleri** için geliştirilmiştir. İzinsiz sistemlerde kullanımı yasadışıdır. Bu yazılımın kötüye kullanımından doğacak sorumluluk tamamen kullanıcıya aittir.

---

## 🚀 Features & Modes

Ghost-Audit features two distinct operational modes tailored for different engagement scenarios:

### ⚡ 1. Stealth Mode (Fast)
Designed for speed and invisibility. It executes chained commands in a minimized window to grab essential data instantly.
* **Payload Name:** `Stealth_Mode_PAYLOAD`
* **Execution Time:** ~5-8 Seconds
* **Technique:** Minimized CMD window (`cols=20`), optimized command chaining (`&`).
* **Output:** `%USERPROFILE%\Desktop\Logs`
* **Data:** Basic IP/DNS, ARP Table, Wi-Fi Profiles, User Info.

### 🔍 2. Detailed Mode (Forensic)
Designed for deep system analysis. It creates a structured log hierarchy and digs deep into the system internals using stable delays.
* **Payload Name:** `Detailed_Mode_PAYLOAD`
* **Execution Time:** ~30-40 Seconds
* **Technique:** Stable execution flow, detailed queries, registry parsing.
* **Output:** `%USERPROFILE%\Desktop\PC_Audit_Logs`
* **Data:**
    * 🖥️ **System:** CPU/RAM/Disk details, Installed Software (Registry), USB Connection History, Services, Processes.
    * 🌐 **Network:** Full IP Config, DNS History, Route Table, Active Connections (Ports), Shares, Firewall State.
    * 🔑 **Wi-Fi:** Exports **ALL** saved Wi-Fi profiles (SSID & Passwords) to XML files.

---

## 🛠️ Payload Generator CLI

Instead of manual edits, you can dynamically compile heavily customizable payloads directly from your terminal using the built-in generator:

```bash
chmod +x generate_payload.sh

# Generate a stealth payload with custom delay
./generate_payload.sh --mode stealth --delay 100 --output Payloads/Generated/my_stealth.txt

# Generate a detailed payload with a custom log export drive/folder
./generate_payload.sh --mode detailed --delay 250 --drive "D:\MyHiddenLogs"
```

*Generated payloads will be safely stored in the `Payloads/Generated/` folder without affecting git history.*

---

## 📂 Repository Structure

```text
Ghost-Audit/
├── generate_payload.sh         # Dynamic Shell Generator CLI
├── Payloads/
│   ├── Generated/              # Dynamically compiled `.txt` output folder
│   ├── FlipperZero/            # .txt payloads for Flipper Zero / Rubber Ducky
│   │   ├── Stealth_Mode_PAYLOAD.txt
│   │   └── Detailed_Mode_PAYLOAD.txt
│   │
│   └── Digispark/              # .ino sketches for Arduino IDE
│       ├── Stealth_Mode_PAYLOAD/
│       │   └── Stealth_Mode_PAYLOAD.ino
│       └── Detailed_Mode_PAYLOAD/
│           └── Detailed_Mode_PAYLOAD.ino
│
├── LICENSE                     # MIT License
└── README.md                   # Documentation
