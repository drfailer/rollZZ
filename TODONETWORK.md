Exemple https://code.qt.io/cgit/qt/qtbase.git/tree/examples/network/network-chat/client.h?h=6.6

# PRINCIPE

* Peer to peer avec broadcast (chaque joueur/mj envoie les deltas à tout le monde)

Système de broacast: dans l'exemple il utilise un timer, pas besoin pour nous normalement ? 
(on envoie seulement si modification). ==> Dans ce cas QTimer

QHostAdress == Adress ipv4
QTCPServer == Server pour gérer socket TCP
QTCPSocket == Socket pour le TCP.
QCborStreamWriter/Reader == Conversion Binaire pour transmission donnée.
PEX to communicate between peer and create the network
