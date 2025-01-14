# nmap-wrapper-cpp
A simple C++ wrapper for executing and parsing Nmap scan results

Input: 
Enter the target IP or domain: 192.168.1.1
Enter Nmap options (e.g., -sS for SYN scan): -sS
Enter output file name (e.g., scan_results.txt): scan_results.txt

Output:

Running command: nmap -sS 192.168.1.1 -oN scan_results.txt

--- Nmap Scan Results ---

22/tcp   open  ssh
80/tcp   open  http
443/tcp  open  https
