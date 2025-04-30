# 📡 WiFi Beacon & Data Packet Analyzer

A low-level C-based network scanner designed to monitor and analyze **IEEE 802.11 wireless traffic**, with a special focus on:

- 📶 **Access Point Discovery** via beacon frame parsing
- 🔍 **Station Tracking** through analysis of data packets

---
## ✨ Features

- 🛰️ **Beacon Frame Analysis**  
    Identify all nearby Access Points (APs), extract essential metadata including:    
    - SSID (Network Name)
    - BSSID (MAC Address)
    - Signal strength (RSSI)
    - Channel and frequency

- 📊 **Data Frame Parsing**  
    Analyze traffic to determine which stations (clients) are connected to which APs using MAC correlation.
    
- ⚡ **Real-time Monitoring**  
    Continuously scan and output traffic details for live wireless monitoring.
    
- 🧱 **Raw Packet Capture**  
    Utilizes  `libpcap` for low-level packet sniffing and filtering.
    

---
## 📦 Dependencies

- `libpcap` – Packet capture library (install via `sudo pacman -Sy libpcap` on Arch-based systems)
- Root privileges for interface monitoring mode
- Linux-based system with a Wi-Fi interface supporting monitor mode

---

## 🚀 Output sample

The tool print a json ouput that provides the following information:

```
#{
# 	"name":	"Access Points",
# 	"ap":	{
# 		"essid":	"LE-24442346",
# 		"bssid":	"92:4g:6:52:89:a5",
# 		"info":	{
# 			"channel":	7,
# 			"signal":	-55,
# 			"stations":	{
# 			}
# 		}
# 	},
# 
#   ...
# 
#   {}
#}
```

## 🛠️ Work in progress

The struct used for parsing the packet content need to be checked in order to overcome a couple of assuntion in the packet structure itself.
The project will be translated in python and will be enriched with additional features, so it can be considered outdated.

🔒 Legal Disclaimer

This tool is intended for educational and security research purposes only. Use it only on networks you own or have explicit permission to analyze.
