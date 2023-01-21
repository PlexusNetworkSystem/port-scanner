# :eight_spoked_asterisk: Port scanner :eight_spoked_asterisk:
# :question: What is this script :question:
This script is a port scanner written in C++ that utilizes the ncurses library to provide a user-friendly interface. It allows the user to input a target IP address and a range of ports to scan. The script then attempts to connect to each port within the specified range and reports back whether the port is open or closed.

# :warning: Warning :warning:
This script is intended for educational and ethical testing purposes only. Any unauthorized use or misuse of this script is strictly prohibited and may be in violation of local, state, and/or federal laws. By using this script, you assume all risk and liability associated with its use. It is your responsibility to ensure that you have the legal right and authorization to use this script on any target systems. Use of this script without proper consent and authorization may result in unauthorized access, data breaches, and/or severe legal consequences. The developers of this script will not be held liable for any damages or harm caused by its use. Always seek permission and conduct ethical testing to ensure the safety and security of all parties involved.

# :cyclone: How does it work :question:
The script first initializes the ncurses library for displaying the user interface. The user is prompted to enter a target IP address and a range of ports to scan. The script then uses the Boost C++ library to perform asynchronous IO operations to connect to each port in the specified range. The script then checks the status of each port and reports back whether it is open or closed.

# :cyclone: What do we need to run it :question:
To run this script, you will need a C++ compiler (such as GCC), the ncurses library, and the Boost C++ library.

# :arrow_double_down: Install the dependencies :arrow_double_down:
On Ubuntu and Debian based systems, you can install the dependencies by running the following commands in the terminal:

    sudo apt-get install libncurses5-dev
    sudo apt-get install libboost-all-dev

# :pager: How can i run it :question:
You will be prompted to enter the target IP address and port range to scan. Once you have entered this information, the script will begin scanning the ports and display the results on the screen.
Once you have all the dependencies installed, you can compile the script by running the following command in the terminal:
    
    g++ -o port_scanner.run port_scanner.cpp -lncurses -lpthread
    
Then you can run the compiled binary by typing:
    
    chmod +x port_scanner.run
    ./port_scanner.run <target_ip_address>
    
# :satellite: Contacts :satellite:
Discord: `Abra#1568`<br />
Our discord server: [Click Me](https://discord.gg/R6fVaQS5We "Click Me")

# :computer: System Requirements :computer:
To run this script, you will need a system with a C++ compiler (such as g++) and the ncurses and pthread libraries installed. Additionally, you will need a Unix-based operating system, as the script uses POSIX threads and signal blocking functions.

# Created on this platform

<a href="https://linuxmint.com/" target="_blank"><img src="https://linuxmint.com/web/img/logo-mono.svg" alt="Patreon" height="174" width="310"></a></br>


# :credit_card: Donation :inbox_tray:

Loved :two_hearts: the project:question: You can :star2:support:star2: me and my team on this sites:point_down::point_down::point_down:

<a href="https://www.patreon.com/plexusnetworksystem" target="_blank"><img src="https://raw.githubusercontent.com/PlexusNetworkSystem/PlexusNetworkSystem/main/patreon.png" alt="Patreon" height="174" width="174"></a></br>
<a href="http://www.bynogame.com/tr/destekle/plexus-system" target="_blank"><img src="https://images.bynogame.com/images/anlatim/bynogame-logo-siyah2.png" alt="ByNoGame" height="123" width="300"></a>
------------ 
Developed by [Abra](https://github.com/Aegeansword "Abra")
