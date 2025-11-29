\*\*Ghost-Audit\*\* is an advanced post-exploitation and reconnaissance tool designed for BadUSB devices (Flipper Zero, USB Rubber Ducky, Digispark Attiny85). It targets Windows systems to gather comprehensive system, network, hardware, and Wi-Fi information in seconds using optimized command chains.



---



\## ⚠️ Legal Disclaimer / Yasal Uyarı



> \*\*EN:\*\* This project is intended for \*\*educational purposes\*\* and \*\*authorized security auditing\*\* only. Usage of these scripts on systems without prior mutual consent is illegal. The author assumes no liability and is not responsible for any misuse or damage caused by this program.

>

> \*\*TR:\*\* Bu proje yalnızca \*\*eğitim amaçlı\*\* ve \*\*yetkili güvenlik denetimleri\*\* için geliştirilmiştir. İzinsiz sistemlerde kullanımı yasadışıdır. Bu yazılımın kötüye kullanımından doğacak sorumluluk tamamen kullanıcıya aittir.



---



\## 🚀 Features \& Modes



Ghost-Audit features two distinct operational modes tailored for different engagement scenarios:



\### ⚡ 1. Stealth Mode (Fast)

Designed for speed and invisibility. It executes chained commands in a minimized window to grab essential data instantly.

\* \*\*Payload Name:\*\* `Stealth\_Mode\_PAYLOAD`

\* \*\*Execution Time:\*\* ~5-8 Seconds

\* \*\*Technique:\*\* Minimized CMD window (`cols=20`), optimized command chaining (`\&`).

\* \*\*Output:\*\* `%USERPROFILE%\\Desktop\\Logs`

\* \*\*Data:\*\* Basic IP/DNS, ARP Table, Wi-Fi Profiles, User Info.



\### 🔍 2. Detailed Mode (Forensic)

Designed for deep system analysis. It creates a structured log hierarchy and digs deep into the system internals using stable delays.

\* \*\*Payload Name:\*\* `Detailed\_Mode\_PAYLOAD`

\* \*\*Execution Time:\*\* ~30-40 Seconds

\* \*\*Technique:\*\* Stable execution flow, detailed queries, registry parsing.

\* \*\*Output:\*\* `%USERPROFILE%\\Desktop\\PC\_Audit\_Logs`

\* \*\*Data:\*\*

&nbsp;   \* 🖥️ \*\*System:\*\* CPU/RAM/Disk details, Installed Software (Registry), USB Connection History, Services, Processes.

&nbsp;   \* 🌐 \*\*Network:\*\* Full IP Config, DNS History, Route Table, Active Connections (Ports), Shares, Firewall State.

&nbsp;   \* 🔑 \*\*Wi-Fi:\*\* Exports \*\*ALL\*\* saved Wi-Fi profiles (SSID \& Passwords) to XML files.



---

